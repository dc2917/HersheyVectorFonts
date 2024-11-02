#include "string.hpp"

String::String(Font font, const char *chars) {
    num_glyphs = strlen(chars);
    for(int c = 0; c < num_glyphs; ++c) {
        glyphs[c] = font.get_glyph(chars[c]);
    }
}

int String::get_nglyph() {
    return num_glyphs;
}

Glyph String::get_glyph(int i) {
    return glyphs[i];
}

int String::get_width() {
    int width = 0;
    for(int i = 0; i < num_glyphs; ++i) {
        width += glyphs[i].get_width();
    }
    return width;
}

int String::get_height() {
    int height = 0;
    for(int i = 0; i < num_glyphs; ++i) {
        if(glyphs[i].get_height() > height) {
            height = glyphs[i].get_height();
        }
    }
    return height;
}
