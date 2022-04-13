TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        AnimatedSprite.cpp \
        Buildings.cpp \
        Button.cpp \
        Hearts.cpp \
        Platforms.cpp \
        Sky.cpp \
        World.cpp \
        aBullet.cpp \
        aMonster.cpp \
        main.cpp

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"

CONFIG(debug, debug|release){

    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d

} else {

    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    AnimatedSprite.h \
    Buildings.h \
    Button.h \
    Hearts.h \
    Platforms.h \
    Sky.h \
    World.h \
    aBullet.h \
    aMonster.h \
    included.h
