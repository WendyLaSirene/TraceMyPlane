QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accueil.cpp \
    head_interact_airport.cpp \
    head_interract_fly.cpp \
    main.cpp \
    mainwindow.cpp \
    widg_airports.cpp \
    widg_entete.cpp \
    widg_vols.cpp

HEADERS += \
    accueil.h \
    head_interact_airport.h \
    head_interract_fly.h \
    mainwindow.h \
    widg_airports.h \
    widg_entete.h \
    Classe_Aeroport.h\
    Classe_Moment.h\
    Classe_Position.h\
    Classe_Utilisateur.h\
    Classe_Vol.h\
    Fonctions_Diverses.h\
    widg_vols.h

FORMS += \
    accueil.ui \
    head_interact_airport.ui \
    head_interract_fly.ui \
    mainwindow.ui \
    widg_airports.ui \
    widg_entete.ui \
    widg_vols.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc

DISTFILES +=
