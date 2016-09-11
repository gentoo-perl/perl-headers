#include "stdio.h"

int main(char *argc, char **argv) {

#if DO_HASH_WARNING

  printf("{\n");
  printf("  package Gentoo::_SizeofWarn;\n");
  printf("  require Tie::Hash;\n");
  printf("  @ISA = qw(Tie::StdHash);\n");
  printf("  sub FETCH {\n");
  printf("    warn qq[No sizeof for '$_[1]'] unless exists $_[0]{$_[1]};\n");
  printf("    return $_[0]{$_[1]};\n");
  printf("  }\n");
  printf("}\n");
  printf("tie %%sizeof, 'Gentoo::_SizeofWarn';\n");

#endif

  printf("$sizeof{'char'              } = 0x%lx;\n", sizeof(char)              );
  printf("$sizeof{'int'               } = 0x%lx;\n", sizeof(int)               );
  printf("$sizeof{'long int'          } = 0x%lx;\n", sizeof(long int)          );
  printf("$sizeof{'long unsigned int' } = 0x%lx;\n", sizeof(long unsigned int) );
  printf("$sizeof{'short int'         } = 0x%lx;\n", sizeof(short int)         );
  printf("$sizeof{'short unsigned int'} = 0x%lx;\n", sizeof(short unsigned int));
  printf("$sizeof{'size_t'            } = 0x%lx;\n", sizeof(size_t)            );
  printf("$sizeof{'unsigned int'      } = 0x%lx;\n", sizeof(unsigned int)      );
  printf("$sizeof{'unsigned long int' } = 0x%lx;\n", sizeof(unsigned long int) );
  printf("$sizeof{'unsigned short int'} = 0x%lx;\n", sizeof(unsigned short int));

  return 0;
}


