QT += core gui widgets

TEMPLATE = lib
TARGET = DlgDemo

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS USE_QT

SOURCES += \
    demodialog.cpp \
    main.cpp

HEADERS += \
    demodialog.h

INCLUDEPATH += $$PWD/.
INCLUDEPATH += $$PWD/../../../inc
INCLUDEPATH += $$PWD/../../../../inc

DEPENDPATH += $$PWD/.

#
GC_CONF_NAME = ""

win32: {
    TARGET_EXT = .grx
    CONFIG(debug, debug|release): {
        GC_CONF_NAME = "x64Debug"
    }
    else:{
        GC_CONF_NAME = "x64Release"
    }

    #输出目录
    DESTDIR = $$PWD/../make/out/$${GC_CONF_NAME}

    #配置lib目录
    LIB_DIR = $$PWD/../make/lib/$${GC_CONF_NAME}/

    LIBS += -L$${LIB_DIR}
    LIBS += -lgcbase
    LIBS += -lgcdb
    LIBS += -lgccore
    LIBS += -lgcadui
}
else:unix:!macx:{
    CONFIG += plugin no_plugin_name_prefix
    QMAKE_EXTENSION_PLUGIN = grx

    GC_CONF_NAME = "distribute"

    DESTDIR = $$PWD/../make/out/v2023/$${GC_CONF_NAME}/linux/amd64

    #配置lib目录
    LIB_DIR = $$PWD/../make/lib/v2023/$${GC_CONF_NAME}/linux/amd64/

    LIBS += -L$${LIB_DIR}
    LIBS += -lgcbase
    LIBS += -lgcdb
    LIBS += -lgccore
    LIBS += -lgcadui
}

