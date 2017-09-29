QT += core widgets
QT -= gui

TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

SOURCES += main.cpp \
    interfaz.cpp \
    sistema.cpp \
    imagen.cpp \
    pixel.cpp \
    archivador.cpp \
    arhivadormif.cpp \
#    metadatos.cpp \
    graficador.cpp

HEADERS += \
    interfaz.h \
    sistema.h \
    imagen.h \
    pixel.h \
    archivador.h \
    arhivadormif.h \
#    metadatos.h \
    defines.h \
    graficador.h

DISTFILES += \
    requerimientos.md \
    README.md
