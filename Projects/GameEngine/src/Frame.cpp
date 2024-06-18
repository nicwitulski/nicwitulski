#include "Frame.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// public -----------------------------------------------------------------------------
Frame::Frame(void)
{
   m_maxX = 79;
   m_maxY = 23;

   for (int i = 0; i < m_maxY; i++)
   {
      std::vector<char> temp;
      for (int j = 0; j < m_maxX; j++)
      {
         temp.push_back('+');
      }
      m_contents.push_back(temp);
   }
};

// public -----------------------------------------------------------------------------
Frame::Frame(int maxX, int maxY, std::vector<std::vector<char>> contents)
{
   m_maxX     = maxX;
   m_maxY     = maxY;
   m_contents = contents;
};

// public -----------------------------------------------------------------------------
void Frame::print(void)
{
   std::stringstream ss;
   for (unsigned i = 0; i < m_contents.size(); i++)
   {
      std::vector<char> line = m_contents.at(i);
      for (unsigned j = 0; j < line.size(); j++)
      {
         ss << line.at(j);
      }
      ss << std::endl;
   }
   std::cout << ss.str() << std::endl;
};

// public -----------------------------------------------------------------------------
int Frame::getMaxX()
{
   return m_maxX;
};

// public -----------------------------------------------------------------------------
int Frame::getMaxY()
{
   return m_maxY;
};

// public -----------------------------------------------------------------------------
char Frame::getContentAt(int x, int y)
{
   if ((x > m_maxX) || (y > m_maxY))
   {
      return '~';
   }

   return m_contents.at(y).at(x);
}

// public -----------------------------------------------------------------------------
std::string Frame::getContentString()
{
   std::string result;
   for (int y = 0; y < m_maxY; y++)
   {
      for (int x = 0; x < m_maxX; x++)
      {
         result.push_back(getContentAt(x, y));
      }
      result.push_back('\n');
   }
   return result;
}

// public -----------------------------------------------------------------------------
void Frame::setContents(std::vector<std::vector<char>> contents)
{
   m_contents = contents;
}

// public -----------------------------------------------------------------------------
void Frame::setContentChar(int x, int y, char character)
{
   if ((x > m_maxX) || (y > m_maxY))
   {
      return;
   }

   m_contents.at(y).at(x) = character;
};
