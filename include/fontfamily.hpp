#ifndef FONT_FAMILY_HPP
#define FONT_FAMILY_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "font.hpp"
#include "glyph.hpp"

/*! A Hershey vector font family */

class FontFamily {
    std::string name;  /*! The name of the font family. */
    bool has_rm;  /*! Whether the family contains a roman font. */
    bool has_it;  /*! Whether the family contains an italic font. */
    bool has_sc;  /*! Whether the family contains a script font. */
    bool has_gr;  /*! Whether the family contains a Greek font. */
    std::unordered_map<std::string, Font> fonts;  /*! The family's fonts. */

    private:
    /*! Load fonts
      Load and store each of the fonts in the family.
     */
    void load_fonts();

    public:
    /*! Constructor.
      Create a new font family.
     */
    FontFamily(std::string name, bool rm, bool it, bool sc, bool gr);

    /*! Get font
      Get a font.
     */
    Font get_font(std::string);
};

#endif
