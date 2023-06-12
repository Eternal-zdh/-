QT       += core gui
QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#让程序获取管理员权限
CONFIG(release, debug|release){
QMAKE_LFLAGS += /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\"
}

SOURCES += \
    calculator_method.cpp \
    history_method.cpp \
    history_widget.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    calculator_method.h \
    history_method.h \
    history_widget.h \
    widget.h

FORMS += \
    history_widget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
