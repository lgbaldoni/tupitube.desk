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

/*
#include <stdio.h>
#include <string.h>
#include "zlib.h"
*/

#include <QCameraInfo>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>

int main()
{
    // QByteArray cameraDevice = QCamera::availableDevices()[0];

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    // foreach (const QCameraInfo &cameraInfo, cameras)
    //     qDebug() << cameraInfo.deviceName();

    if (cameras.length() > 0) {
        QCamera *camera = new QCamera(cameras.at(0));
        QCameraViewfinder *viewFinder = new QCameraViewfinder();
        camera->setViewfinder(viewFinder);

        camera->setCaptureMode(QCamera::CaptureStillImage);
        new QCameraImageCapture(camera);

        if (camera->state() == QCamera::ActiveState)
            camera->stop();
 
        camera->start();
    }
}
