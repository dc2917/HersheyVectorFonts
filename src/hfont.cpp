#include <iostream>
#include <fstream>
#include <string>

class Glyph {
    std::string raw;
    int cid;
    int lhp;
    int rhp;
    int nvert;
    int height;
    int width;
    int coords[144][2];

    public:
    Glyph() {}
    Glyph(std::string _raw) {
        raw = _raw;
        cid = std::stoi(raw.substr(0, 5));
        nvert = std::stoi(raw.substr(5, 3));
        lhp = static_cast<int>(raw.substr(8, 1).c_str()[0] - 'R');
        rhp = static_cast<int>(raw.substr(9, 1).c_str()[0] - 'R');
        for(int v=0; v<nvert-1; ++v) {
            coords[v][0] = static_cast<int>(raw.substr(10+2*v, 1).c_str()[0] - 'R');
            coords[v][1] = static_cast<int>(raw.substr(10+2*v+1, 1).c_str()[0] - 'R');
        }
    };
    std::string get_raw() {
        return raw;
    }
    int get_cid() {
        return cid;
    }
    int get_lhp() {
        return lhp;
    }
    int get_rhp() {
        return rhp;
    }
    int get_nvert() {
        return nvert;
    }
    void print_coords() {
        for(int v=0; v<nvert-1; ++v) {
            std::cout << coords[v][0] << ", " << coords[v][1] << std::endl;
        }
    }
};

class Font {

    std::string fname;
    std::string name;
    int num_glyphs = 0;
    Glyph glyphs[98];

    private:
    void load_font() {
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

    public:
    Font(std::string _name) {
        name = _name;
        fname = std::string("../data/") + name + std::string(".hf");
        load_font();
    }
    std::string get_fname() {
        return fname;
    }
    std::string get_name() {
        return name;
    }
    int get_num_glyphs() {
        return num_glyphs;
    }
    Glyph get_glyph(int i) {
        return glyphs[i];
    }
};

