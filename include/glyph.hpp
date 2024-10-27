#ifndef GLYPH_HPP
#define GLYPH_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <array>

/*! A Hershey vector font glyph */

class Glyph {
    std::string raw;  /*! The raw coordinate definition of the glyph. */
    int cid;  /*! The unique identifier of the character. */
    int lhp;  /*! The left-hand position of the character. */
    int rhp;  /*! The right-hand position of the character. */
    int nvert;  /*! The number of vertices in the character. */
    int height;  /*! The height of the character. */
    int width;  /*! The width of the character. */

    public:
    int coords[144][2];  /*! The x and y coordinates of the character's vertices. */

    /*! Default constructor.
      Create a new glyph.
     */
    Glyph();

    /*! Constructor.
      Create a new glyph from a raw coordinate definition.
     */
    Glyph(std::string raw);

    /*! Get raw
      Get the raw coordinate definition of the glyph.
     */
    std::string get_raw();    

    /*! Get cid
      Get the character's unique identifier.
     */
    int get_cid();

    /*! Get lhp
      Get the character's left-hand position.
     */
    int get_lhp();

    /*! Get rhp
      Get the character's right-hand position.
     */
    int get_rhp();

    /*! Get nvert
      Get the number of vertices making up the character.
     */
    int get_nvert();

    /*! Print info
      Print information about the character.
     */
    void print_info();

    /*! Get cid
      Print the character's vertices' coordinates in numpy array format.
     */
    void print_coords();

    /*! Print coords nparray
      Print the character's vertices' coordinates in numpy array format.
     */
    void print_coords_nparray();

    /*! Get width
      Get the character's width.
     */
    int get_width();

    /*! Height
      Get the character's height.
     */
    int get_height();
};

#endif
