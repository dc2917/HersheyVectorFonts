#include "glyph.hpp"

using namespace Hershey;

Glyph::Glyph() {
}

Glyph::Glyph(std::string raw) : raw(raw) {
    cid = std::stoi(raw.substr(0, 5));
    nvert = std::stoi(raw.substr(5, 3)) - 1;
    lhp = static_cast<int>(raw.substr(8, 1).c_str()[0] - 'R');
    rhp = static_cast<int>(raw.substr(9, 1).c_str()[0] - 'R');
    for(int v = 0; v < nvert; ++v) {
        coords[v][0] = static_cast<int>(raw.substr(10 + 2 * v, 1).c_str()[0] - 'R');
        coords[v][1] = static_cast<int>(raw.substr(10 + 2 * v + 1, 1).c_str()[0] - 'R');
    }
}

std::string Glyph::get_raw() {
    return raw;
}

int Glyph::get_cid() {
    return cid;
}

int Glyph::get_lhp() {
    return lhp;
}

int Glyph::get_rhp() {
    return rhp;
}

int Glyph::get_nvert() {
    return nvert;
}

void Glyph::print_info() {
    std::cout << "Hershey character " << cid << " has " << nvert
              << " vertices:" << '\n'
              << "\t(" << lhp << ", " << rhp << ")" << '\n';
    for(int v = 0; v < nvert; ++v) {
        std::cout << "\t" << v + 1 << ": (" << coords[v][0] << ", " << coords[v][1]
                  << ")" << '\n';
    }
}

void Glyph::print_coords() {
    for(int v = 0; v < nvert; ++v) {
        std::cout << coords[v][0] << ", " << coords[v][1] << '\n';
    }
}

void Glyph::print_coords_nparray() {
    std::cout << "array([";
    for(int v = 0; v < nvert - 1; ++v) {
        std::cout << "\t[" << coords[v][0] << ", " << coords[v][1] << "]," << '\n';
    }
    std::cout << "\t[" << coords[nvert - 1][0] << ", " << coords[nvert - 1][1] << "]])"
              << '\n';
}

int Glyph::get_width() {
    return rhp - lhp;
}

int Glyph::get_height() {
    int min = 0;
    int max = 0;
    for(int v = 0; v < nvert; ++v) {
        if(coords[v][1] < min) {
            min = coords[v][1];
        }
        if(coords[v][1] > max) {
            max = coords[v][1];
        }
    }
    return max - min;
}
