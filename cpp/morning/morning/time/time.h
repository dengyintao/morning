#ifndef _MORNING_TIME_H_
#define __MORNING_TIME_H_
#include <iostream>
class time
{
private:
    /* data */
public:
    time(/* args */);
    ~time();


private:
    struct tm m_start_day,m_end_day;
    static void set_start_day(std::string start_day);
    static void set_end_day(std::string end_day);
    static bool checkdayformat(std::string day); 
    
public:
    static int diffdays(std::string startday, std::string enday);
};

time::time(/* args */)
{
}

time::~time()
{
}

#endif//_MORNING_TIME_H_