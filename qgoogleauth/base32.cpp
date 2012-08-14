#include "base32.h"

Base32::Base32(QObject *parent) :
    QObject(parent)
{
}

int Base32::base32_decode(const quint8 *encoded, quint8 *result, int bufSize)
{
    int buffer = 0;
    int bitsLeft = 0;
    int count = 0;

    for (const quint8 *ptr = encoded; count < bufSize && *ptr; ++ptr) {
        quint8 ch = *ptr;

        if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '-') {
            continue;
        }

        buffer <<= 5;

        // Deal with commonly mistyped characters
        if (ch == '0') {
            ch = 'O';
        } else if (ch == '1') {
            ch = 'L';
        } else if (ch == '8') {
            ch = 'B';
        }

        // Look up one base32 digit
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            ch = (ch & 0x1F) - 1;
        } else if (ch >= '2' && ch <= '7') {
            ch -= '2' - 26;
        } else {
            return -1;
        }

        buffer |= ch;
        bitsLeft += 5;

        if (bitsLeft >= 8) {
            result[count++] = buffer >> (bitsLeft - 8);
            bitsLeft -= 8;
        }
    }

    if (count < bufSize) {
        result[count] = '\000';
    }

    return count;
}
