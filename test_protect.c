#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
  // printf(1,"1" );
  char * x = sbrk(0);
  sbrk(PGSIZE);
  *x = 200;
  mprotect(x, 2) ;
  int y = fork();
  if(y == 0){
    printf(1, "Protected the value: %d \n", *x);
    munprotect(x, 2);
    *x = 10;
    printf(1, "Unprotecting it: %d \n", *x);
    exit();
  }
  else if(y > 0){
    wait();
    printf(1, "trapping... \n");
    *x = 10;
    exit();
  }
 exit();
}
