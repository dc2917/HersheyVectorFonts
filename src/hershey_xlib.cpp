#include "hershey_xlib.hpp"

void draw_glyph(
    Display *display, Window *win, GC *gc, Hershey::Glyph glyph, int x0, int y0,
    int scale
) {

    int x1, x2, y1, y2;
    for(int v = 0; v < glyph.get_nvert() - 1; ++v) {
        x1 = glyph.coords[v][0];
        y1 = glyph.coords[v][1];
        x2 = glyph.coords[v + 1][0];
        y2 = glyph.coords[v + 1][1];
        if((x2 == -50) && (y2 == 0)) {
            ++v;
        } else {
            XDrawLine(
                display, *win, *gc, x0 + (x1 - glyph.get_lhp()) * scale,
                y0 + y1 * scale, x0 + (x2 - glyph.get_lhp()) * scale, y0 + y2 * scale
            );
        }
    }
}

void draw_glyphs(
    Display *display, Window *win, GC *gc, Hershey::String string, int x0, int y0,
    int scale
) {

    for(int c = 0; c < string.get_nglyph(); ++c) {
        draw_glyph(display, win, gc, string.get_glyph(c), x0, y0, scale);
        x0 += string.get_glyph(c).get_width() * scale;
    }
}

void draw_font(
    Display *display, Window *win, GC *gc, Hershey::Font font, int width, int height
) {

    int scale = 1;
    int w, h;

    // Draw title
    Hershey::String title(font, font.get_name().c_str());
    w = title.get_width();
    h = title.get_height();
    draw_glyphs(
        display, win, gc, title, width * scale / 2 - w / 2, h + 20 * scale, scale
    );

    // Draw glyphs
    int x0 = 8 * scale;
    int y0 = 100 * scale;
    int origin = x0;
    int cell_width = 44 * scale;
    int cell_height = 35 * scale;
    int chars_per_row = 16;
    Hershey::Glyph glyph;

    for(int i = 0; i < font.get_num_glyphs(); ++i) {
        glyph = font.get_glyph(i);
        w = glyph.get_rhp() - glyph.get_lhp();
        x0 = origin + (i % chars_per_row) * cell_width;
        x0 += cell_width / 2;
        x0 -= scale * w / 2;
        draw_glyph(display, win, gc, font.get_glyph(i), x0, y0, scale);

        if(i % chars_per_row == (chars_per_row - 1)) {
            y0 += cell_height;
        }
    }
}

float position(float fraction, float X, float x) {
    return fraction * (X - x);
}
