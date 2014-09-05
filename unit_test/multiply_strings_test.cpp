#include "gtest/gtest.h"

#include <iostream>
#include <string>

using namespace std;

string multiply(string str, char c);
string add(string num1, string num2, int shift);
string multiply(string num1, string num2);

TEST(MultiplyStringsTestCase, MultiplyChar)
{
    string a = multiply(string("1234"), '5');
    string b = multiply(string("473"), '9');
    string c = multiply(string("999"), '0');
    string d = multiply(string("999"), '9');

    cout << a << ", " << b << ", " << c << ", " << d << endl;

    EXPECT_STREQ("6170", a.c_str());
    EXPECT_STREQ("4257", b.c_str());
    EXPECT_STREQ("0", c.c_str());
    EXPECT_STREQ("8991", d.c_str());
}

TEST(MultiplyStringsTestCase, Add)
{
    string a = add(string("123"), string("123"), 1);
    string b = add(string("0"), string("456"), 1);
    string c = add(string("789"), string("0"), 1);
    string d = add(string("12"), string("88547"), 1);
    string e = add(string("88632"), string("1"), 1);

    cout << a << ", " << b << ", " << c << ", " << d << ", " << e << endl;

    EXPECT_STREQ("1353", a.c_str());
    EXPECT_STREQ("4560", b.c_str());
    EXPECT_STREQ("789", c.c_str());
    EXPECT_STREQ("885482", d.c_str());
    EXPECT_STREQ("88642", e.c_str());
}

TEST(MultiplyStringsTestCase, Multiply)
{
    string a = multiply(string("789"), string("987"));
    string b = multiply(string("45"), string("0"));
    string c = multiply(string("0"), string("78"));
    string d = multiply(string("999"), string("9999"));

    cout << a << ", " << b << ", " << c << ", " << d << endl;

    EXPECT_STREQ("778743", a.c_str());
    EXPECT_STREQ("0", b.c_str());
    EXPECT_STREQ("0", c.c_str());
    EXPECT_STREQ("9989001", d.c_str());
}
