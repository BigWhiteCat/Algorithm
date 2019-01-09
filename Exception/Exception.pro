TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Exception.cpp

HEADERS += \
    Exception.h

target.path = ../lib
target.uninstall = @echo "uninstall"
INSTALLS += target
