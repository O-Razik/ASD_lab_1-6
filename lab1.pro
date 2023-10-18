QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    func_app.cpp \
    func_sort.cpp \
    main.cpp \
    mainwindow.cpp \
    var_eleven.cpp \
    var_fourteen.cpp \
    var_ten.cpp \
    var_thirteen.cpp \
    var_twelve.cpp

HEADERS += \
    func_app.h \
    func_sort.h \
    mainwindow.h \
    var_eleven.h \
    var_fourteen.h \
    var_ten.h \
    var_thirteen.h \
    var_twelve.h

FORMS += \
    mainwindow.ui \
    var_eleven.ui \
    var_fourteen.ui \
    var_ten.ui \
    var_thirteen.ui \
    var_twelve.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
