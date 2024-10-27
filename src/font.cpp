#include "font.hpp"

void Font::load_font() {
    std::ifstream hf(fname);
    std::string line;
    if(hf.is_open()) {
        while(std::getline(hf, line)) {
            glyphs[num_glyphs++] = Glyph(line);
        }
    } else {
        std::cout << "Unable to open file " << fname << std::endl;
    }
}

Font::Font() {
}

Font::Font(std::string name) : name(name) {
    fname = std::string("./data/") + name + std::string(".hf");
    load_font();
}

std::string Font::get_fname() {
    return fname;
}

std::string Font::get_name() {
    return name;
}

int Font::get_num_glyphs() {
    return num_glyphs;
}

Glyph Font::get_glyph(int i) {
    return glyphs[i];
}

Glyph Font::get_glyph(char c) {
    int i = static_cast<int>(c) - 32;
    if(i < 0 || i > 95) {
        std::cout << "Invalid character " << i << std::endl;
        return glyphs[0];
    } else {
        return glyphs[i];
    }
}
