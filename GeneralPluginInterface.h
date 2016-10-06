/*
	This file is part of the UrgBenri application.

	Copyright (c) 2016 Mehrez Kristou.
	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Please contact kristou@hokuyo-aut.jp for more details.

*/

#ifndef GENERALPUGININTERFACE
#define GENERALPUGININTERFACE

#include <QString>
#include <QIcon>
#include <QSettings>
#include <QWidget>

#include "PluginDataStructure.h"
#include "PluginVersion.h"
#include "PluginManagerInterface.h"

#define PLUGIN_FACTORY(PluginClass) \
    public: GeneralPluginInterface *createPlugin(QWidget* parent = 0) \
        {return new PluginClass(parent);} \
    public: QString pluginClassName() const \
        {return QString(#PluginClass);}

class GeneralPluginInterface : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralPluginInterface(QWidget *parent = 0): QWidget(parent) {}
    virtual ~GeneralPluginInterface(){}

    virtual QString pluginName() const = 0;
    virtual QString pluginDescription() const = 0;
    virtual PluginVersion pluginVersion() const = 0;
    virtual QIcon pluginIcon() const = 0;
    virtual QString pluginAuthorName() const = 0;
    virtual QString pluginAuthorContact() const = 0;
    virtual int pluginLoadOrder() const = 0;
    virtual QString pluginClassName() const = 0;
    virtual bool pluginIsExperimental() const = 0;
    virtual QString pluginLicense() const = 0;
    virtual QString pluginLicenseDescription() const = 0;

    virtual void loadTranslator(const QString &locale) = 0;

    virtual void saveState(QSettings &settings) = 0;
    virtual void restoreState(QSettings &settings) = 0;

    virtual GeneralPluginInterface *createPlugin(QWidget* parent = 0) = 0;

signals:
    void error(const QString &header, const QString &message);
    void warning(const QString &header, const QString &message);
    void information(const QString &header, const QString &message);

public slots:
    virtual void onLoad(PluginManagerInterface *manager) = 0;
    virtual void onUnload() = 0;

};

Q_DECLARE_INTERFACE(GeneralPluginInterface, "com.kristou.GeneralPluginInterface")

#endif // GENERALPUGININTERFACE

