/*
 * ErrorCode.h
 *
 *  Created on: Aug 7, 2011
 *      Author: xuweidong
 */

#ifndef ERRORCODE_H_
#define ERRORCODE_H_

namespace Tn {

enum ErrorCode
{
    NoError = 0,        //!< No error.
    GeneralError,       //!< Not able to specify error type.
    InvalidArgument,    //!< Input argument is not correct, or the message cannot be handled by the class.
    NoMemeoryError,     //!< Not enough memory.
    IoError,            //!< I/O error.
    InternalError,      //!< The internal state of the class is not correct.
    NoMatchData,        //!< No matching data found.
    DuplicateData,      //!< Duplicate data exists, and replacing not allowed.
    OutOfRange
};

//! Check code is error.
inline bool isError(ErrorCode error)  { return (error != NoError); }

}

#endif /* ERRORCODE_H_ */
