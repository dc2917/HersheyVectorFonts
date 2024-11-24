#include "hershey_svg.hpp"

void write_header(std::ofstream &svg_file, int width, int height, int scale) {
    svg_file << "<!-- Hershey vector font SVGs -->\n";
    svg_file << "<!-- github.com/dc2917/HersheyVectorFonts -->\n";
    svg_file << "<svg viewBox=\"0 0 " << width * scale << " " << height * scale << "\">\n";
}

void write_footer(std::ofstream &svg_file) {
    svg_file << "</svg>\n";
}

void draw_glyph(
    std::ofstream &svg_file, Hershey::Glyph glyph, int x0, int y0, int scale
) {

    int stroke_width = 1;

    svg_file << "\t<path d=\"\n\t\tM"
             << x0 + (glyph.coords[0][0] - glyph.get_lhp()) * scale << " "
             << y0 + glyph.coords[0][1] * scale << '\n';
    for(int v = 1; v < glyph.get_nvert(); ++v) {
        if((glyph.coords[v][0] == -50) && (glyph.coords[v][1] == 0)) {
            svg_file << "\t\tM";
            ++v;
        } else {
            svg_file << "\t\tL";
        }
        svg_file << x0 + (glyph.coords[v][0] - glyph.get_lhp()) * scale << " "
                 << y0 + glyph.coords[v][1] * scale << '\n';
    }
    svg_file << "\t\" stroke=\"black\" stroke-width=\"" << stroke_width << "\" fill=\"none\"/>\n";
}

void draw_glyphs(
    std::ofstream &svg_file, Hershey::String string, int x0, int y0, int scale
) {

    for(int c = 0; c < string.get_nglyph(); ++c) {
        draw_glyph(svg_file, string.get_glyph(c), x0, y0, scale);
        x0 += string.get_glyph(c).get_width() * scale;
    }
}

void draw_font(std::ofstream &svg_file, Hershey::Font font, int width, int height) {

    int scale = 1;
    int w, h;

    write_header(svg_file, width, height, scale);

    // Draw title
    Hershey::String title(font, font.get_name().c_str());
    w = title.get_width();
    h = title.get_height();
    draw_glyphs(svg_file, title, position(0.5, width, w) * scale, h + 20 * scale, scale);

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
        draw_glyph(svg_file, font.get_glyph(i), x0, y0, scale);

        if(i % chars_per_row == (chars_per_row - 1)) {
            y0 += cell_height;
        }
    }
    write_footer(svg_file);
}

float position(float fraction, float X, float x) {
    return fraction * (X - x);
}
