#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "cache.h"

#define PROC_PATH "/proc/Invalidate_L1"
static FILE *pFile;


void INVALIDATE_L1(void) {
  fprintf(pFile, "%d", 1);
}


__attribute__((constructor(102))) static void cache_constructor (void) {
  pFile = fopen("/proc/Invalidate_L1", "w");
  if(!pFile) {
    perror("testcase: Unable to open "PROC_PATH);
  }
}

__attribute__((destructor)) static void cache_destructor (void) {
  if(pFile) {
    fclose(pFile);
  }
}

