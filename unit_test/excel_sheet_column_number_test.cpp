#include "gtest/gtest.h"
#include <string>

using namespace std;

int titleToNumber(string s);

TEST(ExcelSheetColumnNumberTestCase, Normal) {
    EXPECT_EQ(1, titleToNumber("A"));
    EXPECT_EQ(28, titleToNumber("AB"));
}
