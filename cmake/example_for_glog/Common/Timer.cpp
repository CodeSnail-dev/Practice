/*
 * Timer.cpp
 *
 *  Created on: Aug 25, 2011
 *      Author: wdxu
 */

#include "Timer.h"

namespace Tn
{

Timer::Timer()
{

}

Timer::~Timer()
{

}

int Timer::registerTimer(boost::shared_ptr<ITimerObserver> observer, int timeout, int priority)
{
    Q_UNUSED(priority);

    if (timeout < 0 || !observer)
        return InvalidTimerId;

    int timerId = this->startTimer(timeout);
    mObservers[timerId] = observer;
    return timerId;
}

int Timer::registerTimer(ITimerObserver *observer, int timeout, int priority)
{
    Q_UNUSED(priority);

    if (timeout < 0 || !observer)
        return InvalidTimerId;

    int timerId = this->startTimer(timeout);
    mLessSafeObservers[timerId] = observer;
    return timerId;
}

void Timer::cancelTimer(int timerId)
{
    std::map<int, boost::weak_ptr<ITimerObserver> >::iterator it1 = mObservers.find(timerId);
    if (it1 != mObservers.end())
    {
        mObservers.erase(it1);
        this->killTimer(timerId);
    }

    std::map<int, ITimerObserver *>::iterator it2 = mLessSafeObservers.find(timerId);
    if (it2 != mLessSafeObservers.end())
    {
        mLessSafeObservers.erase(it2);
        this->killTimer(timerId);
    }
}

void Timer::timerEvent(QTimerEvent *event)
{
    int timerId = event->timerId();
    this->killTimer(timerId);

    std::map<int, boost::weak_ptr<ITimerObserver> >::iterator it1 = mObservers.find(timerId);
    if (it1 != mObservers.end())
    {
        boost::shared_ptr<ITimerObserver> observer = it1->second.lock();
        mObservers.erase(it1);

        if (observer)
            observer->timeout(timerId);
    }

    std::map<int, ITimerObserver *>::iterator it2 = mLessSafeObservers.find(timerId);
    if (it2 != mLessSafeObservers.end())
    {
        ITimerObserver *observer = it2->second;
        mLessSafeObservers.erase(it2);

        if (observer)
            observer->timeout(timerId);
    }
}

}
