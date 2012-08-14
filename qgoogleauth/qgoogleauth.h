#ifndef QGOOGLEAUTH_H
#define QGOOGLEAUTH_H

#include "qgoogleauth_global.h"

class QGOOGLEAUTHSHARED_EXPORT QGoogleAuth {
public:
    QGoogleAuth();
    static QString generatePin(const QByteArray key);
};

#endif // QGOOGLEAUTH_H
