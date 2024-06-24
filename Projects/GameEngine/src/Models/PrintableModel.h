#ifndef PRINTABLE_H
#define PRINTABLE_H

#include "PositionModel.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

///////////////////////////////////////////////////////////////////
/// @class Printable
///
/// Designates an object as printable or not
///////////////////////////////////////////////////////////////////
class PrintableModel
{
private:
   ///////////////////////////////////////////////////////////////////
   /// @fn expandContents
   ///
   /// @param length
   /// @param height
   /// @param padding
   ///////////////////////////////////////////////////////////////////
   void expandContents(int length, int height, char padding);

   ///////////////////////////////////////////////////////////////////
   /// @fn shrinkContents
   ///
   /// @param length
   /// @param height
   ///////////////////////////////////////////////////////////////////
   void shrinkContents(int length, int height);

public:
   ///////////////////////////////////////////////////////////////////
   /// @fn PrintableModel
   ///////////////////////////////////////////////////////////////////
   PrintableModel();

   ///////////////////////////////////////////////////////////////////
   /// @fn getAlias
   ///////////////////////////////////////////////////////////////////
   int getAlias();

   ///////////////////////////////////////////////////////////////////
   /// @fn getLength
   ///////////////////////////////////////////////////////////////////
   int getLength();

   ///////////////////////////////////////////////////////////////////
   /// @fn getHeight
   ///////////////////////////////////////////////////////////////////
   int getHeight();

   ///////////////////////////////////////////////////////////////////
   /// @fn getPosition
   ///////////////////////////////////////////////////////////////////
   PositionModel getPosition();

   ///////////////////////////////////////////////////////////////////
   /// @fn getContents
   ///////////////////////////////////////////////////////////////////
   std::vector<std::vector<char>> getContents();

   ///////////////////////////////////////////////////////////////////
   /// @fn getContentAt
   ///
   /// @param x
   /// @param y
   ///////////////////////////////////////////////////////////////////
   char getContentAt(int x, int y);

   ///////////////////////////////////////////////////////////////////
   /// @fn getContentString
   ///////////////////////////////////////////////////////////////////
   std::string getContentString();

   ///////////////////////////////////////////////////////////////////
   /// @fn setAlias
   ///////////////////////////////////////////////////////////////////
   void setAlias(std::string alias);

   ///////////////////////////////////////////////////////////////////
   /// @fn setDimensions
   ///
   /// @param length
   /// @param width
   /// @param padding
   ///////////////////////////////////////////////////////////////////
   void setDimensions(int length, int height, char padding);

   ///////////////////////////////////////////////////////////////////
   /// @fn setPosition
   ///
   /// @param position
   ///////////////////////////////////////////////////////////////////
   void setPosition(PositionModel position);

   ///////////////////////////////////////////////////////////////////
   /// @fn setContents
   ///
   /// @param contents
   ///////////////////////////////////////////////////////////////////
   void setContents(std::vector<std::vector<char>> contents);

   ///////////////////////////////////////////////////////////////////
   /// @fn setContentChar
   ///
   /// @param x
   /// @param y
   /// @param character
   ///////////////////////////////////////////////////////////////////
   void setContentChar(int x, int y, char character);

   void print();
};

#endif