#include <iostream>
using std::cout;
using std::endl;

//biblioteca que permite alguns controles sobre a saída
#include <iomanip>
using std::setfill; 
using std::setw;

#include "Time.h"
#include <ctime>

Time::Time(int hr, int min, int sec)
{
  setTime(hr, min, sec);  
}

Time::Time()
{
  time_t temp;
  time(&temp);
  struct tm *tempo = localtime(&temp);
  setTime(tempo->tm_hour, tempo->tm_min, tempo->tm_min);
}

void Time::setTime(int h, int m, int s)
{
  setHour(h);
  setMinute(m);
  setSecond(s);  
}

void Time::setHour(int h)
{
  hour = (h >=0 && h < 24) ? h : 0;
}

inline void Time::setMinute(int m)
{
  minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::setSecond( int s )
{
  second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printUniversal()
{
  cout << setfill('0') << setw(2) << getHour() << ":" <<
  setw(2) << getMinute() << ":" << setw(2) << getSecond() << endl;
}

void Time::printStandard()
{
  cout << ( (getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM") << endl;
}

void Time::tic()
{
  if(++second == 60)
  { 
    second = 0, ++minute;
    if(minute == 60) minute = 0, setHour(++hour);
  }
}