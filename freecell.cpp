// freecell.cpp : Defines the entry point for the application.
//

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Card.hpp"

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

int main()
{
   const size_t seed = 57;

   std::vector<Card> dealDeck = DEAL_DECK;
   std::vector<Card> layout;
   layout.reserve(52);

   int remaining = 52;
   std::srand(seed);
   int j;
   for (int i = 0; i < 52; i++)
   {
      j = rand() % remaining;
      layout.push_back(dealDeck[j]);
      std::swap(dealDeck[j], dealDeck[--remaining]);
   }

   for (int i = 0; i < 52; i++)
   {
      if (i % 8 == 0 && i != 0)
      {
         std::cout << std::endl;
      }

      std::cout << CardValueChar(layout[i].mValue) << CardSuitChar(layout[i].mSuit) << " ";
   }

   return 0;
}
