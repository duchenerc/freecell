#include "Card.hpp"

char CardSuitChar(const CardSuit aSuit)
{
   using enum CardSuit;
   switch (aSuit)
   {
   case Club:
      return 'C';
   case Diamond:
      return 'D';
   case Heart:
      return 'H';
   case Spade:
      return 'S';
   }
}

char CardValueChar(const CardValue aValue)
{
   using enum CardValue;
   switch (aValue)
   {
   case Ace:
      return 'A';
   case Ten:
      return 'T';
   case Jack:
      return 'J';
   case Queen:
      return 'Q';
   case King:
      return 'K';
   default:
      return static_cast<char>(static_cast<int>(aValue) + ASCII_ONE);
   }
}

Card::Card(const CardSuit aSuit, const CardValue aValue)
   : mSuit(aSuit)
   , mValue(aValue)
{

}

Card::Card(const Card& rhs)
   : mSuit(rhs.mSuit)
   , mValue(rhs.mValue)
{

}

Card& Card::operator=(const Card& rhs)
{
   if (&rhs != this)
   {
      mSuit = rhs.mSuit;
      mValue = rhs.mValue;
   }

   return *this;
}

bool Card::operator==(const Card& rhs) const
{
   return mSuit == rhs.mSuit && mValue == rhs.mValue;
}
