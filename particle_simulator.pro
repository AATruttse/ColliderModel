TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CCollider.cpp \
    CObject.cpp \
    CMovableObject.cpp \
    CParticle.cpp \
    CParticleFactory.cpp

HEADERS += \
    CCollider.h \
    CObject.h \
    CMovableObject.h \
    CParticle.h \
    CParticleFactory.h
