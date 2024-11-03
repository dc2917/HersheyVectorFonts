# HersheyVectorFonts

A C++ library for working with the Hershey vector fonts.

## Overview

This library contains classes for representing glyphs of the [Hershey vector fonts](https://en.wikipedia.org/wiki/Hershey_fonts), for strings of glyphs, and for the fonts themselves. Also provided are interfaces to the [Cairo](https://cairographics.org) graphics library and the [Xlib](https://x.org) library, for drawing using the Hershey vector fonts.

## Example usage

```cpp
#include "hershey.hpp"
#include "hershey_cairo.hpp"

int main() {

    // Cairo initialisation
    cairo_surface_t *surface;
    cairo_t *cr;
    
    surface = cairo_pdf_surface_create("hello_world.pdf", 240, 80);
    cr = cairo_create(surface);
    
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, 1);

    // Hershey usage
    Hershey::Font hershey_font("complexroman");
    Hershey::String hershey_text(hershey_font, "Hello, world!");

    draw_glyphs(cr, hershey_text, 13, 40, 1);
    cairo_stroke(cr);
    cairo_show_page(cr);

    // Cairo clean-up
    cairo_surface_destroy(surface);
    cairo_destroy(cr);

    return 0;
}
```
