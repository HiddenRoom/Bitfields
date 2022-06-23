#ifndef bitfields
#define bitfields

uint64_t charMemBlock(uint64_t index);
char *createBitField(uint64_t size);
void setBits(char *bitField, uint64_t *indicesToSet, uint64_t numToSet);
void unsetBits(char *bitField, uint64_t *indicesToUnset, uint64_t numToUnset);
bool isBitSet(char *bitField, uint64_t index);

#endif

