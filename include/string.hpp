#ifndef STRING_HPP
#define STRING_HPP

/*! \file string.hpp
 This header file contains the declaration of the String class
*/

#include <cstring>
#include <fstream>
#include <iostream>

#include "font.hpp"
#include "glyph.hpp"

namespace Hershey {

/*! \class String
  \brief A character string comprising Hershey vector font glyphs.
*/
class String {

    int num_glyphs; /*! The number of glyphs in the string. */
    Glyph *glyphs; /*! The glyphs in the string. */

    public:
    /*!
      \brief Create a new string.
    */
    String();

    /*!
      \brief Create a new string of glyphs of a given font.

      \param  font The name of the font to use.
      \param  chars The characters comprising the string.
    */
    String(Font font, const char *chars);

    /*!
      \brief Add two strings

      \param  rhs The string to be appended.
     */
    String operator+(String rhs);

    /*!
      \brief Get the number of glyphs in the string.

      \retval  The number of glyphs in the string.
    */
    int get_nglyph();

    /*!
      \brief Get a i'th glyph in the string.

      \param  i The index of the glyph to get.
      \retval  The glyph at position i in the string.
    */
    Glyph get_glyph(int i);

    /*!
      \brief Get the width of the string.

      \retval  The width of the string.
    */
    int get_width();

    /*!
      \brief Get the height of the string.

      \retval  The height of the string.
    */
    int get_height();
};
} // namespace Hershey

#endif
