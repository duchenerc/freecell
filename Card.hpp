#pragma once

enum class CardSuit
{
   Club,
   Diamond,
   Heart,
   Spade
};

char CardSuitChar(const CardSuit aSuit);

enum class CardValue
{
   Ace,
   Deuce,
   Three,
   Four,
   Five,
   Six,
   Seven,
   Eight,
   Nine,
   Ten,
   Jack,
   Queen,
   King
};

const unsigned char ASCII_ONE = static_cast<unsigned char>('1');
char CardValueChar(const CardValue aValue);

struct Card
{
   CardSuit mSuit;
   CardValue mValue;

   Card(const CardSuit suit, const CardValue value);

   Card(const Card& rhs);
   Card& operator=(const Card& rhs);

   bool operator==(const Card& rhs) const;
};
