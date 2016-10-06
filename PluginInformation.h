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

#ifndef PLUGININFORMATION_H
#define PLUGININFORMATION_H

#include <QObject>
#include <functional>
#include <QIcon>
#include <QString>

class PluginInformation
{

public:
    PluginInformation(
            const QString &id = QString()
            , std::function<QString ()> func = nullptr
            , const QIcon &icon = QIcon())
        : m_id(id)
        , m_func(func)
        , m_icon(icon){}

    PluginInformation(const PluginInformation &rhs){
        m_id = rhs.m_id;
        m_func = rhs.m_func;
        m_icon = rhs.m_icon;
    }
    PluginInformation &operator=(const PluginInformation &rhs){
        if(this != &rhs){
            m_id = rhs.m_id;
            m_func = rhs.m_func;
            m_icon = rhs.m_icon;
        }

        return *this;
    }

#ifdef Q_COMPILER_RVALUE_REFS
    PluginInformation(PluginInformation &&rhs){
        m_id = std::move(rhs.m_id);
        m_func = std::move(rhs.m_func);
        m_icon = std::move(rhs.m_icon);
    }
    PluginInformation &operator=(PluginInformation && rhs){
        if(this != &rhs){
            m_id = std::move(rhs.m_id);
            m_func = std::move(rhs.m_func);
            m_icon = std::move(rhs.m_icon);
        }

        return *this;
    }
#endif

    QString id() const { return m_id; }
    QString title() const { return m_func ? m_func() : ""; }
    QIcon icon() const { return m_icon; }

private:
    QString m_id;
    std::function<QString ()> m_func;
    QIcon m_icon;
};

Q_DECLARE_METATYPE(PluginInformation)
static int PluginInformationRegisteration =
        qRegisterMetaType<PluginInformation>("PluginInformation");

#endif // PLUGININFORMATION_H

