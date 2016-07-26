#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T22:18:33
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Neuro-Endo-Trainer
TEMPLATE = app


SOURCES += main.cpp\
        qmainwindow.cpp \
    settings_main.cpp \
    settings.cpp \
    testBasler.cpp \
    testIDS.cpp \
    testUSB.cpp \
    qtopencvviewergl.cpp \
    buf_aux.cpp \
    buf_endo.cpp \
    usbcamrecorddisp.cpp \
    auxCamRecord.cpp \
    params.cpp \
    serialcomm.cpp

HEADERS  += qmainwindow.h \
    settings_main.h \
    settings.h \
    testBasler.h \
    testIDS.h \
    testUSB.h \
    qtopencvviewergl.h \
    buf_aux.h \
    buf_endo.h \
    usbcamrecorddisp.h \
    auxCamRecord.h \
    params.h \
    serialcomm.h

FORMS    += qmainwindow.ui \
    settings_main.ui \
    settings.ui


RESOURCES += \
    resources.qrc

QMAKE_CXXFLAGS += -O2


QMAKE_CFLAGS -= -Wno-unused-parameter

INCLUDEPATH += /opt/pylon3/include
INCLUDEPATH += /opt/pylon3/genicam/library/CPP/include
INCLUDEPATH += /usr/local/include

LIBS += -L/usr/lib
LIBS += -L/usr/local/lib
LIBS += -L/opt/pylon3/lib64
LIBS += -L/opt/pylon3/genicam/bin/Linux64_x64
LIBS += -L/opt/pylon3/genicam/bin/Linux64_x64/GenApi/Generic

LIBS += -lpylonbase
LIBS += -lGenApi_gcc40_v2_3
LIBS += -lGCBase_gcc40_v2_3
LIBS += -lLog_gcc40_v2_3
LIBS += -lMathParser_gcc40_v2_3
LIBS += -lXerces-C_gcc40_v2_7
LIBS += -llog4cpp_gcc40_v2_3
LIBS += -lpthread
LIBS += -lv4l2
LIBS += -lX11
LIBS += -lueye_api



LIBS += -lopencv_calib3d
LIBS += -lopencv_contrib
LIBS += -lopencv_core
LIBS += -lopencv_features2d
LIBS += -lopencv_flann
LIBS += -lopencv_highgui
LIBS += -lopencv_imgproc
LIBS += -lopencv_legacy
LIBS += -lopencv_ml
LIBS += -lopencv_nonfree
LIBS += -lopencv_objdetect
LIBS += -lopencv_ocl
LIBS += -lopencv_photo
LIBS += -lopencv_stitching
LIBS += -lopencv_superres
LIBS += -lopencv_ts
LIBS += -lopencv_video
LIBS += -lopencv_videostab
LIBS += -lrt
LIBS += -lm
LIBS += -ldl

DISTFILES +=
