#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <string>
#include <vector>

class Printable
{
private:
   int                            length;
   int                            height;
   std::vector<std::vector<char>> m_contents;
};

#endif
