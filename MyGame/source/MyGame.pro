QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11



SOURCES += \
    hagame.cpp \
    main.cpp \
    menu.cpp \
    object.cpp \
    questionlist.cpp \
    score.cpp

HEADERS += \
    hagame.h \
    menu.h \
    object.h \
    questionlist.h \
    score.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc
