#ifndef CAMERA_H
#define CAMERA

#include "PlayerModel.h"
#include "PositionModel.h"

class CameraModel
{
private:
public:
   CameraModel();

   CameraModel(int length, int height, PositionModel middlePosition, bool isLockedOntoPlayer,
               PlayerModel player);

   void setMiddlePosition();

   void setMiddlePosition(PositionModel position);

   PositionModel getMiddlePosition();

   void setDimensions(int length, int height);

   int getLength();

   int getHeight();
};

#endif
