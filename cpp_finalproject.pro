#-------------------------------------------------
#
# Project created by QtCreator 2018-04-24T19:14:15
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cpp_finalproject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
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
    workout.cpp \
    cardio.cpp \
    person.cpp \
    log.cpp \
    dashboard_old.cpp \
    dashboard.cpp \
    userprofile_old.cpp \
    userprofile.cpp \
    profile.cpp \
    food.cpp \
    weight_training.cpp

HEADERS += \
        mainwindow.h \
    workout.h \
    cardio.h \
    weight_training.h \
    food.h \
    person.h \
    log.h \
    dashboard_old.h \
    dashboard.h \
    userprofile_old.h \
    userprofile.h \
    profile.h

FORMS += \
        mainwindow.ui \
    userprofile.ui \
    log.ui \
    dashboard_old.ui \
    dashboard.ui \
    userprofile.ui \
    profile.ui

DISTFILES +=
