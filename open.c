/* open.c */
#include <stdio.h>

int main() {
  int i;

  char addr[] = "\x98\x83\x04\x08";
  
  for (i = 0; i<8; i++) {
    printf(addr);
  }
}
