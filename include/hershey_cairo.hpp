#ifndef HERSHEY_CAIRO_HPP
#define HERSHEY_CAIRO_HPP

/*! \file hershey_cairo.hpp
 This header file contains the declaration of the functions for the Cairo interface.
*/

#include <cairo-pdf.h>

#include "font.hpp"
#include "glyph.hpp"
#include "string.hpp"

#define A4_P_WIDTH 595.275590551   // 210 mm
#define A4_P_HEIGHT 841.889763780  // 297 mm
#define A5_P_WIDTH 419.527559055   // 148 mm
#define A5_P_HEIGHT 595.275590551  // 210 mm
#define A6_P_WIDTH 297.637795276   // 105 mm
#define A6_P_HEIGHT 419.527559055  // 148 mm
#define B6_P_WIDTH 354.330708661   // 125 mm
#define B6_P_HEIGHT 498.897637795  // 176 mm
#define L4x6_WIDTH 287.716535433   // 101.5 mm
#define L4x6_HEIGHT 432.000000000  // 152.4 mm

/*!
  \brief Draw a glyph

  \param  cr The Cairo context
  \param  glyph The glyph to draw
  \param  x0 The starting x position
  \param  y0 The starting x position
  \param  scale The amount to scale the glyph by
*/
void draw_glyph(cairo_t *cr, Hershey::Glyph glyph, float x0, float y0, float scale);

/*!
  \brief Draw a string of glyphs

  \param  cr The Cairo context
  \param  glyph The string of glyphs to draw
  \param  x0 The starting x position
  \param  y0 The starting x position
  \param  scale The amount to scale the glyphs by
*/
void draw_glyphs(cairo_t *cr, Hershey::String string, float x0, float y0, float scale);

/*!
  \brief Draw the glyphs in a font

  \param  cr The Cairo context
  \param  font The font to draw
*/
void draw_font(cairo_t *cr, Hershey::Font font, int width, int height);

/*!
  \brief Calculate a fractional position

  \param  fraction The fraction to use
  \param  x The object's size
  \param  X The total size
*/
float position(float fraction, float x, float X);

#endif
