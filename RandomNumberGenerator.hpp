#pragma once

#include <cstdint>

class RandomNumberGenerator
{
public:
   using seed_t = std::uint32_t;

   RandomNumberGenerator(const seed_t aSeed);
   RandomNumberGenerator(const RandomNumberGenerator& aRhs) = default;
   RandomNumberGenerator& operator=(const RandomNumberGenerator& aRhs) = default;

   seed_t Next();

private:
   seed_t mSeed;
};
