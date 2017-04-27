#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T13:23:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spaceship
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
    battlesphere.cpp \
    iofile.cpp \
    defender.cpp \
    commandcentre.cpp \
    bullet.cpp \
    battlespherebuilder.cpp \
    gamedirector.cpp \
    star.cpp

HEADERS  += \
    battlesphere.h \
    iofile.h \
    defender.h \
    commandcentre.h \
    bullet.h \
    battlespherebuilder.h \
    gamedirector.h \
    star.h \
    gameelement.h

RESOURCES += \
    resources.qrc

OTHER_FILES +=
