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

#ifndef PLUGINVERSION_H
#define PLUGINVERSION_H

#include <QObject>
#include <QStringList>
#include <QString>

class PluginVersion
{

public:
    PluginVersion(
            int major = 0
            , int minor = 0
            , int patch = 0)
        : m_major(major)
        , m_minor(minor)
        , m_patch(patch){}

    inline int major() const { return m_major; }
    inline void setMajor(int major) { m_major = major; }

    inline int minor() const { return m_minor; }
    inline void setMinor(int minor) { m_minor = minor; }

    inline int patch() const { return m_patch; }
    inline void setPatch(int patch) { m_patch = patch; }

    inline QString toString() const {return QString("%1.%2.%3").arg(m_major).arg(m_minor).arg(m_patch);}
    inline qreal toReal() const {return (m_major * 100 * 100) + (m_minor * 100) + m_patch;}
    inline void parse(const QString &value){
        QStringList parts = value.split(".", QString::SkipEmptyParts);
        m_patch = 0; m_minor = 0; m_major = 0;
        switch (parts.size()) {
            case 3: m_patch = parts[2].toInt();
            case 2: m_minor = parts[1].toInt();
            case 1: m_major = parts[0].toInt();
        }
    }

private:
    int m_major;
    int m_minor;
    int m_patch;
};

inline bool operator< (const PluginVersion& lhs, const PluginVersion& rhs){return lhs.toReal() < rhs.toReal();}
inline bool operator> (const PluginVersion& lhs, const PluginVersion& rhs){return rhs < lhs;}
inline bool operator<=(const PluginVersion& lhs, const PluginVersion& rhs){return !(lhs > rhs);}
inline bool operator>=(const PluginVersion& lhs, const PluginVersion& rhs){return !(lhs < rhs);}

inline bool operator==(const PluginVersion& lhs, const PluginVersion& rhs){return lhs.toReal() == rhs.toReal();}
inline bool operator!=(const PluginVersion& lhs, const PluginVersion& rhs){return !(lhs == rhs);}

Q_DECLARE_METATYPE(PluginVersion)

#endif // PLUGINVERSION_H

