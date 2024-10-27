#include "hershey_cairo.hpp"

void draw_glyph(cairo_t *cr, Glyph glyph, int x0, int y0, int scale) {
    int x1, x2, y1, y2;
    for(int v=0; v<glyph.get_nvert()-1; ++v) {
        x1 = glyph.coords[v][0];
        y1 = glyph.coords[v][1];
        x2 = glyph.coords[v+1][0];
        y2 = glyph.coords[v+1][1];
        if((x2 == -50) && (y2 == 0)) {
            ++v;
        } else {
            cairo_move_to(cr, x0+(x1-glyph.get_lhp())*scale, y0+y1*scale);
            cairo_line_to(cr, x0+(x2-glyph.get_lhp())*scale, y0+y2*scale);
        }
    }
}

void draw_glyphs(cairo_t *cr, String string, int x0, int y0, int scale) {
    for(int c=0; c<string.get_nglyph(); ++c) {
        draw_glyph(cr, string.get_glyph(c), x0, y0, scale);
        x0 += string.get_glyph(c).get_width()*scale;
    }
}

void draw_font(cairo_t *cr, Font font) {
}

float position(float fraction, float X, float x) {
    return fraction*(X-x);
}

