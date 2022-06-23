#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "bitfields.h"

uint64_t charMemBlock(uint64_t index)
{
  uint64_t memBlock = 0;
  memBlock = (ceil((float)(index + 1) / (float)(sizeof(char) * 8)) - 1);
  return memBlock;
}

char *createBitField(uint64_t size)
{
  char *result = calloc(size, sizeof(char));
  return result;
}

void setBits(char *bitField, uint64_t *indicesToSet, uint64_t numToSet) //sets bit at given postion/index (passed as argument indexToSet)
{
  uint64_t tmpField = 0x1, i;
  for(i = 0; i < numToSet; i++)
  {
    bitField[charMemBlock(indicesToSet[i])] |= (tmpField << (indicesToSet[i] - (charMemBlock(indicesToSet[i]) * (sizeof(char) * 8)))); //sets bit at playerPos by or-ing at that index, movement to index accomplished through << operator
  }
}

void unsetBits(char *bitField, uint64_t *indicesToUnset, uint64_t numToUnset)
{
  uint64_t tmpField = 0x1, i;
  for(i = 0; i < numToUnset; i++)
  {
    bitField[charMemBlock(indicesToUnset[i])] ^= (tmpField << (indicesToUnset[i] - (charMemBlock(indicesToUnset[i]) * (sizeof(char) * 8)))); //sets bit at indexToSet by or-ing at that index, movement to index accomplished through << operator
  }
}

bool isBitSet(char *bitField, uint64_t index)
{
  if(bitField[charMemBlock(index)] >> (index - (charMemBlock(index) * (sizeof(char) * 8))) & 0x1) //checks to see if the bit to be unset is set before attempting to unset it
  {
    return true;
  }
  return false;
}
