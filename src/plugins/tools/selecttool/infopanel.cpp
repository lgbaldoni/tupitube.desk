/***************************************************************************
 *   Project TUPI: Magia 2D                                                *
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
 *   the Free Software Foundation; either version 3 of the License, or     *
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

#include "infopanel.h"
#include <QBoxLayout>
#include <QTextEdit>

#include "kimagebutton.h"
#include "kseparator.h"
#include "kglobal.h"
#include "kdebug.h"

InfoPanel::InfoPanel(QWidget *parent) :QWidget(parent)
{
    QBoxLayout *mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    QBoxLayout *buttonsLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    buttonsLayout->setMargin(0);
    buttonsLayout->setSpacing(0);

    KImageButton *horizontalFlip = new KImageButton(QPixmap(THEME_DIR + "icons/save.png"), 22);
    horizontalFlip->setToolTip(tr("Horizontal Flip"));
    KImageButton *verticalFlip = new KImageButton(QPixmap(THEME_DIR + "icons/save.png"), 22);
    verticalFlip->setToolTip(tr("Horizontal Flip"));
    KImageButton *crossedFlip = new KImageButton(QPixmap(THEME_DIR + "icons/save.png"), 22);
    crossedFlip->setToolTip(tr("Crossed Flip"));
    connect(horizontalFlip, SIGNAL(clicked()), this, SIGNAL(hFlip()));
    connect(verticalFlip, SIGNAL(clicked()), this, SIGNAL(vFlip()));
    connect(crossedFlip, SIGNAL(clicked()), this, SIGNAL(cFlip()));

    buttonsLayout->addWidget(horizontalFlip);
    buttonsLayout->addWidget(verticalFlip);
    buttonsLayout->addWidget(crossedFlip);

    mainLayout->addLayout(buttonsLayout);

    mainLayout->addWidget(new KSeparator(Qt::Horizontal));

    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom);
    QLabel *label = new QLabel(tr("Tips"));
    label->setAlignment(Qt::AlignHCenter); 
    layout->addWidget(label);

    mainLayout->addLayout(layout);

    QTextEdit *textArea = new QTextEdit; 

    // SQA: Check this code with several screen resolutions. It must looks good with everyone! 
    textArea->setFont(QFont("Arial", 8, QFont::Normal, false));
    textArea->setHtml("<p><b>" + tr("Rotation mode") + ":</b> " + tr("Double click on any node or shortcut Alt + R") + "</p>"); 
    textArea->append("<p><b>" + tr("Arrows") + ":</b> " +  tr("Movement on selection") + "</p>");
    textArea->append("<p><b>" + tr("Shift + Arrows") + ":</b> " +  tr("Slow movement on selection") + "</p>");
    textArea->append("<p><b>" + tr("Ctrl + Arrows") + ":</b> " +  tr("Fast movement on selection") + "</p>");
    textArea->append("<p><b>" + tr("Shift + Left Mouse Button") + ":</b> " +  tr("Proportional scaling on selection") + "</p>");

    QString text = textArea->document()->toPlainText();
    int height = (text.length()*270)/230;

    textArea->setFixedHeight(height);

    mainLayout->addWidget(textArea);
    mainLayout->addStretch(2);
}

InfoPanel::~InfoPanel()
{
}

