#ifndef PRF_H
#define PRF_H

#include <stdint.h>

void START_PROFILING(uint64_t Interrupt_At_US, uint64_t General_Timeout_US);
int  STOP_PROFILING(uint64_t* Measured_Time_US);

#endif
