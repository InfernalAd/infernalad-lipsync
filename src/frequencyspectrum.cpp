/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include "frequencyspectrum.h"

FrequencySpectrum::FrequencySpectrum(int numPoints)
    :   m_elements(numPoints)

{
    _phoneme = '~';
    //qDebug() << "freqSpecCons" << numPoints <<m_elements.size();
}

void FrequencySpectrum::reset()
{
    iterator i = begin();
    for ( ; i != end(); ++i)
        *i = Element();
}

int FrequencySpectrum::count() const
{
    return m_elements.count();
}

FrequencySpectrum::Element& FrequencySpectrum::operator[](int index)
{
    return m_elements[index];
}

const FrequencySpectrum::Element& FrequencySpectrum::operator[](int index) const
{
    return m_elements[index];
}

const FrequencySpectrum::Element &FrequencySpectrum::value(int index) const
{
    return m_elements[index];
}

FrequencySpectrum::iterator FrequencySpectrum::begin()
{
    return m_elements.begin();
}

FrequencySpectrum::iterator FrequencySpectrum::end()
{
    return m_elements.end();
}

FrequencySpectrum::const_iterator FrequencySpectrum::begin() const
{
    return m_elements.begin();
}

FrequencySpectrum::const_iterator FrequencySpectrum::end() const
{
    return m_elements.end();
}

void FrequencySpectrum::setPhoneme(char ch)
{
    _phoneme = ch;
}

char FrequencySpectrum::phoneme()
{
    return _phoneme;
}

float FrequencySpectrum::compareWith(FrequencySpectrum &spectrum)
{
    double res=0;

    int miniWidth = spectrum.count()/32;
    double miniThis[32];
    double miniSpectrum[32];
    for (int i=0;i!=32;i++)
    {
        double value=0;
        for (int j=i*miniWidth;j!=((i+1)*miniWidth-1);j++)
        {
            value = qMax(value,this->value(j).amplitude);
        }
        miniThis[i]=value;
    }

    for (int i=0;i!=32;i++)
    {
        double value=0;
        for (int j=i*miniWidth;j!=((i+1)*miniWidth-1);j++)
        {
            value = qMax(value,spectrum.value(j).amplitude);
        }
        miniSpectrum[i]=value;
    }


    /*
    for (int i=0;i!=16;i++)
    {
        res += miniThis[i]-miniSpectrum[i];
    }
    */

    float sampleMathExpect = 0;
    for (int i = 0; i < 32; ++i)
    {
        sampleMathExpect += miniThis[i];
    }

    sampleMathExpect = 1 / 32 * sampleMathExpect;

    float spectMathExpect = 0;
    for (int i = 0; i < 32; ++i)
    {
        spectMathExpect += miniSpectrum[i];
    }

    spectMathExpect = 1 / 32 * spectMathExpect;

    float dividend = 0, divider1 = 0, divider2 = 0;

    for (int i = 0; i < 32; ++i)
    {
        dividend += (miniThis[i] - sampleMathExpect) * (miniSpectrum[i] - spectMathExpect);
    }

    for (int i = 0; i < 32; ++i)
    {
        divider1 += pow((miniThis[i] - sampleMathExpect), 2);
    }

    for (int i = 0; i < 32; ++i)
    {
        divider2 += pow((miniSpectrum[i] - spectMathExpect), 2);
    }

    res = 1 - fabs(dividend / (sqrt(divider1) * sqrt(divider2)));

    return fabs(res);




}

