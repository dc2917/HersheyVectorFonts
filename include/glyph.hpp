#ifndef GLYPH_HPP
#define GLYPH_HPP

/*! \file glyph.hpp
 This header file contains the declaration of the Glyph class.
*/

#include <array>
#include <fstream>
#include <iostream>
#include <string>

namespace Hershey {

/*! \class Glyph
  \brief A Hershey vector font glyph.
*/
class Glyph {

    std::string raw; /*! The raw coordinate definition of the glyph. */
    int cid; /*! The unique identifier of the character. */
    int lhp; /*! The left-hand position of the character. */
    int rhp; /*! The right-hand position of the character. */
    int nvert; /*! The number of vertices in the character. */
    int height; /*! The height of the character. */
    int width; /*! The width of the character. */

    public:
    int coords[144][2]; /*! The x and y coordinates of the character's vertices. */

    /*!
      \brief Create a new glyph.
    */
    Glyph();

    /*!
      \brief Create a new glyph from a raw coordinate definition.

      \param  raw The raw coordinate definition of the glyph.
    */
    Glyph(std::string raw);

    /*!
      \brief Get the raw coordinate definition of the glyph.

      \retval  The raw coordinate definition of the glyph.
    */
    std::string get_raw();

    /*!
      \brief Get the character's unique identifier.

      \retval  The character's unique identifier.
    */
    int get_cid();

    /*!
      \brief Get the character's left-hand position.

      \retval  The character's left-hand position.
    */
    int get_lhp();

    /*!
      \brief Get the character's right-hand position.

      \retval  The character's right-hand position.
    */
    int get_rhp();

    /*!
      \brief Get the number of vertices making up the character.

      \retval  The number of vertices making up the character.
    */
    int get_nvert();

    /*!
      \brief Print information about the character.
    */
    void print_info();

    /*!
      \brief Print the character's vertices' coordinates in numpy array format.
    */
    void print_coords();

    /*!
      \brief Print the character's vertices' coordinates in numpy array format.
    */
    void print_coords_nparray();

    /*!
      \brief Get the character's width.

      \retval  The width of the character.
    */
    int get_width();

    /*!
      \brief Get the character's height.

      \retval  The height of the character.
    */
    int get_height();
};
} // namespace Hershey

#endif
