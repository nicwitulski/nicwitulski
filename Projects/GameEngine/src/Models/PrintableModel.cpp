#include "PrintableModel.h"

int                            m_length;
int                            m_height;
PositionModel                  m_position;
std::vector<std::vector<char>> m_contents;
std::string                    m_alias;

// public -----------------------------------------------------------------------------
PrintableModel::PrintableModel(void)
{
   m_length = 1;
   m_height = 1;
   m_position.setLocation(0, 0);
   m_alias = "null";

   for (int i = 0; i < m_length; i++)
   {
      std::vector<char> temp;
      for (int j = 0; j < m_height; j++)
      {
         temp.push_back('+');
      }
      m_contents.push_back(temp);
   }
};

// public -----------------------------------------------------------------------------
int PrintableModel::getLength()
{
   return m_length;
};

// public -----------------------------------------------------------------------------
int PrintableModel::getHeight()
{
   return m_height;
};

// public -----------------------------------------------------------------------------
PositionModel PrintableModel::getPosition()
{
   return m_position;
};

// public -----------------------------------------------------------------------------
std::vector<std::vector<char>> PrintableModel::getContents()
{
   return m_contents;
};

// public -----------------------------------------------------------------------------
char PrintableModel::getContentAt(int x, int y)
{
   if ((x > m_length) || (y > m_height))
   {
      return '~';
   }

   return m_contents.at(y).at(x);
}

// public -----------------------------------------------------------------------------
std::string PrintableModel::getContentString()
{
   std::string result;
   for (int y = 0; y < m_height; y++)
   {
      for (int x = 0; x < m_length; x++)
      {
         result.push_back(getContentAt(x, y));
      }
      result.push_back('\n');
   }
   return result;
}

// private ----------------------------------------------------------------------------
void PrintableModel::expandContents(int length, int height, char padding)
{
   if (length > m_length)
   {
      for (int i = 0; i < m_height; i++)
      {
         for (int j = m_length - 1; j < length; j++)
         {
            m_contents.at(i).push_back(padding);
         }
      }
      m_length = length;
   }
   if (height > m_height)
   {
      std::vector<char> lengthVector;
      for (int i = 0; i < m_length; i++)
      {
         lengthVector.push_back(padding);
      }
      for (int i = m_height - 1; i < height; i++)
      {
         m_contents.push_back(lengthVector);
      }
      m_height = height;
   }
};

// private ----------------------------------------------------------------------------
void PrintableModel::shrinkContents(int length, int height)
{
   if (length < m_length)
   {
      for (int i = 0; i < m_height; i++)
      {
         m_contents.at(i).resize(length);
      }
   }
   if (height < m_height)
   {
      m_contents.resize(height);
   }
};

// public -----------------------------------------------------------------------------
void PrintableModel::setDimensions(int length, int height, char padding)
{
   if (length > m_length || height > m_height)
   {
      expandContents(length, height, padding);
   }
   else if (length < m_length || height < m_height)
   {
      shrinkContents(length, height);
   }
};

// public -----------------------------------------------------------------------------
void PrintableModel::setContents(std::vector<std::vector<char>> contents)
{
   if ((contents.size() != m_contents.size()) && (contents.at(0).size() != m_contents.at(0).size()))
   {
      return;
   }

   m_contents = contents;
};

// public -----------------------------------------------------------------------------
void PrintableModel::setContentChar(int x, int y, char character)
{
   if ((x > m_length - 1) || (y > m_height - 1))
   {
      return;
   }

   m_contents.at(y).at(x) = character;
};

// public -----------------------------------------------------------------------------
void PrintableModel::print()
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
