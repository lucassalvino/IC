QT += core
QT -= gui

CONFIG += c++11

TARGET = IC
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    TeoriaFluxo/variaveisdemanda.cpp \
<<<<<<< HEAD
    TeoriaFluxo/variaveisoferta.cpp
=======
    TeoriaFluxo/variaveisservico.cpp
>>>>>>> eb4a60f4a759c2b1b8b57216c412a599c2da0785

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    TeoriaFluxo/variaveisdemanda.h \
<<<<<<< HEAD
    TeoriaFluxo/variaveisoferta.h
=======
    TeoriaFluxo/variaveisservico.h
>>>>>>> eb4a60f4a759c2b1b8b57216c412a599c2da0785
