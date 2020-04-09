TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Exception.cpp \
    Object.cpp \
    Smartpointer.cpp

HEADERS += \
    Exception.h \
    Object.h \
    Smartpointer.h \
    List.h \
    Seqlist.h
