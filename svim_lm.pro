TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    interfaz.cpp \
    sistema.cpp \
    imagen.cpp \
    pixel.cpp \
    archivador.cpp \
    arhivadormif.cpp

HEADERS += \
    interfaz.h \
    sistema.h \
    imagen.h \
    pixel.h \
    archivador.h \
    arhivadormif.h

DISTFILES += \
    requerimientos.md \
    README.md
