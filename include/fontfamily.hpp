#ifndef FONT_FAMILY_HPP
#define FONT_FAMILY_HPP

/*! \file fontfamily.hpp
 This header file contains the declaration of the FontFamily class.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "font.hpp"
#include "glyph.hpp"

/*! \class FontFamily
  \brief A Hershey vector font family
*/
class FontFamily {

    std::string name;  /*! The name of the font family. */
    bool has_rm;  /*! Whether the family contains a roman font. */
    bool has_it;  /*! Whether the family contains an italic font. */
    bool has_sc;  /*! Whether the family contains a script font. */
    bool has_gr;  /*! Whether the family contains a Greek font. */
    std::unordered_map<std::string, Font> fonts;  /*! The family's fonts. */

    private:
    /*!
      \brief Load and store each of the fonts in the family.
    */
    void load_fonts();

    public:
    /*!
      \brief Create a new font family.

      \param  name The name of the font family.
      \param  rm Whether the family contains a roman font.
      \param  it Whether the family contains a italic font.
      \param  sc Whether the family contains a script font.
      \param  gr Whether the family contains a Greek font.
    */
    FontFamily(std::string name, bool rm, bool it, bool sc, bool gr);

    /*!
      \brief Get a font.

      \param  The font to get.
    */
    Font get_font(std::string font);
};

#endif
