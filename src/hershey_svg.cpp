#include "glyph.hpp"
#include <fstream>
#include <iostream>

void write_svg(Hershey::Glyph glyph) {

    std::ofstream fid("glyph.svg");

    int width;
    int scale;

    int baseline = 700;
    int y_off = 9;

    scale = 25;
    width = glyph.get_width();

    fid << "<!-- Hershey vector font SVGs -->\n";
    fid << "<!-- " << glyph.get_cid() << " -->\n";
    fid << "<svg viewBox=\"0 0 " << width * scale << " 1000\">\n";
    fid << "\t<path d=\"\n\t\tM" << (glyph.coords[0][0] - glyph.get_lhp()) * scale
        << " " << baseline - (-glyph.coords[0][1] + y_off) * scale << '\n';
    for(int v = 1; v < glyph.get_nvert(); ++v) {
        if((glyph.coords[v][0] == -50) && (glyph.coords[v][1] == 0)) {
            fid << "\t\tM";
            ++v;
        } else {
            fid << "\t\tL";
        }
        fid << (glyph.coords[v][0] - glyph.get_lhp()) * scale << " "
            << baseline - (-glyph.coords[v][1] + y_off) * scale << '\n';
    }
    fid << "\t\" stroke=\"black\" stroke-width=\"" << 1 << "\" fill=\"none\"/>\n";
    fid << "</svg>\n";

    fid.close();
}
