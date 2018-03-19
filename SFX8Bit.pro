#-------------------------------------------------
#
# Project created by QtCreator 2018-02-07T11:56:52
#
#-------------------------------------------------

QT       += core gui multimedia xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SFX8Bit
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    nsfx.cpp \
    wavenvelope.cpp \
    wavfilter.cpp \
    Sfx8Bit.cpp \
    soundbuffer.cpp \
    qaudioplayer.cpp \
    nchiptune.cpp \
    qmusicinstrument.cpp \
    formkeyboard.cpp \
    wavcontour.cpp \
    dialogmusicinstrumenttest.cpp \
    musicplayer.cpp \
    nmuse.cpp

HEADERS += \
        mainwindow.h \
    nsfx.h \
    wavenvelope.h \
    wavfilter.h \
    Sfx8Bit.h \
    soundbuffer.h \
    qaudioplayer.h \
    nchiptune.h \
    qmusicinstrument.h \
    formkeyboard.h \
    wavcontour.h \
    dialogmusicinstrumenttest.h \
    musicplayer.h \
    nmuse.h

FORMS += \
        mainwindow.ui \
    formkeyboard.ui \
    dialogmusicinstrumenttest.ui

DISTFILES +=

RESOURCES += \
    resource.qrc
