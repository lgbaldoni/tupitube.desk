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

#ifndef TUPCOLORPICKER_H
#define TUPCOLORPICKER_H

#include "tglobal.h"

#include <QFrame>
#include <QPoint>
#include <QColor>
#include <QImage>
#include <QSizePolicy>
#include <QPixmap>
#include <QSize>
#include <QRect>
#include <QPainter>
#include <QMouseEvent>

class TUPITUBE_EXPORT TupColorPicker : public QFrame
{
    Q_OBJECT

    public:
        TupColorPicker(QWidget* parent);
        ~TupColorPicker();
        int getHue();
        int getSaturation();
        void clearSelection();

    public slots:
        void setColor(int getHue, int getSaturation);
        void setHUE(int getHue);
        void setSaturation(int getSaturation);

    signals:
        void newColor(int getHue, int getSaturation);

    protected:
        QSize sizeHint() const;
        void paintEvent(QPaintEvent*);
        void mouseMoveEvent(QMouseEvent *);
        void mousePressEvent(QMouseEvent *);

    private:
        QPoint colorPoint();
        int huePoint(const QPoint &pt);
        int saturationPoint(const QPoint &pt);
        void setColor(const QPoint &pt);

        int hue;
        int saturation;
        QPixmap *pix;
        int pWidth;
        int pHeight;
        bool target;
};

#endif
