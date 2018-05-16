/*                                                   */
/* Write a program to calculate pow(x,n)             */
/*                                                   */
/* Author: Hussama Ismail <hussama.ismail@gmail.com> */
/*                                                   */
#include <stdio.h>

#define ASSERT( expected, returned )  if ((expected) != (returned)) { \
	                                printf("failed."); return 1; \
                                      }

int my_pow(int base, int exp)
{
  if (exp == 0)
  {
    return 1;
  }
  else
  {
    return base * my_pow(base, exp-1);
  }
}

int main()
{
  ASSERT( 4, my_pow(2,2));
  ASSERT( 9, my_pow(3,2));
  ASSERT( 25, my_pow(5,2));
  ASSERT( 49, my_pow(7,2));
  return 0;
}
