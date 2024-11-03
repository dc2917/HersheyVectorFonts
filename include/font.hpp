#ifndef FONT_HPP
#define FONT_HPP

/*! \file font.hpp
 This header file contains the declaration of the Font class.
*/

#include <fstream>
#include <iostream>
#include <string>

#include "glyph.hpp"

namespace Hershey {

/*! \class Font
  \brief A Hershey vector font.
*/
class Font {

    std::string fname; /*! The name of the file containing the glyph definitions. */
    std::string name; /*! The name of the font. */
    int num_glyphs = 0; /*! The number of glyphs in the font. */
    Glyph glyphs[98]; /*! The font's glyphs. */
    int baseline; /*! The baseline of the font. */
    int descent; /*! The descent of the font. */
    int ascent; /*! The ascent of the font. */
    int xheight; /*! The x-height of the font. */

    private:
    /*!
      \brief Load the font's glyph definition files and generate and store the glyphs.
    */
    void load_font();

    public:
    /*!
      \brief Create a new font.
    */
    Font();

    /*!
      \brief Create a new font.

      \param  name The name of the font to create.
    */
    Font(std::string name);

    /*!
      \brief Get the font's filename.

      \retval  The name of the file containing the font's raw glyph definitions.
    */
    std::string get_fname();

    /*!
      \brief Get the font's name.

      \retval  The name of the font.
    */
    std::string get_name();

    /*!
      \brief Get the number of glyphs in the font.

      \retval  The number of glyphs in the font.
    */
    int get_num_glyphs();

    /*!
      \brief Get the i'th glyph in the font.

      \param  i The index of the glyph to get.
      \retval  The glyph at index i in the font.
    */
    Glyph get_glyph(int i);

    /*!
      \brief Get the glyph corresponding to character c.

      \param  c The character to get the glyph of.
      \retval  The glyph of character c.
    */
    Glyph get_glyph(char c);
};
} // namespace Hershey

#endif
