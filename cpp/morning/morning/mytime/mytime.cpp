#include "mytime.h"
#include <string>
#include <time.h>
#include <stdarg.h>
 
mytime::mytime(/* args */ )
{
}

mytime::~mytime( )
{
}

 void mytime::set_start_day(std::string start_day)
 {

 }

  void mytime::set_end_day(std::string start_day)
 {

 }

  bool mytime::checkdayformat(std::string day)
 {
    return false;
 }

  std::string format( const char* format, ... )
  {
      char buf[1024];
      va_list arglist;
      va_start( arglist, format );
      _vsnprintf( buf, 1024, format, arglist );
      va_end( arglist );
      return std::string( buf );
  }

  std::string mytime::gettime( )
  {
      struct tm p;
      const time_t t = time( NULL );
      localtime_s( &p,&t );
      std::string sz_current_time("");

      sz_current_time = format("%d-%d-%d",p.tm_year+1900,p.tm_mon+1,p.tm_mday );
      return sz_current_time;
  }

  int mytime::diffdays(std::string startday, std::string enday)
  {
      struct tm tstart(0), tend(0);
      
          tstart.tm_year = std::stoi(startday.substr( 0, 4 ));
          startday = startday.substr( 5 );
          tstart.tm_mon = std::stoi( startday.substr( 0, startday.find( '-' ) ));
          startday = startday.substr(startday.find('-' )+1 );
          tstart.tm_mday = std::stoi( startday );

          tstart.tm_year -= 1900;
          --tstart.tm_mon;
    
          tend.tm_year = std::stoi(enday.substr( 0, 4 ));
          enday = enday.substr( 5 );
          tend.tm_mon = std::stoi( enday.substr( 0, enday.find( '-' ) ) );
          enday = enday.substr( enday.find( '-' ) + 1 );
          tend.tm_mday = std::stoi( enday );

          tend.tm_year -= 1900;
          --tend.tm_mon;
     

      time_t start = mktime( &tstart );
      time_t end = mktime( &tend);
      return (end - start) / 86400;
  }