//=============================================================================================================
/**
* @file     loadfilter.h
* @author   Lorenz Esch <lorenz.esch@tu-ilmenau.de>;
*           Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     April, 2015
*
* @section  LICENSE
*
* Copyright (C) 2015, Lorenz Esch, Christoph Dinh and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of MNE-CPP authors nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief    LoadFilter class declaration.
*
*/

#ifndef LOADFILTER_H
#define LOADFILTER_H

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "../utils_global.h"
#include "filterdata.h"


//*************************************************************************************************************
//=============================================================================================================
// Qt INCLUDES
//=============================================================================================================

#include <QSharedPointer>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QStringList>


//*************************************************************************************************************
//=============================================================================================================
// Eigen INCLUDES
//=============================================================================================================

#include <Eigen/Core>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE MNELIB
//=============================================================================================================

namespace UTILSLIB
{


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace Eigen;


//*************************************************************************************************************
//=============================================================================================================
// DEFINES
//=============================================================================================================


//*************************************************************************************************************
//=============================================================================================================
// DEFINE FORWARD DECLARATIONS
//=============================================================================================================


//=============================================================================================================
/**
* Processes txt files which hold filter coefficients.
*
* @brief Processes txt files which hold filter coefficients.
*/
class UTILSSHARED_EXPORT LoadFilter
{
public:
    typedef QSharedPointer<LoadFilter> SPtr;            /**< Shared pointer type for LoadFilter. */
    typedef QSharedPointer<const LoadFilter> ConstSPtr; /**< Const shared pointer type for LoadFilter. */

    //=========================================================================================================
    /**
    * Constructs a LoadFilter object.
    */
    LoadFilter();

    //=========================================================================================================
    /**
    * Reads a given txt file and scans it for filter coefficients. Pls see sample file for file syntax.
    * @param [in] path holds the file path of the txt file which is to be read.
    * @param [out] coefficients holds the filter coefficients.
    * @param [out] type holds filter type (HPF, LPF, BPF).
    * @param [out] name holds the filter name.
    * @param [out] order holds the filter order.
    * @param [out] sFreq holds the filters sampling frequency.
    *
    * @return true if reading was successful, false otherwise.
    */
    static bool readFilter(QString path, RowVectorXd &coefficients, QString &type, QString &name, int &order, double &sFreq);

    //=========================================================================================================
    /**
    * Writes a given filter to txt file .
    * @param [in] path holds the file path of the txt file which is to be written to.
    * @param [in] coefficients holds the filter coefficients.
    * @param [in] type holds filter type (HPF, LPF, BPF).
    * @param [in] name holds the filter name.
    * @param [in] order holds the filter order.
    *
    * @return true if reading was successful, false otherwise.
    */
    static bool writeFilter(const QString &path, const RowVectorXd &coefficients, const QString &type, const QString &name, const int &order, const double &sFreq);

private:

};

} // NAMESPACE

#endif // LOADFILTER_H