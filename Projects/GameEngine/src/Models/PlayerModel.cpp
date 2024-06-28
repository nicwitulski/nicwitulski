#include "PlayerModel.h"
#include "../Controllers/KeybindsController.h"

#define blank 32

char m_userInput;

// public -----------------------------------------------------------------------------
void PlayerModel::playerMovement()
{
   SpriteModel sprite = this->PrintableModel::getSprite();

   switch (m_userInput)
   {
      case MOVE_UP:
         sprite.moveUp();
         break;

      case MOVE_DOWN:
         sprite.moveDown();
         break;

      case MOVE_RIGHT:
         sprite.moveRight();
         break;

      case MOVE_LEFT:
         sprite.moveLeft();
         break;

      default:
   }
};

// public -----------------------------------------------------------------------------
PlayerModel::PlayerModel()
{
   m_userInput = blank;
   this->PrintableModel::setAlias("player");
   this->PrintableModel::setSprite(SpriteModel());
   this->setMoveable(true);
   this->setMovementLogic(playerMovement);
};

// public -----------------------------------------------------------------------------
PlayerModel::PlayerModel(PositionModel position, SpriteModel sprite, std::string alias)
{
   m_userInput = blank;
   this->PrintableModel::setAlias(alias);
   this->PrintableModel::setSprite(sprite);
   this->setMoveable(true);
   this->setMovementLogic(playerMovement);
};

// public -----------------------------------------------------------------------------
void PlayerModel::setUserInput(char input)
{
   m_userInput = input;
};
