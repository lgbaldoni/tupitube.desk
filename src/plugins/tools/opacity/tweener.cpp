/***************************************************************************
 *   Project TUPITUBE DESK                                                *
 *   Project Contact: info@maefloresta.com                                 *
 *   Project Website: http://www.maefloresta.com                           *
 *   Project Leader: Gustav Gonzalez <info@maefloresta.com>                *
 *                                                                         *
 *   Developers:                                                           *
 *   2010:                                                                 *
 *    Gustavo Gonzalez / xtingray                                          *
 *                                                                         *
 *   KTooN's versions:                                                     * 
 *                                                                         *
 *   2006:                                                                 *
 *    David Cuadrado                                                       *
 *    Jorge Cuadrado                                                       *
 *   2003:                                                                 *
 *    Fernado Roldan                                                       *
 *    Simena Dinas                                                         *
 *                                                                         *
 *   Copyright (C) 2010 Gustav Gonzalez - http://www.maefloresta.com       *
 *   License:                                                              *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#include "tweener.h"
#include "configurator.h"
#include "taction.h"
#include "tosd.h"
#include "tupinputdeviceinformation.h"
#include "tupbrushmanager.h"
#include "tupgraphicsscene.h"
#include "tupgraphicobject.h"
#include "tupsvgitem.h"
#include "tupitemtweener.h"
#include "tuprequestbuilder.h"
#include "tupprojectrequest.h"
#include "tuplibraryobject.h"
#include "tupscene.h"
#include "tuplayer.h"

#include <QMessageBox>

struct Tweener::Private
{
    QMap<QString, TAction *> actions;
    Configurator *configurator;

    TupGraphicsScene *scene;
    QList<QGraphicsItem *> objects;

    TupItemTweener *currentTween;
    int initFrame;
    int initLayer;
    int initScene;

    TupToolPlugin::Mode mode;
    TupToolPlugin::EditMode editMode;
};

Tweener::Tweener() : TupToolPlugin(), k(new Private)
{
    setupActions();

    k->configurator = nullptr;
    k->initFrame = 0;
}

Tweener::~Tweener()
{
    delete k;
}

/* This method initializes the plugin */

void Tweener::init(TupGraphicsScene *scene)
{
    k->scene = scene;
    k->objects.clear();

    k->mode = TupToolPlugin::View;
    k->editMode = TupToolPlugin::None;
    k->initFrame = k->scene->currentFrameIndex();
    k->initLayer = k->scene->currentLayerIndex();
    k->initScene = k->scene->currentSceneIndex();

    k->configurator->resetUI();

    QList<QString> tweenList = k->scene->currentScene()->getTweenNames(TupItemTweener::Opacity);
    if (tweenList.size() > 0) {
        k->configurator->loadTweenList(tweenList);
        setCurrentTween(tweenList.at(0));
    } else {
        k->configurator->activeButtonsPanel(false);
    }

    int total = framesCount();
    k->configurator->initStartCombo(total, k->initFrame);
}

void Tweener::updateStartPoint(int index)
{
     if (k->initFrame != index && index >= 0)
         k->initFrame = index;
}

/* This method returns the plugin name */

QStringList Tweener::keys() const
{
    return QStringList() << tr("Opacity Tween");
}

/* This method makes an action when the mouse is pressed on the workspace 
 * depending on the active mode: Selecting an object or Creating a path  
*/

void Tweener::press(const TupInputDeviceInformation *input, TupBrushManager *brushManager, TupGraphicsScene *scene)
{
    #ifdef TUP_DEBUG
        #ifdef Q_OS_WIN
            qDebug() << "[Tweener::press()]";
        #else
            T_FUNCINFO;
        #endif
    #endif

    Q_UNUSED(input);
    Q_UNUSED(brushManager);
    Q_UNUSED(scene);
}

/* This method is executed while the mouse is pressed and on movement */

void Tweener::move(const TupInputDeviceInformation *input, TupBrushManager *brushManager, TupGraphicsScene *scene)
{
    Q_UNUSED(input);
    Q_UNUSED(brushManager);
    Q_UNUSED(scene);
}

/* This method finishes the action started on the press method depending
 * on the active mode: Selecting an object or Creating a path
*/

void Tweener::release(const TupInputDeviceInformation *input, TupBrushManager *brushManager, TupGraphicsScene *scene)
{
    #ifdef TUP_DEBUG
        #ifdef Q_OS_WIN
            qDebug() << "[Tweener::release()]";
        #else
            T_FUNCINFO;
        #endif
    #endif

    Q_UNUSED(input);
    Q_UNUSED(brushManager);

    if (scene->currentFrameIndex() == k->initFrame) {
        if (k->editMode == TupToolPlugin::Selection) {
            #ifdef TUP_DEBUG
                QString msg = "Opacity Tweener::release() - Tracing selection mode";
                #ifdef Q_OS_WIN
                    qDebug() << msg;
                #else
                    tError() << msg;
                #endif
            #endif

            if (scene->selectedItems().size() > 0) {
                #ifdef TUP_DEBUG
                    QString msg = "Opacity Tweener::release() - selection size -> " + QString::number(scene->selectedItems().size());
                    #ifdef Q_OS_WIN
                        qDebug() << msg;
                    #else
                        tError() << msg;
                    #endif
                #endif
                k->objects = scene->selectedItems();
                foreach (QGraphicsItem *item, k->objects) {
                    QString tip = item->toolTip();
                    if (tip.contains(tr("Opacity"))) {
                        QDesktopWidget desktop;
                        QMessageBox msgBox;
                        msgBox.setWindowTitle(tr("Warning"));
                        msgBox.setIcon(QMessageBox::Warning);
                        msgBox.setText(tr("The selected items already have this kind of tween assigned."));
                        msgBox.setInformativeText(tr("Please, edit the previous tween of these objects."));
                        msgBox.addButton(QString(tr("Accept")), QMessageBox::AcceptRole);
                        msgBox.show();
                        msgBox.move(static_cast<int>((desktop.screenGeometry().width() - msgBox.width())/2),
                                    static_cast<int>((desktop.screenGeometry().height() - msgBox.height())/2));
                        msgBox.exec();

                        k->objects.clear();
                        scene->clearSelection();
                        return;
                    }
                }
                #ifdef TUP_DEBUG
                    QString msg1 = "Opacity Tweener::release() - Notifying selection...";
                    #ifdef Q_OS_WIN
                        qDebug() << msg1;
                    #else
                        tError() << msg1;
                    #endif
                #endif
                k->configurator->notifySelection(true);
            } else {
                #ifdef TUP_DEBUG
                    QString msg = "Opacity Tweener::release() - Selection mode: no items selected";
                    #ifdef Q_OS_WIN
                        qDebug() << msg;
                    #else
                        tError() << msg;
                    #endif
                #endif
            }
        }
    }
}

/* This method returns the list of actions defined in this plugin */

QMap<QString, TAction *> Tweener::actions() const
{
    return k->actions;
}

/* This method returns the list of actions defined in this plugin */

int Tweener::toolType() const
{
    return TupToolInterface::Tweener;
}

/* This method returns the tool panel associated to this plugin */

QWidget *Tweener::configurator()
{
    if (!k->configurator) {
        k->mode = TupToolPlugin::View;

        k->configurator = new Configurator;
        connect(k->configurator, SIGNAL(startingPointChanged(int)), this, SLOT(updateStartPoint(int)));
        connect(k->configurator, SIGNAL(clickedApplyTween()), this, SLOT(applyTween()));
        connect(k->configurator, SIGNAL(clickedSelect()), this, SLOT(setSelection()));
        connect(k->configurator, SIGNAL(clickedDefineProperties()), this, SLOT(setPropertiesMode()));
        connect(k->configurator, SIGNAL(clickedResetInterface()), this, SLOT(applyReset()));
        connect(k->configurator, SIGNAL(setMode(TupToolPlugin::Mode)), this, SLOT(updateMode(TupToolPlugin::Mode))); 
        connect(k->configurator, SIGNAL(getTweenData(const QString &)), this, SLOT(setCurrentTween(const QString &)));
        connect(k->configurator, SIGNAL(clickedRemoveTween(const QString &)), this, SLOT(removeTween(const QString &)));
    } 

    return k->configurator;
}

/* This method is called when there's a change on/of scene */
void Tweener::aboutToChangeScene(TupGraphicsScene *)
{
}

/* This method is called when this plugin is off */

void Tweener::aboutToChangeTool()
{
}

/* This method defines the actions contained in this plugin */

void Tweener::setupActions()
{
    TAction *action = new TAction(QPixmap(kAppProp->themeDir() + "icons/opacity_tween.png"), 
                                      tr("Opacity Tween"), this);
    action->setCursor(QCursor(kAppProp->themeDir() + "cursors/tweener.png",0 ,0));
    action->setShortcut(QKeySequence(tr("Shift+O")));

    k->actions.insert(tr("Opacity Tween"), action);
}

/* This method saves the settings of this plugin */

void Tweener::saveConfig()
{
}

/* This method updates the workspace when the plugin changes the scene */

void Tweener::updateScene(TupGraphicsScene *scene)
{
    k->mode = k->configurator->mode();

    if (k->mode == TupToolPlugin::Edit) {
        int framesNumber = framesCount();

        if (k->configurator->startComboSize() < framesNumber)
            k->configurator->initStartCombo(framesNumber, k->initFrame);
    } else if (k->mode == TupToolPlugin::Add) {
               int total = framesCount();

               if (k->editMode == TupToolPlugin::Properties) {
                   if (total > k->configurator->startComboSize()) {
                       k->configurator->activateMode(TupToolPlugin::Selection);
                       clearSelection();
                       setSelection();
                   }
               } else if (k->editMode == TupToolPlugin::Selection) {
                          if (scene->currentFrameIndex() != k->initFrame)
                              clearSelection();
                          k->initFrame = scene->currentFrameIndex();
                          setSelection();
               }

               if (k->configurator->startComboSize() < total) {
                   k->configurator->initStartCombo(total, k->initFrame);
               } else {
                   if (scene->currentFrameIndex() != k->initFrame)
                       k->configurator->setStartFrame(scene->currentFrameIndex());
               }

    } else {
        if (scene->currentFrameIndex() != k->initFrame)
            k->configurator->setStartFrame(scene->currentFrameIndex());
    }
}

void Tweener::setCurrentTween(const QString &name)
{
    TupScene *scene = k->scene->currentScene();
    k->currentTween = scene->tween(name, TupItemTweener::Opacity);
    if (k->currentTween)
        k->configurator->setCurrentTween(k->currentTween);
}

int Tweener::framesCount()
{
    int total = 1;
    TupLayer *layer = k->scene->currentScene()->layerAt(k->scene->currentLayerIndex());
    if (layer)
        total = layer->framesCount();

    return total;
}

/* This method clears selection */

void Tweener::clearSelection()
{
    if (k->objects.size() > 0) {
        foreach (QGraphicsItem *item, k->objects) {
            if (item->isSelected())
                item->setSelected(false);
        }
        k->objects.clear();
        k->configurator->notifySelection(false);
    }
}

/* This method disables object selection */

void Tweener::disableSelection()
{
    foreach (QGraphicsView *view, k->scene->views()) {
         view->setDragMode (QGraphicsView::NoDrag);
         foreach (QGraphicsItem *item, view->scene()->items()) {
             item->setFlag(QGraphicsItem::ItemIsSelectable, false);
             item->setFlag(QGraphicsItem::ItemIsMovable, false);
         }
    }
}

void Tweener::setSelection()
{
    k->editMode = TupToolPlugin::Selection;

    /*
    int bottomBoundary = (2*ZLAYER_LIMIT) + (k->initLayer*ZLAYER_LIMIT);
    int topBoundary = bottomBoundary + ZLAYER_LIMIT;
    foreach (QGraphicsView *view, k->scene->views()) {
             view->setDragMode(QGraphicsView::RubberBandDrag);
             foreach (QGraphicsItem *item, view->scene()->items()) {
                      if ((item->zValue() >= bottomBoundary) && (item->zValue() < topBoundary) && (item->toolTip().length()==0))
                          item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
             }
    }
    */

    k->scene->enableItemsForSelection();
    foreach (QGraphicsView *view, k->scene->views())
        view->setDragMode(QGraphicsView::RubberBandDrag);
    // When Object selection is enabled, previous selection is set
    if (k->objects.size() > 0) {
        foreach (QGraphicsItem *item, k->objects) {
            item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
            item->setSelected(true);
        }
        k->configurator->notifySelection(true);
    }
}

void Tweener::setPropertiesMode()
{
    k->editMode = TupToolPlugin::Properties;
    disableSelection();
}

/* This method resets this plugin */

void Tweener::applyReset()
{
    disableSelection();
    clearSelection();

    k->mode = TupToolPlugin::View;
    k->editMode = TupToolPlugin::None;

    k->initFrame = k->scene->currentFrameIndex();
    k->initLayer = k->scene->currentLayerIndex();
    k->initScene = k->scene->currentSceneIndex();
}

/* This method applies to the project, the Tween created from this plugin */

void Tweener::applyTween()
{
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

    QString name = k->configurator->currentTweenName();
    if (name.length() == 0) {
        TOsd::self()->display(tr("Error"), tr("Tween name is missing!"), TOsd::Error);
        return;
    }

    // Tween is new
    if (!k->scene->currentScene()->tweenExists(name, TupItemTweener::Opacity)) {
        k->initFrame = k->scene->currentFrameIndex();
        k->initLayer = k->scene->currentLayerIndex();
        k->initScene = k->scene->currentSceneIndex();

        foreach (QGraphicsItem *item, k->objects) {
                 TupLibraryObject::Type type = TupLibraryObject::Item;
                 int objectIndex = -1;

                 if (TupSvgItem *svg = qgraphicsitem_cast<TupSvgItem *>(item)) {
                     type = TupLibraryObject::Svg;
                     objectIndex = k->scene->currentFrame()->indexOf(svg);
                 } else {
                     objectIndex = k->scene->currentFrame()->indexOf(item);
                 }

                 TupProjectRequest request = TupRequestBuilder::createItemRequest(
                                             k->initScene, k->initLayer, k->initFrame,
                                             objectIndex, QPointF(), k->scene->getSpaceContext(), 
                                             type, TupProjectRequest::SetTween,
                                             k->configurator->tweenToXml(k->initScene, k->initLayer, k->initFrame));
                 emit requested(&request);
        }
    } else { // Tween already exists
        removeTweenFromProject(name);
        QList<QGraphicsItem *> newList;

        k->initFrame = k->configurator->startFrame();
        k->initLayer = k->currentTween->getInitLayer();
        k->initScene = k->scene->currentSceneIndex();

        foreach (QGraphicsItem *item, k->objects) {
                 TupLibraryObject::Type type = TupLibraryObject::Item;

                 // TupProject *project = k->scene->scene()->project();
                 // TupScene *scene = project->scene(k->initScene);

                 TupScene *scene = k->scene->currentScene();
                 TupLayer *layer = scene->layerAt(k->initLayer);
                 TupFrame *frame = layer->frameAt(k->currentTween->getInitFrame());
                 int objectIndex = -1;
                 TupSvgItem *svg = qgraphicsitem_cast<TupSvgItem *>(item);

                 if (svg) {
                     type = TupLibraryObject::Svg;
                     objectIndex = frame->indexOf(svg);
                 } else {
                     objectIndex = frame->indexOf(item);
                 }

                 if (k->initFrame != k->currentTween->getInitFrame()) {
                     QDomDocument dom;
                     if (type == TupLibraryObject::Svg)
                         dom.appendChild(svg->toXml(dom));
                     else
                         dom.appendChild(dynamic_cast<TupAbstractSerializable *>(item)->toXml(dom));

                     TupProjectRequest request = TupRequestBuilder::createItemRequest(k->initScene, k->initLayer, k->initFrame,
                                                                                      0, item->pos(), k->scene->getSpaceContext(),
                                                                                      type, TupProjectRequest::Add,
                                                                                      dom.toString());
                     emit requested(&request);

                     request = TupRequestBuilder::createItemRequest(k->scene->currentSceneIndex(),
                                                                   k->scene->currentLayerIndex(),
                                                                   k->currentTween->getInitFrame(),
                                                                   objectIndex, QPointF(),    
                                                                   k->scene->getSpaceContext(), type,
                                                                   TupProjectRequest::Remove);
                     emit requested(&request);

                     frame = layer->frameAt(k->initFrame);
                     if (type == TupLibraryObject::Item) {
                         objectIndex = frame->graphicsCount() - 1;
                         newList.append(frame->graphicAt(objectIndex)->item());
                     } else {
                         objectIndex = frame->svgItemsCount() - 1;
                         newList.append(frame->svgAt(objectIndex));
                     }
                 }

                 TupProjectRequest request = TupRequestBuilder::createItemRequest(
                                             k->initScene, k->initLayer, k->initFrame,
                                             objectIndex, QPointF(), k->scene->getSpaceContext(), 
                                             type, TupProjectRequest::SetTween, 
                                             k->configurator->tweenToXml(k->initScene, k->initLayer, k->initFrame));
                 emit requested(&request);
        }

        if (newList.size() > 0)
            k->objects = newList;
    }

    int total = k->initFrame + k->configurator->totalSteps();
    int framesNumber = framesCount();
    int layersCount = k->scene->currentScene()->layersCount();
    TupProjectRequest request;

    if (total >= framesNumber) {
        for (int i = framesNumber; i < total; i++) {
             for (int j = 0; j < layersCount; j++) {
                  request = TupRequestBuilder::createFrameRequest(k->initScene, j, i,
                                               TupProjectRequest::Add, tr("Frame"));
                  emit requested(&request);
             }
        }
    }

    QString selection = QString::number(k->initLayer) + "," + QString::number(k->initLayer) + ","
                        + QString::number(k->initFrame) + "," + QString::number(k->initFrame);

    request = TupRequestBuilder::createFrameRequest(k->initScene, k->initLayer, k->initFrame,
                                                    TupProjectRequest::Select, selection);
    emit requested(&request);

    setCurrentTween(name);
    TOsd::self()->display(tr("Info"), tr("Tween %1 applied!").arg(name), TOsd::Info);

    QApplication::restoreOverrideCursor();
}

void Tweener::removeTweenFromProject(const QString &name)
{
    TupScene *scene = k->scene->currentScene();
    bool removed = scene->removeTween(name, TupItemTweener::Opacity);

    if (removed) {
        foreach (QGraphicsView * view, k->scene->views()) {
            foreach (QGraphicsItem *item, view->scene()->items()) {
                QString tip = item->toolTip();
                if (tip.compare("Tweens: " + tr("Opacity")) == 0) {
                    item->setToolTip("");
                    item->setRotation(0);
                } else {
                    if (tip.contains(tr("Opacity"))) {
                        tip = tip.replace(tr("Opacity") + ",", "");
                        tip = tip.replace(tr("Opacity"), "");
                        if (tip.endsWith(","))
                            tip.chop(1);
                        item->setToolTip(tip);
                        item->setRotation(0);
                    }
                }
            }
        }
        emit tweenRemoved();
    } else {
        #ifdef TUP_DEBUG
            QString msg = "Tweener::removeTweenFromProject() - Opacity tween couldn't be removed -> " + name;
            #ifdef Q_OS_WIN
                qDebug() << msg;
            #else
                tError() << msg;
            #endif
        #endif
    }
}

void Tweener::removeTween(const QString &name)
{
    removeTweenFromProject(name);
    applyReset();
}

void Tweener::updateMode(TupToolPlugin::Mode mode)
{
    k->mode = mode;

    if (k->mode == TupToolPlugin::Edit) {
        if (k->currentTween) {
            k->initScene = k->currentTween->getInitScene();
            k->initLayer = k->currentTween->getInitLayer();
            k->initFrame = k->currentTween->getInitFrame();

            if (k->initFrame != k->scene->currentFrameIndex() || k->initLayer != k->scene->currentLayerIndex()) {
                QString selection = QString::number(k->initLayer) + "," + QString::number(k->initLayer) + ","
                                    + QString::number(k->initFrame) + "," + QString::number(k->initFrame);

                TupProjectRequest request = TupRequestBuilder::createFrameRequest(k->initScene, k->initLayer, k->initFrame, 
                                                                                  TupProjectRequest::Select, selection);
                emit requested(&request);
            }

            if (k->objects.isEmpty())
                k->objects = k->scene->currentScene()->getItemsFromTween(k->currentTween->getTweenName(), TupItemTweener::Opacity);
        } else {
            #ifdef TUP_DEBUG
                QString msg = "Tweener::updateMode() - Current tween pointer is NULL!";
                #ifdef Q_OS_WIN
                    qDebug() << msg;
                #else
                    tError() << msg;
                #endif
            #endif
        }
    }
}

void Tweener::sceneResponse(const TupSceneResponse *event)
{
    if ((event->getAction() == TupProjectRequest::Remove || event->getAction() == TupProjectRequest::Reset)
        && (k->scene->currentSceneIndex() == event->getSceneIndex())) {
        init(k->scene);
    }

    if (event->getAction() == TupProjectRequest::Select)
        init(k->scene);
}

void Tweener::layerResponse(const TupLayerResponse *event)
{
    if (event->getAction() == TupProjectRequest::Remove)
        init(k->scene);
}

void Tweener::frameResponse(const TupFrameResponse *event)
{
    if (event->getAction() == TupProjectRequest::Remove && k->scene->currentLayerIndex() == event->getLayerIndex())
        init(k->scene);

    if (event->getAction() == TupProjectRequest::Select) {
        if (k->initLayer != event->getLayerIndex() || k->initScene != event->getSceneIndex())
            init(k->scene);
    }
}
