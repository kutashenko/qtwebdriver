TEMPLATE = subdirs

SUBDIRS = base webdriver extension_qt_base extension_qt_quick

base.subdir = $$PWD/src/base
webdriver.subdir = $$PWD/src/webdriver
extension_qt_base.file = $$PWD/src/webdriver/extension_qt/extension_qt_base.pro
extension_qt_quick.file = $$PWD/src/webdriver/extension_qt/extension_qt_quick.pro
