/*
 * Timer.h
 *
 *  Created on: Aug 25, 2011
 *      Author: wdxu
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "ITimer.h"

#include <QObject>
#include <QTimerEvent>

#include "boost/weak_ptr.hpp"

#include <map>

namespace Tn
{

//! Timer.

class Timer : public ITimer, public QObject
{
public:
    Timer();
    virtual ~Timer();

    virtual int registerTimer(boost::shared_ptr<ITimerObserver> observer, int timeout, int priority = 0);
    virtual int registerTimer(ITimerObserver *observer, int timeout, int priority = 0);

    virtual void cancelTimer(int timerId);

#ifdef UNIT_TEST
    int observerCount() const { return mObservers.size(); }
#endif

protected:
    // From QObject
    //! Handing of timer event.
    virtual void timerEvent(QTimerEvent *event);

public:
    static const int InvalidTimerId = -1;   //!< Id of invalid timer.

private:
    std::map<int, boost::weak_ptr<ITimerObserver> > mObservers; //!< Observers with weak pointer.
    std::map<int, ITimerObserver *> mLessSafeObservers;         //!< Observers with pointer.
};

}

#endif /* TIMER_H_ */
