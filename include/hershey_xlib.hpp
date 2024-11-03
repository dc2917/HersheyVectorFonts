#ifndef HERSHEY_XLIB_HPP
#define HERSHEY_XLIB_HPP

/*! \file hershey_xlib.hpp
 This header file contains the declaration of the functions for the XLib interface.
*/

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "font.hpp"
#include "glyph.hpp"
#include "string.hpp"

/*!
  \brief Draw a glyph

  \param  display The display
  \param  win The window
  \param  gc The graphics context
  \param  x0 The starting x position
  \param  y0 The starting x position
  \param  scale The amount to scale the glyph by
*/
void draw_glyph(
    Display *display, Window *win, GC *gc, Hershey::Glyph glyph, int x0, int y0,
    int scale
);

/*!
  \brief Draw a string of glyphs

  \param  display The display
  \param  win The window
  \param  gc The graphics context
  \param  glyph The string of glyphs to draw
  \param  x0 The starting x position
  \param  y0 The starting x position
  \param  scale The amount to scale the glyphs by
*/
void draw_glyphs(
    Display *display, Window *win, GC *gc, Hershey::String string, int x0, int y0,
    int scale
);

/*!
  \brief Draw the glyphs in a font

  \param  display The display
  \param  win The window
  \param  gc The graphics context
  \param  font The font
*/
void draw_font(
    Display *display, Window *win, GC *gc, Hershey::Font font, int width, int height
);

/*!
  \brief Calculate a fractional position

  \param  fraction The fraction to use
  \param  x The object's size
  \param  X The total size
*/
float position(float fraction, float x, float X);

#endif
