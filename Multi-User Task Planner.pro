QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addtaskui.cpp \
    main.cpp \
    mainwindow.cpp \
    signupform.cpp \
    task.cpp \
    tasklist.cpp \
    taskplanner.cpp \
    taskwidget.cpp \
    user.cpp \
    userdashboard.cpp

HEADERS += \
    addtaskui.h \
    mainwindow.h \
    signupform.h \
    task.h \
    tasklist.h \
    taskplanner.h \
    taskwidget.h \
    user.h \
    userdashboard.h

FORMS += \
    addtaskui.ui \
    mainwindow.ui \
    signupform.ui \
    taskwidget.ui \
    userdashboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
