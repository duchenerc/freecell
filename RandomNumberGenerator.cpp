#include "RandomNumberGenerator.hpp"

const unsigned int MULTIPLIER = 214013;
const unsigned int INCREMENT = 2531011;
const unsigned int MASK = (1u << 31) - 1;

RandomNumberGenerator::RandomNumberGenerator(const seed_t aSeed)
   : mSeed(aSeed)
{
}

RandomNumberGenerator::seed_t RandomNumberGenerator::Next()
{
   mSeed = (mSeed * MULTIPLIER + INCREMENT) & MASK;
   return mSeed >> 16;
}
