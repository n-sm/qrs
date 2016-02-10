#include <time.h>
#include <iostream>
//#include <climits>


double timeDiff(struct timespec& t2, struct timespec& t1)
{
  long secDiff = t1.tv_sec - t2.tv_sec;
  return (double) (t1.tv_nsec - t2.tv_nsec) * 1.0e-9 + secDiff;
}

int main()
{

  struct timespec t1, t2;
  clock_gettime(CLOCK_REALTIME, &t1);
  clock_gettime(CLOCK_REALTIME, &t2);
  std::cout << "Diferencia de tiempo: " << timeDiff(t1, t2) << std::endl;

  //struct tm tm1, tm2;
  time_t tt;
  time(&tt);
  std::cout << "tt: " << tt << '\n';

  time_t t = time(NULL);   // get time now, another way.
  std::cout << "tt: " << t << '\n';

  struct tm * now = localtime( & t );
  std::cout << (now->tm_year + 1900) << '-' 
	    << (now->tm_mon + 1) << '-'
	    <<  now->tm_mday
	    << std::endl;
  return 0;
}
