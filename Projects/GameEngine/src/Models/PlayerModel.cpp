#include "PlayerModel.h"
#include "../Controllers/KeybindsController.h"

#define blank 32

char m_userInput;

// public -----------------------------------------------------------------------------
void PlayerModel::playerMovement()
{
   PositionModel position = this->PrintableModel::getPosition();

   switch (m_userInput)
   {
      case MOVE_UP:
         position.setLocation(position.getX(), position.getY() + 1);
         this->PrintableModel::setPosition(position);
         break;

      case MOVE_DOWN:
         position.setLocation(position.getX(), position.getY() - 1);
         this->PrintableModel::setPosition(position);
         break;

      case MOVE_RIGHT:
         position.setLocation(position.getX() + 1, position.getY());
         this->PrintableModel::setPosition(position);
         break;

      case MOVE_LEFT:
         position.setLocation(position.getX() - 1, position.getY());
         this->PrintableModel::setPosition(position);
         break;

      default:
   }
};

// public -----------------------------------------------------------------------------
PlayerModel::PlayerModel()
{
   m_userInput = blank;
   this->setMoveable(true);
   this->setMovementLogic(playerMovement);
};

// public -----------------------------------------------------------------------------
PlayerModel::PlayerModel(PositionModel position)
{
   m_userInput = blank;
   this->setMoveable(true);
   this->setMovementLogic(playerMovement);
   this->PrintableModel::setPosition(position);
};

// public -----------------------------------------------------------------------------
void PlayerModel::setUserInput(char input)
{
   m_userInput = input;
};
