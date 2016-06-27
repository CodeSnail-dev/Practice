/*
 * TimerList.h
 *
 *  Created on: Jan 10, 2012
 *      Author: wdxu
 */

#ifndef TIMERLIST_H_
#define TIMERLIST_H_

#include "Timer.h"

#include <vector>

namespace Tn
{

//! Container for Timer.

class TimerList : public ITimerObserver
{
public:
    TimerList();
    virtual ~TimerList();

    int addTimer(ITimerObserver *observer, int timeout, int priority = 0, bool startNow = false);
    void removeTimer(int timerId);

    void pauseTimer(int timerId);
    void resumeTimer(int timerId);

    void pauseAllTimer();
    void resumeAllTimer();

    virtual void timeout(int timerId);

private:
    class TimerInfo
    {
    public:
        TimerInfo()
            : mTimerId(Timer::InvalidTimerId),
              mInternalTimerId(Timer::InvalidTimerId),
              mObserver(0),
              mTimeout(0),
              mPriority(0),
              mStarted(false)
        {
        }

        TimerInfo(ITimerObserver *observer, int timeout, int priority)
            : mTimerId(Timer::InvalidTimerId),
              mInternalTimerId(Timer::InvalidTimerId),
              mObserver(observer),
              mTimeout(timeout),
              mPriority(priority),
              mStarted(false)
        {
        }

    public:
        int mTimerId;
        int mInternalTimerId;
        ITimerObserver *mObserver;
        int mTimeout;
        int mPriority;
        bool mStarted;
    };

private:
    Timer mTimer;
    std::vector<TimerInfo> mTimerInfoList;
    int mCurTimerId;
};

} /* namespace Tn */
#endif /* TIMERLIST_H_ */
