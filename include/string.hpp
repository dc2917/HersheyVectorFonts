#ifndef STRING_HPP
#define STRING_HPP

/*! \file string.hpp
 This header file contains the declaration of the String class
*/

#include <iostream>
#include <fstream>
#include <cstring>

#include "font.hpp"
#include "glyph.hpp"

/*! \class String
  \brief A character string comprising Hershey vector font glyphs.
*/
class String {

    int num_glyphs;  /*! The number of glyphs in the string. */
    Glyph glyphs[32];  /*! The glyphs in the string. */

    public:
    /*!
      \brief Create a new string of a given font.

      \param  font The name of the font to use.
      \param  chars The characters comprising the string.
    */
    String(Font font, char *chars);

    /*!
      \brief Get the number of glyphs in the string.
    */
    int get_nglyph();

    /*!
      \brief Get a i'th glyph in the string.

      \param  i The index of the glyph to get.
    */
    Glyph get_glyph(int i);

    /*!
      \brief Get the width of the string.
    */
    int get_width();

    /*!
      \brief Get the height of the string.
    */
    int get_height();
};

#endif
