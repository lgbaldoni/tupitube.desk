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

#ifndef TUPVIDEOPROPERTIES_H
#define TUPVIDEOPROPERTIES_H

#include "tglobal.h"
#include "tupexportwizard.h"

#include <QLineEdit>
#include <QTextEdit>
#include <QProgressBar>

#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QNetworkReply>

class TUPITUBE_EXPORT TupVideoProperties : public TupExportWizardPage
{
    Q_OBJECT

    public:
        TupVideoProperties();
        ~TupVideoProperties();

        bool isComplete() const;
        void reset();
        QString title() const;
        QString topics() const;
        QString description() const;
        QList<int> scenesList() const;
        bool successful();
        void setProjectParams(const QString &login, const QString &passwd, const QString &path);

    signals:
        void postHasStarted();
        void isDone();

    private slots:
        void resetTitleColor(const QString &text);
        void resetTopicsColor(const QString &text);
        void postIt();
        void setScenesIndexes(const QList<int> &indexes);
        void serverAuthAnswer(QNetworkReply *reply);
        void closeRequest(QNetworkReply *reply);
        void slotError(QNetworkReply::NetworkError error);
        void tracingPostProgress(qint64 bytesSent, qint64 bytesTotal);

    private:
        void setForm();
        void setProgressBar();

        QVBoxLayout *layout;
        QLineEdit *titleEdit;
        QLineEdit *topicsEdit;
        QTextEdit *descText;
        QList<int> scenes;
        bool isOk;

        QString username;
        QString token;
        QString filePath;
        QWidget *formWidget;
        QWidget *progressWidget;
        QStackedWidget *stackedWidget;

        QNetworkAccessManager *manager;
        QNetworkRequest request;
        QUrlQuery params;
        QNetworkReply *reply;
};

#endif
