#include "PrintableModel.h"

// public -----------------------------------------------------------------------------
PrintableModel::PrintableModel(void)
{
   m_alias  = "null";
   m_sprite = SpriteModel();
};

// public -----------------------------------------------------------------------------
PrintableModel::PrintableModel(SpriteModel sprite, std::string alias, int layer)
{
   m_sprite = sprite;
   m_alias  = alias;
};

// public -----------------------------------------------------------------------------
std::string PrintableModel::getAlias()
{
   return m_alias;
};

// public -----------------------------------------------------------------------------
SpriteModel PrintableModel::getSprite()
{
   return m_sprite;
}

// public -----------------------------------------------------------------------------
void PrintableModel::setAlias(std::string alias)
{
   m_alias = alias;
};

// public -----------------------------------------------------------------------------
void PrintableModel::setSprite(SpriteModel sprite)
{
   m_sprite = sprite;
};

// public -----------------------------------------------------------------------------
void PrintableModel::doMovement(char input) {}

// public -----------------------------------------------------------------------------
int PrintableModel::Compare(PrintableModel printable) const
{
   if (printable.getSprite() == m_sprite && printable.getAlias() == m_alias)
   {
      return 0;
   }
   return -1;
};
