#include "stdio.h"
#include "signal.h"

int main(char *argc, char **argv) {
  printf("$sizeof{ &FP_XSTATE_MAGIC2 } = 0x%lx;\n",  sizeof(FP_XSTATE_MAGIC2));
  return 0;
}


