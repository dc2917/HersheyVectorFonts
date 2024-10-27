#include "fontfamily.hpp"

void FontFamily::load_fonts() {
    if(has_rm) {
        fonts["rm"] = Font(name + std::string("roman"));
    }
    if(has_it) {
        fonts["it"] = Font(name + std::string("italic"));
    }
    if(has_sc) {
        fonts["sc"] = Font(name + std::string("script"));
    }
    if(has_gr) {
        fonts["gr"] = Font(name + std::string("greek"));
    }
}

FontFamily::FontFamily(std::string name, bool rm, bool it, bool sc, bool gr) :
    name(name),
    has_rm(rm),
    has_it(it),
    has_sc(sc),
    has_gr(gr) {
    load_fonts();
}

Font FontFamily::get_font(std::string font) {
    return fonts[font];
}
