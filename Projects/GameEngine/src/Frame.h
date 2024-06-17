#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <vector>

class Frame
{
private:
   int                            m_maxX;
   int                            m_maxY;
   std::vector<std::vector<char>> m_contents;

public:
   Frame();
   Frame(int x, int y, std::vector<std::vector<char>> contents);

   void print();

   int                            getMaxX();
   int                            getMaxY();
   char                           getContentAt(int x, int y);
   std::vector<std::vector<char>> getContents();
   std::string                    getContentString();

   void setContents(std::vector<std::vector<char>> contents);
   void setContentChar(int x, int y, char character);
};

#endif
