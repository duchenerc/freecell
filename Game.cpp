#include "Game.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

const std::vector<Card> DEAL_DECK = {
   { CardSuit::Club   , CardValue::Ace   },
   { CardSuit::Diamond, CardValue::Ace   },
   { CardSuit::Heart  , CardValue::Ace   },
   { CardSuit::Spade  , CardValue::Ace   },
   { CardSuit::Club   , CardValue::Deuce },
   { CardSuit::Diamond, CardValue::Deuce },
   { CardSuit::Heart  , CardValue::Deuce },
   { CardSuit::Spade  , CardValue::Deuce },
   { CardSuit::Club   , CardValue::Three },
   { CardSuit::Diamond, CardValue::Three },
   { CardSuit::Heart  , CardValue::Three },
   { CardSuit::Spade  , CardValue::Three },
   { CardSuit::Club   , CardValue::Four  },
   { CardSuit::Diamond, CardValue::Four  },
   { CardSuit::Heart  , CardValue::Four  },
   { CardSuit::Spade  , CardValue::Four  },
   { CardSuit::Club   , CardValue::Five  },
   { CardSuit::Diamond, CardValue::Five  },
   { CardSuit::Heart  , CardValue::Five  },
   { CardSuit::Spade  , CardValue::Five  },
   { CardSuit::Club   , CardValue::Six   },
   { CardSuit::Diamond, CardValue::Six   },
   { CardSuit::Heart  , CardValue::Six   },
   { CardSuit::Spade  , CardValue::Six   },
   { CardSuit::Club   , CardValue::Seven },
   { CardSuit::Diamond, CardValue::Seven },
   { CardSuit::Heart  , CardValue::Seven },
   { CardSuit::Spade  , CardValue::Seven },
   { CardSuit::Club   , CardValue::Eight },
   { CardSuit::Diamond, CardValue::Eight },
   { CardSuit::Heart  , CardValue::Eight },
   { CardSuit::Spade  , CardValue::Eight },
   { CardSuit::Club   , CardValue::Nine  },
   { CardSuit::Diamond, CardValue::Nine  },
   { CardSuit::Heart  , CardValue::Nine  },
   { CardSuit::Spade  , CardValue::Nine  },
   { CardSuit::Club   , CardValue::Ten   },
   { CardSuit::Diamond, CardValue::Ten   },
   { CardSuit::Heart  , CardValue::Ten   },
   { CardSuit::Spade  , CardValue::Ten   },
   { CardSuit::Club   , CardValue::Jack  },
   { CardSuit::Diamond, CardValue::Jack  },
   { CardSuit::Heart  , CardValue::Jack  },
   { CardSuit::Spade  , CardValue::Jack  },
   { CardSuit::Club   , CardValue::Queen },
   { CardSuit::Diamond, CardValue::Queen },
   { CardSuit::Heart  , CardValue::Queen },
   { CardSuit::Spade  , CardValue::Queen },
   { CardSuit::Club   , CardValue::King  },
   { CardSuit::Diamond, CardValue::King  },
   { CardSuit::Heart  , CardValue::King  },
   { CardSuit::Spade  , CardValue::King  },
};

Game::Game()
{
   for (auto& col : mColumns)
   {
      col.reserve(MAX_COLUMN_HEIGHT);
   }
   for (auto& homecell : mHomecells)
   {
      homecell.reserve(MAX_HOMECELL_HEIGHT);
   }
}

size_t Game::GetSizeLongestColumn() const
{
   size_t size = 0;
   for (const auto& col : mColumns)
   {
      size = std::max(size, col.size());
   }
   return size;
}

void Game::Print() const
{
   for (const auto& freecell : mFreecells)
   {
      if (freecell)
      {
         std::cout << "[" << CardValueChar(freecell->mValue) << CardSuitChar(freecell->mSuit) << "]";
      }
      else
      {
         std::cout << "[  ]";
      }
   }
   
   std::cout << "    ";

   for (const auto& homecell : mHomecells)
   {
      if (!homecell.empty())
      {
         std::cout << "[" << CardValueChar(homecell.back().mValue) << CardSuitChar(homecell.back().mSuit) << "]";
      }
      else
      {
         std::cout << "[  ]";
      }
   }

   std::cout << std::endl;

   size_t size = GetSizeLongestColumn();
   for (size_t i = 0; i < size; i++)
   {
      std::cout << "   ";
      for (const auto& col : mColumns)
      {
         if (i < col.size())
         {
            std::cout << CardValueChar(col[i].mValue) << CardSuitChar(col[i].mSuit) << "  ";
         }
         else
         {
            std::cout << "    ";
         }
      }
      std::cout << std::endl;
   }
   std::cout << std::flush;
}

Game::Builder::Builder()
{
   // std::srand(static_cast<unsigned int>(std::time(NULL)));
   // mGame->mSeed = std::rand() % 32000;
}

void Game::Builder::SetSeed(const size_t aSeed)
{
   mGame->mSeed = aSeed;
}

std::unique_ptr<Game> Game::Builder::Build()
{
   std::vector<Card> dealDeck = DEAL_DECK;

   std::srand(mGame->mSeed);

   int remaining = 52;
   int j;
   for (int i = 0; i < 52; i++)
   {
      j = rand() % remaining;
      mGame->mColumns[i % NUM_COLUMNS].push_back(dealDeck[j]);
      std::swap(dealDeck[j], dealDeck[--remaining]);
   }

   return std::move(mGame);
}
