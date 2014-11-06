#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mount.h>

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


__attribute__((constructor(101))) static void main_constructor(void) {
  if(mkdir("/proc", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH))
    printf("Failed to create directory '/proc'\n");

  if(mount(NULL, "/proc", "proc", 0, NULL) != 0)
    printf("Failed to mount /proc\n");
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

