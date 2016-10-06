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

#ifndef VIEWERINTERFACE_H
#define VIEWERINTERFACE_H

#include <QWidget>
#include <QString>
#include <QIcon>
#include <QCheckBox>
#include <QSettings>

#include "GeneralPluginInterface.h"
#include "PluginDataStructure.h"

class ViewerPluginInterface: public GeneralPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(GeneralPluginInterface)

public:
    explicit ViewerPluginInterface(QWidget *parent = 0)
        : GeneralPluginInterface(parent)
    , m_active(new QCheckBox(this))
    {
        m_active->setChecked(true);
    }
    virtual ~ViewerPluginInterface() {}


    QCheckBox *getActiveWidget() { return m_active; }
    inline bool isActive(){ return m_active->isChecked();}

signals:
    void selectedStepChanged(int step);

public slots:
    virtual void addMeasurementData(const QString &id
                                    , const PluginDataStructure &data) = 0;
    virtual void setSelectedStep(int step) = 0;
    virtual void refresh() = 0;
    virtual void clear() = 0;
    inline void setActive(bool state){ m_active->setChecked(state); }

private:
    QCheckBox *m_active;

};

Q_DECLARE_INTERFACE(ViewerPluginInterface, "com.kristou.ViewerPluginInterface")

#endif // VIEWERINTERFACE_H

