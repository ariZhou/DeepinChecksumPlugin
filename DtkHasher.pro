QT += core gui dtkwidget

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console
TARGET = dtkHash
TEMPLATE = app

SOURCES += \
        main.cpp \
    BaseHasher.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    Types.h \
    Ihasher.h \
    BaseHasher.h
