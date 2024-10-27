#ifndef HERSHEY_CAIRO_HPP
#define HERSHEY_CAIRO_HPP

#include <cairo-pdf.h>

#include "glyph.hpp"
#include "string.hpp"

#define A4_P_WIDTH 595.275590551
#define A4_P_HEIGHT 841.88976378
#define A5_P_WIDTH 420.94488189
#define A5_P_HEIGHT 595.275590551


void draw_glyph(cairo_t *cr, Glyph glyph, int x0, int y0, int scale);

void draw_glyphs(cairo_t *cr, String string, int x0, int y0, int scale);

float position(float fraction, float x, float X);

#endif
