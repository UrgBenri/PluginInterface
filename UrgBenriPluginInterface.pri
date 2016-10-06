!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    QT       += core gui widgets

    DEPENDPATH += $$PWD
    INCLUDEPATH += $$PWD

    QMAKE_LFLAGS_SONAME = -Wl,-install_name,@rpath/plugins/

    HEADERS += \
        $$PWD/GeneralPluginInterface.h \
        $$PWD/ConnectorPluginInterface.h \
        $$PWD/PluginDataStructure.h \
        $$PWD/ViewerPluginInterface.h \
        $$PWD/FilterPluginInterface.h \
        $$PWD/ToolPluginInterface.h \
        $$PWD/PluginInformation.h \
        $$PWD/HelperPluginInterface.h \
        $$PWD/PluginVersion.h \
        $$PWD/PluginManagerInterface.h \
        $$PWD/PluginUtils.h \
        $$PWD/SystemPluginInterface.h
}
