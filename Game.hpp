#pragma once

#include <array>
#include <memory>
#include <optional>
#include <vector>

#include "Card.hpp"

class Game
{
public:
   using Column = std::vector<Card>;
   using Freecell = std::optional<Card>;
   using Homecell = std::vector<Card>;

   Game(); // use the builder to make a new Game
   Game(const Game& rhs) = default;
   Game& operator=(const Game& rhs) = default;

   void Print() const;

protected:

   size_t GetSizeLongestColumn() const;

   const static size_t NUM_COLUMNS = 8;
   const static size_t NUM_FREECELLS = 4;
   const static size_t NUM_HOMECELLS = 4;

   const static size_t MAX_COLUMN_HEIGHT = 18;
   const static size_t MAX_HOMECELL_HEIGHT = 13;

private:

   std::array<Column, NUM_COLUMNS> mColumns;
   std::array<Freecell, NUM_FREECELLS> mFreecells;
   std::array<Homecell, NUM_HOMECELLS> mHomecells;

   unsigned int mSeed = 0;

public:

   class Builder
   {
   public:
      Builder();
      Builder(const Builder& rhs) = delete;
      Builder& operator=(const Builder& rhs) = delete;

      void SetSeed(const unsigned int aSeed);
      std::unique_ptr<Game> Build();

   private:
      std::unique_ptr<Game> mGame = std::make_unique<Game>();
   };
};
