#define _POSIX_C_SOURCE 200809L

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
//#include <limits>
#include <climits>

void print_current_time_with_ms (void)
{
    long            ms; // Milliseconds
    time_t          s;  // Seconds
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);
    
    s  = spec.tv_sec;
    ms = round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds

    printf("Current time: %"PRIdMAX".%03ld seconds since the Epoch\n",
           (intmax_t)s, ms);

    std::cout << "secs: " << spec.tv_sec << "." << spec.tv_nsec << std::endl;
    double d = spec.tv_nsec / 1.0e9 + spec.tv_sec;
    std::cout << "d " << d  << std::endl;
}

double timeDiff(struct timespec& t2, struct timespec& t1)
{
  //  double ret;
  std::cout << "t1 sec: " << t1.tv_sec << ", t2 sec: " << t2.tv_sec;
  long secDiff = t1.tv_sec - t2.tv_sec;
  std::cout << "\nsec dif: " << secDiff << std::endl;
  return (double) (t1.tv_nsec - t2.tv_nsec) * 1.0e-9 + secDiff;
}

int main()
{
  //  print_current_time_with_ms ();

  struct timespec t1, t2;
  clock_gettime(CLOCK_REALTIME, &t1);
  //  long l = std::numeric_limits<long>::max();
  for(long i=0; i < INT_MAX-1 ; i++)
    ;
  clock_gettime(CLOCK_REALTIME, &t2);

  double d = timeDiff(t1, t2);
  std::cout << "Diferencia de tiempo: " << d << std::endl;
  return 0;
}
