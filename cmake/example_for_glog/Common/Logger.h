/*
 * Logger.h
 *
 *  Created on: Aug 24, 2011
 *      Author: wdxu
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "glog/logging.h"
#ifdef COMPACT_GOOGLE_LOG_GERROR
#define COMPACT_GOOGLE_LOG_ERROR COMPACT_GOOGLE_LOG_GERROR
#endif // COMPACT_GOOGLE_LOG_GERROR

/*
class NoLog
{
public:
    inline NoLog(){}
    inline ~NoLog(){}

    template<typename T>
    inline NoLog &operator<<(const T &) { return *this; }
};
#define LOG(x) NoLog()
*/

/*
#include <QDebug>

namespace Tn {

#ifdef ENABLE_LOG
inline QDebug Logger() { return qDebug(); }
#else
#undef Logger
inline QNoDebug Logger() { return QNoDebug(); }
#define Logger while (false) Logger
#endif // ENABLE_LOG

}
*/

#endif /* LOGGER_H_ */
