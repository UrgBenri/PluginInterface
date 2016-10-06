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

#ifndef CONNECTORWIDGET_H
#define CONNECTORWIDGET_H

#include <QWidget>
#include <QVector>
#include <QMetaType>
#include <QIcon>
#include <QAction>
#include <QEvent>
#include <QSettings>

#include "GeneralPluginInterface.h"

class ConnectorPluginInterface : public GeneralPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(GeneralPluginInterface)

public:
    explicit ConnectorPluginInterface(QWidget* parent = 0)
        : GeneralPluginInterface(parent)
    {

    }

    virtual ~ConnectorPluginInterface(void) {}

    /*!
    * \brief Query the connected state of the plugin.
    * This method is usually called by the connector manager to query the connected state of the plugin.
    * If the plugin is connected, interactions are forwarded to the plugin.
    *
    * Return \c true if connected, else return \c false.
    *
    * \return \b bool: \c true if connected.
    */
    virtual bool isConnected() = 0;
    virtual bool isStarted() = 0;
    virtual bool isPaused() = 0;

    virtual bool loadFile(const QString &filename){
        Q_UNUSED(filename);
        return false;
    }

signals:
    void connexionLost();
    void connexionReady();
    void fileOpened(const QString &filename);

    void started();
    void stopped();
    void paused();

    void measurementDataReady(const PluginDataStructure &data);

public slots:
    virtual void start() {}
    virtual void stop() {}
    virtual void pause() {}
};

Q_DECLARE_INTERFACE(ConnectorPluginInterface, "com.kristou.ConnectorPluginInterface")

#endif // CONNECTORWIDGET_H

