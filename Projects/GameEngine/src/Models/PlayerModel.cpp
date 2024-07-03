#include "PlayerModel.h"
#include "../Controllers/KeybindsController.h"

#define blank 32

// static public ----------------------------------------------------------------------
void playerMovement(SpriteModel sprite)
{
   if (m_userInput == MOVE_UP)
   {
      sprite.moveUp();
   }
   else if (m_userInput == MOVE_DOWN)
   {
      sprite.moveDown();
   }
   else if (m_userInput == MOVE_RIGHT)
   {
      sprite.moveRight();
   }
   else if (m_userInput == MOVE_LEFT)
   {
      sprite.moveLeft();
   }
};

// public -----------------------------------------------------------------------------
PlayerModel::PlayerModel()
{
   m_userInput = blank;
   this->setAlias("player");
   this->setSprite(SpriteModel());
   this->setMoveable(true);
   this->setMovementLogic(&playerMovement);
};

// public -----------------------------------------------------------------------------
PlayerModel::PlayerModel(PositionModel position, SpriteModel sprite, std::string alias)
{
   m_userInput = blank;
   this->setAlias(alias);
   this->setSprite(sprite);
   this->getSprite().moveWholeSpriteToMiddlePosition(position);
   this->setMoveable(true);
   this->setMovementLogic(&playerMovement);
};

// public -----------------------------------------------------------------------------
void PlayerModel::setUserInput(char input)
{
   m_userInput = input;
};
