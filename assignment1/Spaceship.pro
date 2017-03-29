#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T13:23:41
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spaceship
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
    battlesphere.cpp \
    spaceship.cpp \
    config.cpp \
    spaceitem.cpp \
    spaceitemfactory.cpp \
    laser.cpp

HEADERS  += \
    battlesphere.h \
    spaceship.h \
    config.h \
    spaceitem.h \
    spaceitemfactory.h \
    laser.h

RESOURCES += \
    resources.qrc

OTHER_FILES +=
