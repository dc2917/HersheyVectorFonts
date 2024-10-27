#ifndef HERSHEY_CAIRO_HPP
#define HERSHEY_CAIRO_HPP

/*! \file hershey_cairo.hpp
 This header file contains the declaration of the functions for the Cairo interface.
*/

#include <cairo-pdf.h>

#include "glyph.hpp"
#include "string.hpp"

#define A4_P_WIDTH 595.275590551
#define A4_P_HEIGHT 841.88976378
#define A5_P_WIDTH 420.94488189
#define A5_P_HEIGHT 595.275590551


/*!
  \brief Draw a glyph

  \param  cr The Cairo context
  \param  glyph The glyph to draw
  \param  x0 The starting x position
  \param  y0 The starting x position
  \param  scale The amount to scale the glyph by
*/
void draw_glyph(cairo_t *cr, Glyph glyph, int x0, int y0, int scale);

/*!
  \brief Draw a string of glyphs

  \param  cr The Cairo context
  \param  glyph The string of glyphs to draw
  \param  x0 The starting x position
  \param  y0 The starting x position
  \param  scale The amount to scale the glyphs by
*/
void draw_glyphs(cairo_t *cr, String string, int x0, int y0, int scale);

/*!
  \brief Calculate a fractional position

  \param  fraction The fraction to use
  \param  x The object's size
  \param  X The total size
*/
float position(float fraction, float x, float X);

#endif
