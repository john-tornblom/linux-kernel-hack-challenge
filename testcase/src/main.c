#include <stdio.h>
#include <unistd.h>

#include "time_a60hz.h"
#include "cache.h"


static void test_check(int doIt) {
  if (doIt) {
    time_A60Hz_Initialize();

    for(int i=0;i<10;i++){
      INVALIDATE_L1();
      time_A60Hz_Execute();
    }
  }
}


static void run_tests(void) {
  test_check(1);
}


int main() {
  run_tests();

  printf("Done, sleeping\n");
  sleep(9999);
  return 0;
}

