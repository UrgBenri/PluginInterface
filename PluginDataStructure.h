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

#ifndef PLUGINDATASTRUCTURE_H
#define PLUGINDATASTRUCTURE_H

#include <QObject>
#include <QSharedPointer>
#include <QVector3D>
#include <QVector>
#include <QPair>

typedef struct DataOffset{
    qreal range; // Unit: millimeter
    qreal phy, theta; // Unit: radian
    DataOffset(qreal l_range = 0
               , qreal l_phy = 0
               , qreal l_theta = 0)
        : range(l_range)
        , phy(l_phy)
        , theta(l_theta)
    {}
} DataOffset;

class DataConverterInterface
{
public:
    DataConverterInterface(){}
    virtual ~DataConverterInterface(){}

    virtual QVector3D range2point(int step
                                  , long range
                                  , DataOffset offset
                                  , long maxLength = -1) const = 0;
    virtual QVector<QVector<QVector3D> > getPoints(const QVector<QVector<long > > &steps
                                                   , DataOffset offset = DataOffset()
                                                   , int max_length = -1) const = 0;
    virtual int angle2index(qreal phy, qreal theta) const = 0;
    virtual int index2Step(int index) const = 0;
    virtual int step2Index(int step) const = 0;
    virtual QPair<qreal, qreal> index2angle(int index) const = 0;
};

typedef struct {
    QVector<QVector<long > > ranges;
    QVector<QVector<long > > levels;
    QSharedPointer<DataConverterInterface> converter;
    qint64 timestamp;
    QByteArray extra;
} PluginDataStructure;

Q_DECLARE_METATYPE(PluginDataStructure)

static int PluginDataStructureRegisteration =
        qRegisterMetaType<PluginDataStructure>("PluginDataStructure");

#endif /* !PLUGINDATASTRUCTURE_H */

