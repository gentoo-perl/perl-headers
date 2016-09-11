#include "stdio.h"
#include "sys/select.h"

int main(char *argc, char **argv) {
  printf("$sizeof{ &fd_set    } = 0x%lx;\n",  sizeof(fd_set)   );
  printf("$sizeof{ &__fd_mask } = 0x%lx;\n",  sizeof(__fd_mask));
  return 0;
}


