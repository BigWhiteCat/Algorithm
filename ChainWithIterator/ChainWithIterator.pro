TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += ../Exception/libException.so

SOURCES += main.cpp

HEADERS += \
    ChainWithIterator.hpp \
    ChainNode.hpp

target.path = ../bin
target.uninstall = @echo "uninstall"
INSTALLS += target