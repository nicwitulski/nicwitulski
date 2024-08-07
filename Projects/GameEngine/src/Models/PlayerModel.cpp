#include "PlayerModel.h"
#include "../Controllers/KeybindsController.h"

#define blank 32

// public -----------------------------------------------------------------------------
PlayerModel::PlayerModel()
{
   SpriteModel sprite = SpriteModel();
   setSprite(SpriteModel());
   setAlias("player");
   setMovable(true);
};

// public -----------------------------------------------------------------------------
PlayerModel::PlayerModel(PositionModel position, SpriteModel sprite, std::string alias)
{
   sprite.moveWholeSpriteToMiddlePosition(position);
   setSprite(sprite);
   setAlias(alias);
   setMovable(true);
};

void PlayerModel::doMovement(char input)
{
   SpriteModel newSprite = getSprite();
   switch (input)
   {
      case 'w':
         newSprite.moveUp();
         break;

      case 'a':
         newSprite.moveLeft();
         break;

      case 's':
         newSprite.moveDown();
         break;

      case 'd':
         newSprite.moveRight();
         break;

      default:
         break;
   }
   setSprite(newSprite);
};
