#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <fstream>
#include <cstring>

#include "font.hpp"
#include "glyph.hpp"

/*! A character string comprising Hershey vector font glyphs */

class String {

    int num_glyphs;  /*! The number of glyphs in the string. */
    Glyph glyphs[32];  /*! The glyphs in the string. */

    public:
    /*! Constructor
      Create a new string of a given font.
     */
    String(Font font, char *chars);

    /*! Get nglyph
      Get the number of glyphs in the string.
     */
    int get_nglyph();

    /*! Get glyph
      Get a glyph in the string.
     */
    Glyph get_glyph(int i);

    /*! Get width
      Get the width of the string.
     */
    int get_width();

    /*! Get height
      Get the height of the string.
     */
    int get_height();
};

#endif
