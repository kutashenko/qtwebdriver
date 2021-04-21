BUILD_DIR = ../..
include($$BUILD_DIR/common.pri)

TARGET = WebDriver_core
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += $$SRC_DIR/third_party/mongoose

include(webdriver-src.pri)
