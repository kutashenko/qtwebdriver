BUILD_DIR = ../../..
include($$BUILD_DIR/common.pri)

TARGET = WebDriver_extension_qt_base
TEMPLATE = lib
CONFIG += staticlib qt

include(extension_qt_base-src.pri)
