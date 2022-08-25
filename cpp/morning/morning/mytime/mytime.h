#ifndef _MORNING_TIME_H_
#define _MORNING_TIME_H_
#include <iostream>
class mytime
{
private:
    struct tm m_start_day, m_end_day;
    static void set_start_day( std::string start_day );
    static void set_end_day( std::string end_day );
    static bool checkdayformat( std::string day ); 


public:
    mytime();
    ~mytime();

public:
    //∑µªÿ∏Ò Ω: 2022-08-26
    static std::string gettime();
    static int diffdays(std::string startday, std::string enday);
};

#endif