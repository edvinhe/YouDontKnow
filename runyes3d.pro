TEMPLATE = app

QT += core gui

QT += qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    handletextfield.cpp \
    mainwindow.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    handletextfield.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
