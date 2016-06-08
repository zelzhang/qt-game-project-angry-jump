#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T15:49:24
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
DESTDIR   = $$PWD

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 102022111_final_project_angry_jump
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    easymusic.cpp \
    floor.cpp \
    number.cpp \
    obstacle.cpp \
    role.cpp \
    score.cpp \
    start.cpp \
    angry.cpp \
    icon.cpp \
    jump.cpp \
    thank_you.cpp

HEADERS  += mainwindow.h \
    easymusic.h \
    floor.h \
    number.h \
    obstacle.h \
    role.h \
    score.h \
    start.h \
    angry.h \
    icon.h \
    jump.h \
    thank_you.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

DISTFILES +=
