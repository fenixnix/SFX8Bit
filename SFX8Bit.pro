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
    dialogmusicinstrumenttest.cpp \
    formkeyboard.cpp \
    main.cpp \
    mainwindow.cpp \
    Chiptune/nmuse.cpp \
    Chiptune/Sfx8Bit.cpp \
    Chiptune/wavcontour.cpp \
    Chiptune/wavenvelope.cpp \
    Chiptune/wavfilter.cpp \
    Device/qaudioplayer.cpp \
    Device/qmusicinstrument.cpp \
    Device/nchiptune.cpp \
    Chiptune/nwavwriter.cpp \
    Chiptune/wavbase.cpp



HEADERS += \
    dialogmusicinstrumenttest.h \
    formkeyboard.h \
    mainwindow.h \
    Chiptune/nmuse.h \
    Chiptune/Sfx8Bit.h \
    Chiptune/wavcontour.h \
    Chiptune/wavenvelope.h \
    Chiptune/wavfilter.h \
    Device/qaudioplayer.h \
    Device/qmusicinstrument.h \
    Device/nchiptune.h \
    Chiptune/nwavwriter.h \
    Chiptune/wavbase.h



FORMS += \
    dialogmusicinstrumenttest.ui \
    formkeyboard.ui \
    mainwindow.ui


DISTFILES +=

RESOURCES += \
    resource.qrc
