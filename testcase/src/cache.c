#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "cache.h"

#define PROC_PATH "/proc/Invalidate_L1"
static int fd;


void INVALIDATE_L1(void) {

}


__attribute__((constructor)) static void cache_constructor (void) {
  fd = open(PROC_PATH, O_WRONLY);
  if(fd < 0) {
    perror("testcase: Unable to open "PROC_PATH);
  }
}

__attribute__((destructor)) static void cache_destructor (void) {
  if(fd >= 0) {
    close(fd);
  }
}
