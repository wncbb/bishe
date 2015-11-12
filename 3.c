#include <stdio.h>
#include <stdlib.h>
int main()
{
  int a=12;
  int b=13;
  if(b<14)
  {
      int c=a;
      
      int a=a+1;
      printf("a=%d c=%d\n", a, c);
  }
  printf("a=%d\n", a);
  return 0;
}





