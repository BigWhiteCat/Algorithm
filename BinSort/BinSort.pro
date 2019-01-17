TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += ../Exception/libException.so

SOURCES += \
    binSort.cpp \
    main.cpp

HEADERS += \
    StudentRecord.h \
    Declaration.h
