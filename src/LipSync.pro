#-------------------------------------------------
#
# Project created by QtCreator 2012-08-31T13:38:49
#
#-------------------------------------------------

QT       += core gui multimedia xml

DESTDIR = ../bin
MOC_DIR = ../tmp
OBJECTS_DIR = ../tmp

TARGET = LipSync
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    fftreal/fftreal_wrapper.cpp \
    fftreal/stopwatch/StopWatch.cpp \
    fftreal/stopwatch/ClockCycleCounter.cpp \
    wavfile.cpp \
    wavfile.cpp \
    waveform.cpp \
    utils.cpp \
    spectrumanalyser.cpp \
    spectrograph.cpp \
    settingsdialog.cpp \
    progressbar.cpp \
    mainwindow.cpp \
    mainwidget.cpp \
    main.cpp \
    levelmeter.cpp \
    frequencyspectrum.cpp \
    engine.cpp \
    lipwidget.cpp \
    spectrumtable.cpp \
    choosephonemedialog.cpp

HEADERS  += mainwindow.h \
    fftreal/TestWhiteNoiseGen.hpp \
    fftreal/TestWhiteNoiseGen.h \
    fftreal/TestSpeed.hpp \
    fftreal/TestSpeed.h \
    fftreal/TestHelperNormal.hpp \
    fftreal/TestHelperNormal.h \
    fftreal/TestHelperFixLen.hpp \
    fftreal/TestHelperFixLen.h \
    fftreal/TestAccuracy.hpp \
    fftreal/TestAccuracy.h \
    fftreal/test_settings.h \
    fftreal/test_fnc.hpp \
    fftreal/test_fnc.h \
    fftreal/OscSinCos.hpp \
    fftreal/OscSinCos.h \
    fftreal/FFTRealUseTrigo.hpp \
    fftreal/FFTRealUseTrigo.h \
    fftreal/FFTRealSelect.hpp \
    fftreal/FFTRealSelect.h \
    fftreal/FFTRealPassInverse.hpp \
    fftreal/FFTRealPassInverse.h \
    fftreal/FFTRealPassDirect.hpp \
    fftreal/FFTRealPassDirect.h \
    fftreal/FFTRealFixLenParam.h \
    fftreal/FFTRealFixLen.hpp \
    fftreal/FFTRealFixLen.h \
    fftreal/fftreal_wrapper.h \
    fftreal/FFTReal.hpp \
    fftreal/FFTReal.h \
    fftreal/DynArray.hpp \
    fftreal/DynArray.h \
    fftreal/def.h \
    fftreal/Array.hpp \
    fftreal/Array.h \
    fftreal/stopwatch/StopWatch.hpp \
    fftreal/stopwatch/StopWatch.h \
    fftreal/stopwatch/Int64.h \
    fftreal/stopwatch/fnc.hpp \
    fftreal/stopwatch/fnc.h \
    fftreal/stopwatch/def.h \
    fftreal/stopwatch/ClockCycleCounter.hpp \
    fftreal/stopwatch/ClockCycleCounter.h \
    wavfile.h \
    wavfile.h \
    waveform.h \
    utils.h \
    spectrumanalyser.h \
    spectrum.h \
    spectrograph.h \
    settingsdialog.h \
    progressbar.h \
    mainwindow.h \
    mainwidget.h \
    levelmeter.h \
    frequencyspectrum.h \
    engine.h \
    lipwidget.h \
    spectrumtable.h \
    choosephonemedialog.h

FORMS    += mainwindow.ui \
    lipwidget.ui \
    spectrumtable.ui \
    choosephonemedialog.ui

OTHER_FILES += \
    fftreal/testapp.dpr \
    fftreal/readme.txt \
    fftreal/license.txt \
    fftreal/fftreal.pro.user \
    fftreal/fftreal.pro \
    fftreal/fftreal.pas \
    fftreal/FFTReal.dsw \
    fftreal/FFTReal.dsp \
    fftreal/bwins/fftrealu.def \
    fftreal/eabi/fftrealu.def
