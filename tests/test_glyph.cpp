#include "gtest/gtest.h"
#include "glyph.hpp"

std::string glyph8_raw("    8  9MWOMOV RUMUV ROQUQ");
Hershey::Glyph glyph8(glyph8_raw);

TEST(GlyphTest, test_constructor) {
    EXPECT_EQ(glyph8.get_cid(), 8);
    EXPECT_EQ(glyph8.get_lhp(), -5);
    EXPECT_EQ(glyph8.get_rhp(), 5);
    EXPECT_EQ(glyph8.get_nvert(), 8);
}

TEST(GlyphTest, test_get_width) {
    EXPECT_EQ(glyph8.get_width(), 10);
}

TEST(GlyphTest, test_get_height) {
    EXPECT_EQ(glyph8.get_height(), 9);
}
