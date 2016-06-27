/*
 * ITimer.h
 *
 *  Created on: Aug 25, 2011
 *      Author: wdxu
 */

#ifndef ITIMER_H_
#define ITIMER_H_

#include "ITimerObserver.h"

#include "boost/shared_ptr.hpp"

namespace Tn
{

//! Interface for timer.

class ITimer
{
public:
    virtual ~ITimer() {}

    //! Register a timer.
    /*!
     * \param observer shared pointer to observer.
     * \param timeout timeout period, in millisecond.
     * \param priority priority of the timer.
     * \return Timer id.
     */
    virtual int registerTimer(boost::shared_ptr<ITimerObserver> observer, int timeout, int priority = 0) = 0;

    //! Register a timer.
    /*! This is a easier to use but less safe way to register timer.  But if the only observer owns this timer, it should be fine.
     * \param observer pointer to observer.
     * \param timeout timeout period, in millisecond.
     * \param priority priority of the timer.
     * \return Timer id.
     */
    virtual int registerTimer(ITimerObserver *observer, int timeout, int priority = 0) = 0;

    //! Cancel a timer.
    /*!
     * \param timerId id of the timer registered.
     */
    virtual void cancelTimer(int timerId) = 0;
};

}

#endif /* ITIMER_H_ */
