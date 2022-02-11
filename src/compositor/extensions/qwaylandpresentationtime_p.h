/****************************************************************************
**
** Copyright (C) 2021 LG Electronics Inc.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtWaylandCompositor module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QWAYLANDPRESENTATIONTIME_P_H
#define QWAYLANDPRESENTATIONTIME_P_H

#include <QObject>
#include <QtWaylandCompositor/qwaylandcompositorextension.h>

QT_BEGIN_NAMESPACE

class QQuickWindow;
class QWaylandPresentationTimePrivate;

class Q_WAYLANDCOMPOSITOR_EXPORT QWaylandPresentationTime : public QWaylandCompositorExtensionTemplate<QWaylandPresentationTime>
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QWaylandPresentationTime)
public:
    QWaylandPresentationTime();
    QWaylandPresentationTime(QWaylandCompositor *compositor);

    QWaylandCompositor *compositor() const;
    void initialize() override;

    Q_INVOKABLE void sendFeedback(QQuickWindow *window, quint64 sequence, quint64 tv_sec, quint32 tv_nsec);

    static const struct wl_interface *interface();
    static QByteArray interfaceName();

signals:
    void presented(quint64 sequence, quint64 tv_sec, quint32 tv_nsec, quint32 refresh_nsec);
};

QT_END_NAMESPACE

#endif
