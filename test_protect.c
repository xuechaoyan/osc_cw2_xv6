#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
  //invalid address
  int* a = (int*)4097;

  // test case 1
  //invalid address make mprotect fail
  printf(1, "Test case 1:\n");
  printf(1, "Value of address a is %d\n", *a);
  int i = mprotect((void*)a, sizeof(int));
  printf(1, "invalid address for mprotect\n");
  printf(1, "%d\n", i);


  // test case 2
  //invalid address make munprotect fail
  printf(1, "Test case 2:\n");
  printf(1, "Value of address a is %d\n", *a);
  i = munprotect((void*)a, sizeof(int));
  printf(1, "invalid address for munprotect\n");
  printf(1, "%d\n", i);


  //valid address
  int* b = (int*)4096;
  // test case 3
  //invalid len make mprotect fail
  printf(1, "Test case 3:\n");
  printf(1, "Value of address b is %d\n", *b);
  i = mprotect((void*)b, -1);
  printf(1, "valid lens for munprotect\n");
  printf(1, "%d\n", i);


  // test case 4
  //invalid len make munprotect fail
  printf(1, "Test case 4:\n");
  printf(1, "Value of address b is %d\n", *b);
  i = munprotect((void*)b, -1);
  printf(1, "valid lens for munprotect\n");
  printf(1, "%d\n", i);

  *b = 200;
  // test case 5
  //valid len and address make mprotect work
  printf(1, "Test case 5:\n");
  printf(1, "Value of address b is %d\n", *b);
  i = mprotect((void*)b, 1);
  printf(1, "worked mprotect\n");
  printf(1, "%d\n", i);


  // test case 6
  //valid len and address make munprotect work
  printf(1, "Test case 6:\n");
  printf(1, "Value of address b is %d\n", *b);
  i = munprotect((void*)b, 1);
  printf(1, "worked for munprotect\n");
  printf(1, "%d\n", i);

  exit();
}
