#-------------------------------------------------
#
# Project created by QtCreator 2012-08-10T10:08:07
#
#-------------------------------------------------

QT       -= gui

TARGET = qgoogleauth
TEMPLATE = lib

DEFINES += QGOOGLEAUTH_LIBRARY

SOURCES += qgoogleauth.cpp \
    base32.cpp \
    hmac.cpp

HEADERS += qgoogleauth.h\
        qgoogleauth_global.h \
    base32.h \
    hmac.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE6830BBF
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = qgoogleauth.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
