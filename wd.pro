TEMPLATE = subdirs

SUBDIRS = base webdriver extension_qt_base extension_qt_quick

base.subdir = src/base
webdriver.subdir = src/webdriver
extension_qt_base.file = src/webdriver/extension_qt/extension_qt_base.pro
extension_qt_quick.file = src/webdriver/extension_qt/extension_qt_quick.pro
