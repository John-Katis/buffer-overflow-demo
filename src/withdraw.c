/* withdraw.c */

#define DEBUG
#define PASSWD "openup!"
#include <stdio.h>
#include <string.h>


void open_safe() {
  printf("Opening safe door...\n");

  /* code to open safe goes here */

  printf("Safe opened successfully\n");
}

void verify_passwd() {
  char pass_buf[10];
  int i;

  for (i = 0; i < 10; i++) {
    pass_buf[i] = 0;
  }


#ifdef DEBUG
  printf("** Stack dump before verifying password **\n");
  printf("  Address        Value \n");

  for (i = 20; i >= 0; i--) {
    printf("0x%x => 0x%8.8x\n", &(((long *) pass_buf)[i]), ((long *)
            pass_buf)[i]);
  }
  printf("\n\n");
#endif

  printf("Please enter your password:\n");

  gets(pass_buf);

  if (strcmp(pass_buf, PASSWD) == 0) {
    open_safe();
  } else {
    printf("Bad password!\n");
  }
  
#ifdef DEBUG
  printf("\n\n");
  printf("** Stack dump after verifying password **\n");
  printf("  Address        Value \n");

  for (i = 20; i >= 0; i--) {
    printf("0x%x => 0x%8.8x\n", &(((long *) pass_buf)[i]), ((long *)
            pass_buf)[i]);
  }

  printf("\n\n");

  printf("&open_safe = 0x%8.8x\n", &open_safe);
#endif
}


int main() {
  verify_passwd();
}
