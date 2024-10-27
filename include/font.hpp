#ifndef FONT_HPP
#define FONT_HPP

#include <iostream>
#include <fstream>
#include <string>

#include "glyph.hpp"

/*! A Hershey vector font */

class Font {
    std::string fname;  /*! The name of the file containing the glyph definitions. */
    std::string name;  /*! The name of the font. */
    int num_glyphs = 0;  /*! The number of glyphs in the font. */
    Glyph glyphs[98];  /*! The font's glyphs. */
    int baseline;  /*! The baseline of the font. */
    int descent;  /*! The descent of the font. */
    int ascent;  /*! The ascent of the font. */
    int xheight;  /*! The x-height of the font. */
    
    private:
    /*! Load font
      Load the font's glyph definition files and generate and store the glyphs.
     */
    void load_font();

    public:
    /*! Default constructor.
      Create a new font.
     */
    Font();

    /*! Constructor.
      Create a new font.
     */
    Font(std::string name);

    /*! Get fname
      Get the font's filename
     */
    std::string get_fname();

    /*! Get name
      Get the font's name
     */
    std::string get_name();

    /*! Get num glyphs
      Get the number of glyphs in the font.
     */
    int get_num_glyphs();

    /*! Get glyph
      Get the i'th glyph in the font.
     */
    Glyph get_glyph(int i);

    /*! Get glyph
      Get the glyph corresponding to character c.
     */
    Glyph get_glyph(char c);
};

#endif
