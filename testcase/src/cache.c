#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "cache.h"

#define PROC_PATH "/proc/Invalidate_L1"
static int fd;


void INVALIDATE_L1(void) {
  write(fd, "\x00", 1);
}


__attribute__((constructor(102))) static void cache_constructor (void) {
  if((fd = open(PROC_PATH, O_WRONLY | O_DSYNC | O_RSYNC | O_SYNC)) < 0) {
    perror("testcase: Unable to open "PROC_PATH);
  }
}


__attribute__((destructor)) static void cache_destructor (void) {
  if(fd != -1) {
    close(fd);
  }
}

