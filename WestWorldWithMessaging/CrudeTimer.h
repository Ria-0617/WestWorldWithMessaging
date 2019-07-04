#ifndef CRUDETIMER_H
#define CRUDETIMER_H
//------------------------------------------------------------------------
//
//  Name:   CrudeTimer.h
//
//  Desc:   timer to measure time in seconds
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

#include <iostream>
#include <chrono>

#define Clock CrudeTimer::Instance()

class CrudeTimer
{
private:
  

  //set to the time (in seconds) when class is instantiated
  std::chrono::system_clock::time_point m_dStartTime;

  //set the start time
    CrudeTimer(){m_dStartTime = std::chrono::system_clock::now();}

  //copy ctor and assignment should be private
  CrudeTimer(const CrudeTimer&);
  CrudeTimer& operator=(const CrudeTimer&);
  
public:

  static CrudeTimer* Instance();

  //returns how much time has elapsed since the timer was started
  double GetCurrentTime(){
      return  std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - m_dStartTime).count();;
  }

};







#endif
