// Copyright (C) 2022 David Edmundson <davidedmundson@kde.org>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qwaylandfractionalscale_p.h"

QT_BEGIN_NAMESPACE

namespace QtWaylandClient {

QWaylandFractionalScale::QWaylandFractionalScale(struct ::wp_fractional_scale_v1 *object)
    : QtWayland::wp_fractional_scale_v1(object)
{}


QWaylandFractionalScale::~QWaylandFractionalScale()
{
    destroy();
}

qreal QWaylandFractionalScale::preferredScale() const
{
    return mPreferredScale;
}

void QWaylandFractionalScale::wp_fractional_scale_v1_preferred_scale(wl_fixed_t scale)
{
    mPreferredScale = wl_fixed_to_double(scale);
    Q_EMIT preferredScaleChanged();
}

}

QT_END_NAMESPACE