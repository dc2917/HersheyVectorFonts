#include "string.hpp"

using namespace Hershey;

String::String() {
}

String::String(Font font, const char *chars) {
    num_glyphs = strlen(chars);
    glyphs = new Glyph[num_glyphs];
    for(int c = 0; c < num_glyphs; ++c) {
        glyphs[c] = font.get_glyph(chars[c]);
    }
}

String String::operator+(String rhs) {

    String sum;
    sum.num_glyphs = (*this).get_nglyph() + rhs.get_nglyph();
    sum.glyphs = new Glyph[sum.num_glyphs];

    int c;
    for(c = 0; c < (*this).get_nglyph(); ++c) {
        sum.glyphs[c] = (*this).get_glyph(c);
    }
    for(c = 0; c < rhs.get_nglyph(); ++c) {
        sum.glyphs[c + (*this).get_nglyph()] = rhs.get_glyph(c);
    }

    return sum;
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
