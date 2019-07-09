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

#include "tupfilemanager.h"
#include "tupproject.h"
#include "tupscene.h"
#include "tuplibrary.h"
#include "tuppackagehandler.h"
#include "talgorithm.h"

#include <QDir>

TupFileManager::TupFileManager() : QObject()
{
}

TupFileManager::~TupFileManager()
{
}

bool TupFileManager::save(const QString &fileName, TupProject *project)
{
    #ifdef TUP_DEBUG
        qWarning() << "TupFileManager::save() - Saving file -> " << fileName;
    #endif

    QFileInfo info(fileName);
    QString name = info.baseName();	
    QString oldDirName = CACHE_DIR + project->getName();
    QDir projectDir(oldDirName);
    bool ok;

    // Project name has been changed by the user
    if (name.compare(project->getName()) != 0) {
        project->setProjectName(name);
        projectDir.setPath(CACHE_DIR + name);    
        project->getLibrary()->updatePaths(CACHE_DIR + name);
        if (!projectDir.exists()) {
            // Update the cache path with new project's name
            if (projectDir.rename(oldDirName, projectDir.path())) {
                #ifdef TUP_DEBUG
                    qDebug() << "TupFileManager::save() - Directory renamed to -> " << projectDir.path();
                #endif
            } else {
                // If rename action fails, then try to create new project's path
                if (!projectDir.mkdir(projectDir.path())) {
                    #ifdef TUP_DEBUG
                        qWarning() << "TupFileManager::save() - Error: Can't create path -> " << projectDir.path();
                    #endif
                    return false;
                } else {
                    #ifdef TUP_DEBUG
                        qDebug() << "TupFileManager::save() - Directory was created successfully -> " << projectDir.path();
                    #endif
                }
            }
        }
    } else {
        // If project's path doesn't exist, create it
        if (!projectDir.exists()) {
            if (!projectDir.mkdir(projectDir.path())) {
                #ifdef TUP_DEBUG
                    qWarning() << "TupFileManager::save() - Error: Can't create path -> " << projectDir.path();
                #endif
                return false;
            } else {
                #ifdef TUP_DEBUG
                    qDebug() << "TupFileManager::save() - Directory was created successfully -> " << projectDir.path();
                #endif
            }
        }
    }

    {
     #ifdef TUP_DEBUG
         qDebug() << "TupFileManager::save() - source files path -> " << projectDir.path();
     #endif

     // Save project
     QFile projectFile(projectDir.path() + "/project.tpp");

     if (projectFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
         #ifdef TUP_DEBUG
             qDebug() << "TupFileManager::save() - Saving config file (TPP)";
         #endif
         QTextStream ts(&projectFile);
         QDomDocument doc;
         project->setProjectName(name);
         doc.appendChild(project->toXml(doc));
         ts << doc.toString();
         projectFile.close();
     } else {
         #ifdef TUP_DEBUG
             qWarning() << "TupFileManager::save() - Error: Can't create file -> " << projectDir.path() << "/project.tpp";
         #endif
         return false;
     }
    }

    // Save scenes
    {
     int totalScenes = project->getScenes().size();
     int index = 0;
     QDomDocument doc;
     QString scenePath;

     for (int i=0; i<totalScenes; i++) {
          #ifdef TUP_DEBUG
              qDebug() << "TupFileManager::save() - Saving scene file " << QString::number(i);
          #endif
          doc.appendChild(project->getScenes().at(i)->toXml(doc));
          scenePath = projectDir.path() + "/scene" + QString::number(index) + ".tps";
          QFile sceneFile(scenePath);
          if (sceneFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
              QTextStream st(&sceneFile);
              st << doc.toString();
              index += 1;
              doc.clear();
              sceneFile.close();
          } else {
              #ifdef TUP_DEBUG
                  qWarning() << "TupFileManager::save() - Error: Can't create file -> " << scenePath;
              #endif
              return false;
          }
     }
    }

    {
     // Save library
     QFile library(projectDir.path() + "/library.tpl");

     if (library.open(QIODevice::WriteOnly | QIODevice::Text)) {
         #ifdef TUP_DEBUG
             QString msg = "TupFileManager::save() - Saving library file (TPL)";
             qDebug() << msg;
         #endif
         QTextStream ts(&library);
         QDomDocument doc;
         doc.appendChild(project->getLibrary()->toXml(doc));

         ts << doc.toString();
         library.close();
     } else {
         #ifdef TUP_DEBUG
             QString msg = "TupFileManager::save() - Error: Can't create file -> " + projectDir.path() + "/library.tpl";
             qWarning() << msg;
         #endif
         return false;
     }
    }

    {
        #ifdef TUP_DEBUG
            QString msg = "TupFileManager::save() - Creating TUP file...";
            qDebug() << msg;
        #endif
        TupPackageHandler packageHandler;
        ok = packageHandler.makePackage(projectDir.path(), fileName);

        if (ok) {
            #ifdef TUP_DEBUG
                QString msg = "TupFileManager::save() - Project saved at -> " + fileName;
                #ifdef Q_OS_WIN
                    qWarning() << msg;
                #else
                    tWarning() << msg;
                #endif
            #endif
        } else {
            #ifdef TUP_DEBUG
                QString msg = "TupFileManager::save() - Error: Project couldn't be saved at -> " + fileName;
                #ifdef Q_OS_WIN
                    qDebug() << msg;
                #else
                    tError() << msg;
                #endif
            #endif
            return false;
        }
    }

    return ok;
}

bool TupFileManager::load(const QString &fileName, TupProject *project)
{
    #ifdef TUP_DEBUG
        #ifdef Q_OS_WIN
            qDebug() << "[TupFileManager::load()] - fileName: " + fileName;
        #else
            T_FUNCINFO << "filename: " << fileName;
        #endif
    #endif

    TupPackageHandler packageHandler;
    if (packageHandler.importPackage(fileName)) {
        QDir projectDir(packageHandler.importedProjectPath());
        QFile pfile(projectDir.path() + "/project.tpp");

        if (pfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            project->fromXml(QString::fromLocal8Bit(pfile.readAll()));
            pfile.close();
        } else {
            #ifdef TUP_DEBUG
                QString msg1 = "TupFileManager::load() - Error while open .tpp file. Name: " + pfile.fileName();
                QString msg2 = "TupFileManager::load() - Path: " + projectDir.path();
                QString msg3 = "TupFileManager::load() - Error Description: " + pfile.errorString(); 
                qWarning() << msg1;
                qWarning() << msg2;
                qWarning() << msg3;
            #endif
            return false;
        }

        project->setDataDir(packageHandler.importedProjectPath());
        project->loadLibrary(projectDir.path() + "/library.tpl");

        QStringList scenes = projectDir.entryList(QStringList() << "*.tps", QDir::Readable | QDir::Files);
        QFile *file;
        QDomDocument doc;
        QString xml;
        QDomElement root;

        if (scenes.count() > 0) {
            int index = 0;
            foreach (QString scenePath, scenes) {
                scenePath = projectDir.path() + "/" + scenePath;
                file = new QFile(scenePath);
					 
                if (file->open(QIODevice::ReadOnly | QIODevice::Text)) {
                    xml = QString::fromLocal8Bit(file->readAll());
                    if (!doc.setContent(xml))
                        return false;

                    root = doc.documentElement();
                    project->createScene(root.attribute("name"), index, true)->fromXml(xml);
                    index += 1;
                    doc.clear();
                    file->close();
                    delete file;
                } else {
                    #ifdef TUP_DEBUG
                        qWarning() << "TupFileManager::load() - Error: Can't open file -> " << scenePath;
                    #endif
                    return false;
                }
            }
            project->setOpen(true);
            return true;
        } else {
            #ifdef TUP_DEBUG
                QString msg = "TupFileManager::load() - Error: No scene files found (*.tps)";
                #ifdef Q_OS_WIN
                    qDebug() << msg;
                #else
                    tError() << msg;
                #endif
            #endif
            return false;
        }
    }

    #ifdef TUP_DEBUG
        QString msg = "TupFileManager::load() - Error: Can't import package -> " + fileName;
        #ifdef Q_OS_WIN
            qDebug() << msg;
        #else
            tError() << msg;
        #endif
    #endif
    return false;
}
