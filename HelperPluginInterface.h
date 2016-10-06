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

#ifndef HELPERPLUGININTERFACE
#define HELPERPLUGININTERFACE

#include "GeneralPluginInterface.h"

#include <QVariantList>
#include <QMap>
#include <functional>

#define REGISTER_FUNCTION(x) HelperPluginInterface::registerFunction(#x, [&](const QVariantList &vars) -> QVariant{ return x(vars); })

class HelperPluginInterface : public GeneralPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(GeneralPluginInterface)

public:
    explicit HelperPluginInterface(QWidget* parent = 0)
        : GeneralPluginInterface(parent)
    {

    }

    virtual ~HelperPluginInterface(void) {}

    inline QVariant callFunction(const QString &name, const QVariant &var){
        return callFunction(name, QVariantList() << var);
    }

    inline QVariant callFunction(const QString &name, const QVariantList &vars = QVariantList()){
        if(m_funcMap.contains(name)) return m_funcMap[name](vars);
        return QVariant();
    }

    inline bool hasFunction(const QString &name){
        return m_funcMap.contains(name);
    }

protected:
    inline void registerFunction(const QString &name, std::function<QVariant(const QVariantList &)> func){
        m_funcMap[name] = func;
    }

private:
    QMap<QString, std::function<QVariant(const QVariantList &)>> m_funcMap;
};

Q_DECLARE_INTERFACE(HelperPluginInterface, "com.kristou.HelperPluginInterface")

#endif // HELPERPLUGININTERFACE

