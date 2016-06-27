/*
 * TimerList.cpp
 *
 *  Created on: Jan 10, 2012
 *      Author: wdxu
 */

#include "TimerList.h"

namespace Tn
{

TimerList::TimerList()
    : mCurTimerId(0)
{

}

TimerList::~TimerList()
{
    this->pauseAllTimer();
}

int TimerList::addTimer(ITimerObserver *observer, int timeout, int priority, bool startNow)
{
    if (!observer || timeout < 0)
        return Timer::InvalidTimerId;

    TimerInfo timerInfo(observer, timeout, priority);
    timerInfo.mTimerId = mCurTimerId++;
    if (mCurTimerId < 0)
        mCurTimerId = 0;

    if (startNow)
    {
        timerInfo.mInternalTimerId = mTimer.registerTimer(this, timeout, priority);
        if (timerInfo.mInternalTimerId != Timer::InvalidTimerId)
            timerInfo.mStarted = true;
    }

    mTimerInfoList.push_back(timerInfo);

    return timerInfo.mTimerId;
}

void TimerList::removeTimer(int timerId)
{
    if (timerId == Timer::InvalidTimerId)
        return;

    for (std::vector<TimerInfo>::iterator it = mTimerInfoList.begin(); it != mTimerInfoList.end(); ++it)
    {
        if (it->mTimerId == timerId)
        {
            if (it->mStarted)
                mTimer.cancelTimer(it->mInternalTimerId);
            mTimerInfoList.erase(it);
            break;
        }
    }
}

void TimerList::pauseTimer(int timerId)
{
    if (timerId == Timer::InvalidTimerId)
        return;

    for (std::vector<TimerInfo>::iterator it = mTimerInfoList.begin(); it != mTimerInfoList.end(); ++it)
    {
        if (it->mTimerId == timerId)
        {
            if (it->mStarted)
            {
                mTimer.cancelTimer(it->mInternalTimerId);
                it->mInternalTimerId = Timer::InvalidTimerId;
                it->mStarted = false;
            }
            break;
        }
    }
}

void TimerList::resumeTimer(int timerId)
{
    if (timerId == Timer::InvalidTimerId)
        return;

    for (std::vector<TimerInfo>::iterator it = mTimerInfoList.begin(); it != mTimerInfoList.end(); ++it)
    {
        if (it->mTimerId == timerId)
        {
            if (!it->mStarted)
            {
                it->mInternalTimerId = mTimer.registerTimer(this, it->mTimeout, it->mPriority);
                if (it->mInternalTimerId != Timer::InvalidTimerId)
                    it->mStarted = true;
            }
            break;
        }
    }
}

void TimerList::pauseAllTimer()
{
    for (std::vector<TimerInfo>::iterator it = mTimerInfoList.begin(); it != mTimerInfoList.end(); ++it)
    {
        if (it->mStarted)
        {
            mTimer.cancelTimer(it->mInternalTimerId);
            it->mInternalTimerId = Timer::InvalidTimerId;
            it->mStarted = false;
        }
    }
}

void TimerList::resumeAllTimer()
{
    for (std::vector<TimerInfo>::iterator it = mTimerInfoList.begin(); it != mTimerInfoList.end(); ++it)
    {
        if (!it->mStarted)
        {
            it->mInternalTimerId = mTimer.registerTimer(this, it->mTimeout, it->mPriority);
            if (it->mInternalTimerId != Timer::InvalidTimerId)
                it->mStarted = true;
        }
    }
}

void TimerList::timeout(int timerId)
{
    for (std::vector<TimerInfo>::iterator it = mTimerInfoList.begin(); it != mTimerInfoList.end(); ++it)
    {
        if (it->mInternalTimerId == timerId)
        {
            if (it->mStarted)
            {
                if (it->mObserver)
                    it->mObserver->timeout(it->mTimerId);
                it->mInternalTimerId = mTimer.registerTimer(this, it->mTimeout, it->mPriority);
                it->mStarted = (it->mInternalTimerId != Timer::InvalidTimerId);
            }
            break;
        }
    }
}

} /* namespace Tn */
