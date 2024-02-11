QT += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    s21_graphWindow.cc \
    s21_creditWindow.cc \
    s21_main.cc \
    s21_mainWindow.cc \
    qcustomplot.cc \
    ../Model/s21_modelSmartCalc.cc 

HEADERS += \
    s21_graphWindow.h \
    s21_creditWindow.h \
    s21_mainWindow.h \
    ../Controller/s21_controllerSmartCalc.h \
    qcustomplot.h

FORMS += \
    graphWindow.ui \
    creditwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
