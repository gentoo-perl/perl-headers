#include "stdio.h"
#include "sys/socket.h"

int main(char *argc, char **argv) {
  printf("$sizeof{ &__ss_aligntype} = 0x%lx;\n",  sizeof(__ss_aligntype));
  printf("$sizeof{'struct cmsghdr'} = 0x%lx;\n",  sizeof(struct cmsghdr));
  return 0;
}


