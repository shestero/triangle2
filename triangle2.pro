TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    point.cpp \
    segment.cpp \
    triangle.cpp

HEADERS += \
    geomath.h \
    point.h \
    segment.h \
    triangle.h
