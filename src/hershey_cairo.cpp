#include "hershey_cairo.hpp"

void draw_glyph(cairo_t *cr, Glyph glyph, int x0, int y0, int scale) {
    int x1, x2, y1, y2;
    for(int v = 0; v < glyph.get_nvert() - 1; ++v) {
        x1 = glyph.coords[v][0];
        y1 = glyph.coords[v][1];
        x2 = glyph.coords[v + 1][0];
        y2 = glyph.coords[v + 1][1];
        if((x2 == -50) && (y2 == 0)) {
            ++v;
        } else {
            cairo_move_to(cr, x0 + (x1 - glyph.get_lhp()) * scale, y0 + y1 * scale);
            cairo_line_to(cr, x0 + (x2 - glyph.get_lhp()) * scale, y0 + y2 * scale);
        }
    }
}

void draw_glyphs(cairo_t *cr, String string, int x0, int y0, int scale) {
    for(int c = 0; c < string.get_nglyph(); ++c) {
        draw_glyph(cr, string.get_glyph(c), x0, y0, scale);
        x0 += string.get_glyph(c).get_width() * scale;
    }
}

void draw_font(cairo_t *cr, Font font, int width, int height) {

    // Draw title
    int scale = 1;
    // std::string fontname = font.get_name();
    // String title(font, fontname);
    // draw_glyphs(cr, title, position(0.5, width, title.get_width()), 20*scale, scale);

    // Draw glyphs
    int w, h;
    int nchars = font.get_num_glyphs();
    int x0 = 8 * scale;
    int y0 = 100 * scale;
    int origin = x0;
    int cell_width = 44 * scale;
    int cell_height = 35 * scale;
    int chars_per_row = 16;
    Glyph glyph;

    for(int i = 0; i < nchars; ++i) {
        glyph = font.get_glyph(i);
        w = glyph.get_rhp() - glyph.get_lhp();
        x0 = origin + (i % chars_per_row) * cell_width;
        x0 += cell_width / 2;
        x0 -= scale * w / 2;
        draw_glyph(cr, font.get_glyph(i), x0, y0, scale);

        if(i % chars_per_row == (chars_per_row - 1)) {
            y0 += cell_height;
        }
    }
}

float position(float fraction, float X, float x) {
    return fraction * (X - x);
}
