TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Exception.cpp \
    Object.cpp \
    Smartpointer.cpp \
    main.cpp

HEADERS += \
    Exception.h \
    Object.h \
    Smartpointer.h \
    List.h \
    StaticList.h \
    SeqList.h \
    DynamicList.h \
    Array.h \
    StaticArray.h \
    DynamicArray.h
