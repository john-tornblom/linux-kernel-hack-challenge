#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Required for proper uint64_t format-strings
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#include "prf.h"
#include "cache.h"
#include "time_a60hz.h"
#include "time_types.h"

void time_A60Hz_Initialize(void)
{
  Time_Init();
}


void time_A60Hz_Execute(void)
{
  int32_t i = 0;
  uint64_t Tint = 0;
  uint64_t Ttimeout = 100000; //us
  uint64_t Texe = 2;
  uint64_t Texe_First = 0;
  int32_t ret = 0;
  
  // Profiling
  printf("Measuring...\n");
  while (Texe > Tint*1000 || Tint < 350 )
  {
    // Execute Application
    // Invalidate L1 before execution of application
    INVALIDATE_L1();
    START_PROFILING(Tint, Ttimeout);  // Tint and Ttimeout in us
    for (i = 0; i < 1; i++){
      Time_TypeP3(); // Little cache usage
      Time_TypeP4(); // Some L1 data cache usage
      Time_TypeP5(); // Extensive L1 data cache usage
    }
    ret = STOP_PROFILING(&Texe);  // Texe in ns
    if (Texe_First == 0) {
      Texe_First = Texe; // First sample without interrupts. No execution can be faster than this
    }
    // Measurement reported OK. => ret = 0
    // Execution time must be larger than first reported without interrupts
    // The increase in time shall be small enough, 1us extra execution can not 
    // have an execution time of more than 1us due to L1 cache effects.
    printf("Tint = ""%"PRIu64", ", Tint);
    printf("Texe = ""%"PRIu64", ", Texe/1000);
    printf("ret = %d\n", ret);

    Tint = Tint + 1;
  }
} 
