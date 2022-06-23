#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "bitfields.h"

int main()
{
  char *bitField = createBitField(2);
  uint64_t indexs[] = {11, 2, 0, 10};
  uint64_t indexsToUnset[] = {11};
  setBits(bitField, indexs, 4);
  unsetBits(bitField, indexsToUnset, 1);
  for(int i = 0; i < 16; i++)
  {
    if(isBitSet(bitField, i) == true)
    {
      printf("X");
    }
    else
    {
      printf(".");
    }
  }
  printf("\n");
  return 0;
}
