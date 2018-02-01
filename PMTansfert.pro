#-------------------------------------------------
#
# Project created by QtCreator 2017-11-18T17:37:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network

TARGET = PMTansfert
TEMPLATE = app


SOURCES += main.cpp\
    PMSettingsWidget.cpp \
    PMSettingsAccess.cpp \
    PMSettings.cpp \
    PMSettingsController.cpp \
    PMInitController.cpp \
    PMTransferController.cpp \
    PMUser.cpp \
    PMUserAccess.cpp \
    PMSigninWidget.cpp \
    blSlidingStackedWidget.cpp \
    PMMenuWidget.cpp \
    PMSigninModel.cpp \
    PMTransferWidget.cpp \
    PMTransferModel.cpp \
    PMExplorerWidget.cpp \
    PMBookingListWidget.cpp \
    PMBookingListModel.cpp \
    PMBookingModel.cpp \
    PMBookingWidget.cpp \
    PMUploadWidget.cpp \
    PMCopyModel.cpp

HEADERS  += \
    PMSettingsWidget.h \
    PMSingleton.h \
    PMSettingsAccess.h \
    PMSettings.h \
    PMSettingsController.h \
    PMInitController.h \
    PMTransferController.h \
    PMUser.h \
    PMUserAccess.h \
    PMSigninWidget.h \
    blSlidingStackedWidget.h \
    PMMenuWidget.h \
    PMSigninModel.h \
    PMTransferWidget.h \
    PMTransferModel.h \
    PMExplorerWidget.h \
    PMBookingListWidget.h \
    PMBookingListModel.h \
    PMBookingModel.h \
    PMBookingWidget.h \
    PMUploadWidget.h \
    PMCopyModel.h
