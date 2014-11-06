#include <time.h>

#include "prf.h"

#define SEC2NANO 1000000000L
#define US_DIFF(start , stop) (SEC2NANO *(stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec))

static struct timespec t_start;
static int fd;

void START_PROFILING(uint64_t Interrupt_At_US, uint64_t General_Timeout_US) {
  clock_gettime(CLOCK_REALTIME, &t_start);
}

int  STOP_PROFILING(uint64_t* Measured_Time_US) {
  struct timespec t_stop;

  clock_gettime(CLOCK_REALTIME, &t_stop);
  *Measured_Time_US = US_DIFF(t_start, t_stop);

  return 0;
}

__attribute__((constructor(102))) static void prf_constructor (void) {
  fd = 1;
}
__attribute__((destructor)) static void prf_destructor (void) {
  fd = -1;
}
