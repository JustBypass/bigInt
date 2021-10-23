//
// Created by Admin on 22.10.2021.
//

#include "C:\Qt\Qt5.12.10\cmake_tur\library\bigInt.h"
#include "gtest/gtest.h"
//#include <string.h

TEST(bigInt_t, PlusOperator_1)//Do everything by the strings
{
    bigInt a("435");
    bigInt b("435");
    EXPECT_STREQ(to_str(bigInt(a+b)),"870");
}
TEST(bigInt_t, PlusOperator_2)
{
    bigInt a("435");
    bigInt b("-435");
    bigInt c("0");
    EXPECT_STREQ(to_str(bigInt(a+b)),"0");
}
TEST(bigInt_t, PlusOperator_3) {
    bigInt a("-435");
    bigInt b("-435");
    EXPECT_STREQ(to_str(bigInt(a+b)),"-870");
}

TEST(bigInt_t, PlusOperator_4) {
    bigInt a("-435");
    bigInt b("435");
    EXPECT_STREQ(to_str(bigInt(a+b)),"0");
}
TEST(bigInt_t, MinusOperator_1) {
    bigInt a("435");
    bigInt b("435");
    EXPECT_STREQ(to_str(bigInt(a-b)),"0");
}
TEST(bigInt_t, MinusOperator_2) {
    bigInt a("-435");
    bigInt b("435");
    EXPECT_STREQ(to_str(bigInt(a-b)),"-870");
}
TEST(bigInt_t, MinusOperator_3) {
    bigInt a("435");
    bigInt b("-435");
    bigInt c("870");
    EXPECT_STREQ(to_str(bigInt(a-b)),"870");
}
TEST(bigInt_t, MinusOperator_4) {
    bigInt a("-435");
    bigInt b("-435");
    EXPECT_STREQ(to_str(bigInt(a-b)),"0");
}
TEST(bigInt_t, ShiftR_t) {///Ошибка в знаке скорее всего
    bigInt _v("32");
    bigInt _n("3");
    EXPECT_STREQ(to_str(bigInt(_v>>1)) , "3");
}
TEST(bigInt_t, ShiftL_t)
{
    bigInt _v("32");
    bigInt _n("320");
    EXPECT_STREQ(to_str(bigInt(_v<<1)) , "320");
}
TEST(bigInt_t, ShiftZeroR_t) {///Ошибка в знаке скорее всего//Ошибка в strlen (\0 считает за число???)
    bigInt _v("0");
    bigInt _n("0");
    EXPECT_STREQ(to_str(bigInt(_v>>1)) , "0");
}
TEST(bigInt_t, intPlusStr) {
    bigInt _a(345);
    EXPECT_STREQ(to_str(bigInt(_a + "1")) , "346");

}
TEST(bigInt_t, longLongPlusStr) {
    bigInt _a((long long)345);
    bigInt _c("346");
    EXPECT_STREQ(to_str(bigInt(_a + "1")) , "346");
}
TEST(bigInt_t, externalNegativeCode_t) {
    myVector<char> _v(5);
    bigInt _num("4325");
    do_external(4, _num, _v);
    char* _str = new char(6);
    int i = 0;
    while(_v.size()!=0)
    {
    _str[i++] = _v.pop_back();
    }
    _str[i] = '\0';
    ASSERT_STREQ("04325", _str);
}
TEST(bigInt_t, externalPositiveCode_t) {
    myVector<char> _v(5);
    bigInt _num("-4325");
    do_external(4, _num, _v);
    char* _str = new char(6);
    int i = 0;
    while (_v.size() != 0) {
    _str[i++] = _v.pop_back();
    }
    _str[i] = '\0';
    ASSERT_STREQ("95675", _str);
}
TEST(myVector, push_back_t) {
    myVector<char> a(5);
    a.push_back('0');
    EXPECT_EQ(1,a.size());
}
TEST(bigInt_t, Increment_plus)
{
   // EXPECT_STREQ(to_str(const bigInt(++bigInt(0))),"1");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
