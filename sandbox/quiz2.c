#include <stdio.h>
#include <string.h>

#define sqr(x) (x * x)

int main()
{
  printf("%.2f, ", sqr(10.0));
  printf("%.2f\n", sqr(10.0-5.0));
}