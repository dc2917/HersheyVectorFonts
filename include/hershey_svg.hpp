#ifndef HERSHEY_SVG_HPP
#define HERSHEY_SVG_HPP

/*! \file hershey_svg.hpp
 This header file contains the declaration of the functions for the svg interface.
*/

#include <fstream>
#include <iostream>

#include "font.hpp"
#include "glyph.hpp"
#include "string.hpp"

/*!
  \brief Write the svg file header

  \param  svg_file The file to draw to
  \param  width The width of the image
  \param  height The height of the image
  \param  scale The amount to scale the image by
*/
void write_header(std::ofstream &svg_file, int width, int height, int scale);

/*!
  \brief Write the svg file header

  \param  svg_file The file to draw to
*/
void write_footer(std::ofstream &svg_file);

/*!
  \brief Draw a glyph

  \param  svg_file The file to draw to
  \param  glyph The glyph to draw
  \param  x0 The starting x position
  \param  y0 The starting x position
  \param  scale The amount to scale the glyph by
*/
void draw_glyph(
    std::ofstream &svg_file, Hershey::Glyph glyph, int x0, int y0, int scale
);

/*!
  \brief Draw a string of glyphs

  \param  svg_file The file to draw to
  \param  string The string of glyphs to draw
  \param  x0 The starting x position
  \param  y0 The starting x position
  \param  scale The amount to scale the glyphs by
*/
void draw_glyphs(
    std::ofstream &svg_file, Hershey::String string, int x0, int y0, int scale
);

/*!
  \brief Draw the glyphs in a font

  \param  svg_file The file to draw to
  \param  font The font to draw
  \param  width The width of the image
  \param  height The height of the image
*/
void draw_font(std::ofstream &svg_file, Hershey::Font font, int width, int height);

/*!
  \brief Calculate a fractional position

  \param  fraction The fraction to use
  \param  x The object's size
  \param  X The total size
*/
float position(float fraction, float x, float X);

#endif
