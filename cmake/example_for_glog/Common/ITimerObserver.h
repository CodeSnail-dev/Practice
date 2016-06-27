/*
 * ITimerObserver.h
 *
 *  Created on: Aug 25, 2011
 *      Author: wdxu
 */

#ifndef ITIMEROBSERVER_H_
#define ITIMEROBSERVER_H_

namespace Tn
{

//! Observer for Timer.

class ITimerObserver
{
protected:
    virtual ~ITimerObserver() {}

public:
    //! Notification of timeout.
    /*!
     * \param timerId timer id.
     */
    virtual void timeout(int timerId) = 0;
};

}

#endif /* ITIMEROBSERVER_H_ */
