#include "qgoogleauth.h"
#include <QtEndian>
#include <QDateTime>
#include "base32.h"
#include "hmac.h"

QGoogleAuth::QGoogleAuth()
{
}

QString QGoogleAuth::generatePin(const QByteArray key)
{
    quint64 time = QDateTime::currentDateTime().toTime_t();
    quint64 current = qToBigEndian(time / 30);

    int secretLen = (key.length() + 7) / 8 * 5;
    quint8 secret[100];
    int res = Base32::base32_decode(reinterpret_cast<const quint8 *>(key.constData()), secret, secretLen);
    QByteArray hmac = HMAC::hmacSha1(QByteArray(reinterpret_cast<const char *>(secret), res), QByteArray((char*)&current, sizeof(current)));

    int offset = (hmac[hmac.length() - 1] & 0xf);
    int binary =
            ((hmac[offset] & 0x7f) << 24)
            | ((hmac[offset + 1] & 0xff) << 16)
            | ((hmac[offset + 2] & 0xff) << 8)
            | (hmac[offset + 3] & 0xff);

    int password = binary % 1000000;
    return QString("%1").arg(password, 6, 10, QChar('0'));
}
