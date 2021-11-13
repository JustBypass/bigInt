//
// Created by Admin on 20.10.2021.
//
#include "gtest/gtest.h"
#include "../Dynamic/bigInt.h"

//#include  "../TestLib/TestLib.hpp"

TEST(BigInt_t, Throw_incorrect_string_and_argument) {
    EXPECT_ANY_THROW(bigInt(54)+"gt4");
    EXPECT_ANY_THROW(bigInt("543frf"));
    EXPECT_ANY_THROW(bigInt(54) += "gt4");
    EXPECT_ANY_THROW(bigInt(54) -= "gt4");
    EXPECT_ANY_THROW(bigInt(54) - "gt4");
    EXPECT_ANY_THROW(bigInt(54) >>-1321);
    EXPECT_ANY_THROW(bigInt(54) << -1321);
}
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
    a + 6;
    6 + a;
    EXPECT_STREQ(to_str(bigInt(a+b)),"0");
}
TEST(bigInt_t, MinusOperator_1)
{
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
    myVector _v(5);
    bigInt _num("4325");
    do_external(4, _num, _v);
    char* _str = new char(6);
    int i = 0;
    while(_v._size!=0)
    {
         _str[i++] = _v.pop_back();
            std::cout<<_str[i-1];
    }
    _str[i] = '\0';
    ASSERT_STREQ("04325", _str);
}
TEST(bigInt_t, externalPositiveCode_t) {
    myVector _v(5);
    bigInt _num("-4325");
    do_external(4, _num, _v);
    char* _str = new char(6);
    int i = 0;
    while (_v._size != 0)
    {
         _str[i++] = _v.pop_back();
    }
    _str[i] = '\0';
    ASSERT_STREQ("95675", _str);
}
TEST(myVector, push_back_t) {
    myVector a(5);
    a.push_back('0');
    EXPECT_EQ(1,a._size);
}
TEST(bigInt_t, Increment_plus)
{
    EXPECT_STREQ(to_str(bigInt(++bigInt(0))),"1");
}
TEST(bigInt_t, PlusEqual)
{
    EXPECT_STREQ(to_str((bigInt(0)+=7)), "7");
}
TEST(bigInt_t, MinusEqual)
{
    EXPECT_STREQ(to_str((bigInt(0)-=7)),"-7");
}
TEST(bigInt_t, MinusEqual2)
{
    EXPECT_STREQ(to_str(bigInt("0")-="7"),"-7");
}
TEST(bigInt_t,PlusDecr2)
{
    bigInt a(0);
    EXPECT_STREQ(to_str(a++),"0");
    EXPECT_STREQ(to_str(a),"1");
}
TEST(bigInt_t,PlusDecr)
{
    bigInt a(0);
    bigInt c = ++a;
    EXPECT_STREQ(to_str(bigInt(c)),"1");
    EXPECT_STREQ(to_str(bigInt(a)),"1");
}
TEST(bigInt_t, OtherOperations)
{
    EXPECT_STREQ(to_str(bigInt("1")-7-76578877687687+"1"),"-76578877687692");
    EXPECT_STREQ(to_str(bigInt("1")-7-76578877687687+bigInt("1")),"-76578877687692");
    EXPECT_STREQ(to_str(bigInt("1")-=76578877687687),"-76578877687686");
    EXPECT_STREQ(to_str(3+bigInt("1")-=76578877687687),"-76578877687683");
    EXPECT_STREQ(to_str("3"+bigInt("1")-=76578877687687),"-76578877687683");
}
TEST(Operator,Move){
    bigInt a(0);
    bigInt b(8);
    char* test = b.get_digit();
    a = std::move(b);
    EXPECT_STREQ(b.get_digit(),nullptr);
    EXPECT_STREQ(test,a.get_digit());
}
TEST(Operator,Copy){
    bigInt a(0);
    bigInt b(8);
    char* test = b.get_digit();
    a = b;
    EXPECT_STREQ(b.get_digit(),a.get_digit());
    EXPECT_STREQ(test,b.get_digit());
}
TEST(Constructor,Move){
    bigInt b(8);
    char* test = b.get_digit();
    bigInt a(std::move(b));
    EXPECT_STREQ(b.get_digit(),nullptr);
    EXPECT_STREQ(test,a.get_digit());
}
TEST(Constructor,Copy){
    bigInt b(8);
    char* test = b.get_digit();
    bigInt a(b);
    EXPECT_STREQ(b.get_digit(),a.get_digit());
    EXPECT_STREQ(test,b.get_digit());
}
TEST(Operator,Move1){
    bigInt a("0");
    bigInt b("8");
    char* test = b.get_digit();
    a = std::move(b);
    EXPECT_STREQ(b.get_digit(),nullptr);
    EXPECT_STREQ(test,a.get_digit());
}
TEST(Operator,Copy1){
    bigInt a("0");
    bigInt b("8");
    char* test = b.get_digit();
    a = b;
    EXPECT_STREQ(b.get_digit(),a.get_digit());
    EXPECT_STREQ(test,b.get_digit());
}
TEST(Constructor,Move2){
    bigInt b("6");
    char* test = b.get_digit();
    bigInt a(std::move(b));
    EXPECT_STREQ(b.get_digit(),nullptr);
    EXPECT_STREQ(test,a.get_digit());
}
TEST(Constructor,Copy2){
    bigInt b("3");
    char* test = b.get_digit();
    bigInt a(b);
    EXPECT_STREQ(b.get_digit(),a.get_digit());
    EXPECT_STREQ(test,b.get_digit());
}
TEST(BigInt_t,Shift_L){
    bigInt a(4);
    a>>=0;
    EXPECT_STREQ(to_str(a),"4");
}
TEST(BigInt_t,Shift_R){
    bigInt a(4);
    a<<=0;
    EXPECT_STREQ(to_str(a),"4");
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}