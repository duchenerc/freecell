// freecell.cpp : Defines the entry point for the application.
//

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

#include "Card.hpp"
#include "Game.hpp"

int main()
{
   const size_t seed = 57;
   std::unique_ptr<Game> gamePtr;
   Game::Builder builder;
   builder.SetSeed(seed);
   gamePtr = builder.Build();

   gamePtr->Print();

   return 0;
}
