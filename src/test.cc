#include <gtest/gtest.h>

#include "./Controller/s21_controllerSmartCalc.h"
#include "./Model/s21_modelSmartCalc.cc"

TEST(test, create_SmartCalc_1) {
  const char *str = "1+2";
  long double result = 1 + 2;
  long double x = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_2) {
  const char *str = "20+x^2";
  long double x = 4;

  long double result = 20 + pow(4, 2);

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_3) {
  const char *str = "-80/200";
  long double x = 0;

  long double result = static_cast<long double>(-80) / 200;

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_4) {
  const char *str = "-80*(+20)";
  long double x = 0;

  long double result = -80 * (+20);

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_5) {
  const char *str = "60mod5";
  long double x = 0;

  long double result = 60 % 5;

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_6) {
  const char *str = "sin(4)";
  long double x = 0;

  long double result = sin(4);

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_7) {
  const char *str = "cos(-2)";
  long double x = 0;

  long double result = cos(-2);

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_8) {
  const char *str = "cos(-2))";
  long double x = 0;

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
}

TEST(test, create_SmartCalc_9) {
  const char *str = "cos((-2)";
  long double x = 0;

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
}

TEST(test, create_SmartCalc_10) {
  const char *str = "76587-----";
  long double x = 0;

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
}

TEST(test, create_SmartCalc_11) {
  const char *str = "*6-2";
  long double x = 0;

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
}

TEST(test, create_SmartCalc_12) {
  const char *str = "20(7/2/";
  long double x = 0;

  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
}

TEST(test, create_SmartCalc_13) {
  const char *str = "30 + (4 * (200 + 1) / 2) - 100 * asin(1)";
  long double x = 0;

  long double result = 30 + (4 * (200 + 1) / 2) - 100 * asin(1);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_14) {
  const char *str = "8.3+3.8^2";
  long double x = 0;

  long double result = 8.3 + powl(3.8, 2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_15) {
  const char *str = "atan(3)";
  long double x = 0;

  long double result = atan(3);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_16) {
  const char *str = "tan(3)";
  long double x = 0;

  long double result = tan(3);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_17) {
  const char *str = "sqrt(20)";
  long double x = 0;

  long double result = sqrt(20);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_20) {
  const char *str = "log(5)-ln(2)";
  long double x = 0;

  long double result = log10(5) - log(2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_18) {
  const char *str = "log(5)";
  long double x = 0;

  long double result = log10(5);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_19) {
  const char *str = "ln(2)";
  long double x = 0;

  long double result = log(2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_21) {
  const char *str = "60.23/59-294*(87-(-5.34))*2.1";
  long double x = 0;

  long double result = 60.23 / 59 - 294 * (+87 - (-5.34)) * 2.1;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_22) {
  const char *str = "+x-7+(-30)*(-x)--x+x++x";
  long double x = 6;

  long double result = (+6) - 7 + (-30) * (-6) - (-6) + 6 + (+6);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_23) {
  const char *str = "acos(1)";
  long double x = 0;

  long double result = acos(1);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_24) {
  const char *str = "3 + 22 - (5 + 89) * 1";
  long double x = 0;

  long double result = 3 + 22 - (5 + 89) * 1;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_25) {
  const char *str = "i";
  long double x = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
}

TEST(test, create_SmartCalc_26) {
  const char *str = nullptr;
  long double x = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, 0);
}

TEST(test, create_SmartCalc_27) {
  const char *str = "8 + 2 i";
  long double x = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
}

TEST(test, create_SmartCalc_28) {
  const char *str = "8965 - 22 + (75 * 1) / 2 + 10^3 - -77 + +2";
  long double x = 0;

  long double result = 10059.5;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_29) {
  const char *str =
      "888 - 333333 / 75 + 22 + (-6543) + (654-98765*6543+(8765-543))";
  long double x = 0;

  long double result = -646220596.44000006;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_30) {
  const char *str = "+3 - -1 + -5 + 765 * -2";
  long double x = 0;

  long double result = +3 - -1 + -5 + 765 * -2;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_33) {
  const char *str = "cos(2^2)-sin(2^2^2)+cos(2)^2";
  long double x = 0;

  long double result = cosl(4) - sinl(16) + pow(cosl(2), 2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_34) {
  const char *str = "-5 - -4 + 30 - 2 - 38";
  long double x = 0;

  long double result = -5 - -4 + 30 - 2 - 38;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_35) {
  const char *str = "7--7-3--2-1-2--3-4--7";
  long double x = 0;

  long double result = 7 - -7 - 3 - -2 - 1 - 2 - -3 - 4 - -7;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_36) {
  const char *str = "10 - 20 + (-49) + 2 + (+3)";
  long double x = 0;

  long double result = 10 - 20 + (-49) + 2 + (+3);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_37) {
  const char *str = "(-100)^(2+3)";
  long double x = 0;

  long double result = powl(-100, 5);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_38) {
  const char *str = "50";
  long double x = 0;

  long double result = 50;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_39) {
  const char *str = "tan(39) - 100 / 10 * 6";
  long double x = 0;

  long double result = tan(39) - 100 / 10 * 6;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_40) {
  const char *str = "0^20 + 2 + 1";
  long double x = 0;

  long double result = pow(0, 20) + 2 + 1;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_41) {
  const char *str = "(1.2^3^2)^2^2";
  long double x = 0;

  long double result = 708.8018749850919;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_42) {
  const char *str = " - 13758 * 1 - +5";
  long double x = 0;

  long double result = -13758 * 1 - +5;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_44) {
  const char *str = "log(10)";
  long double x = 0;

  long double result = log10l(10);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_45) {
  const char *str = "(log(10))^2";
  long double x = 0;

  long double result = pow(log10l(10), 2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_46) {
  const char *str = "(log(10^2^2))";
  long double x = 0;

  long double result = log10l(pow(pow(10, 2), 2));
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_47) {
  const char *str = "0";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_48) {
  const char *str = "+47-22mod3*1";
  long double x = 0;

  long double result = +47 - 22 % 3 * 1;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_49) {
  const char *str = "2(1+2)";
  long double x = 0;

  long double result = 2 * (1 + 2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_50) {
  const char *str = "(1+2)2";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_51) {
  const char *str = "(1+2)2()";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_52) {
  const char *str = "(1+2)2(";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_54) {
  const char *str = "()";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_55) {
  const char *str = "2cos()";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_56) {
  const char *str = "cos()2";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_57) {
  const char *str = "2log(6)";
  long double x = 0;

  long double result = 2 * log10l(6);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_58) {
  const char *str = "log(6)2";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_59) {
  const char *str = "////";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_60) {
  const char *str = "cos(+)";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_61) {
  const char *str = "cos(";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_62) {
  const char *str = "mod(4)";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_63) {
  const char *str = "mod(";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_64) {
  const char *str = "8mod(4)";
  long double x = 0;

  long double result = 8 % 4;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_65) {
  const char *str = "4mod";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_66) {
  const char *str = "4/2 (1+3)";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_67) {
  const char *str = "4 cos(2)";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_68) {
  const char *str = "4cos(2)";
  long double x = 0;

  long double result = 4 * cosl(2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_69) {
  const char *str = "cos(2)4";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_70) {
  const char *str = "(1+3)5";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_71) {
  const char *str = "5(1+3)";
  long double x = 0;

  long double result = 5 * (1 + 3);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_72) {
  const char *str = "cos(2)";
  long double x = 0;

  long double result = cosl(2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_73) {
  const char *str = "acos(1)";
  long double x = 0;

  long double result = acosl(1);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_74) {
  const char *str = "sin(6)";
  long double x = 0;

  long double result = sinl(6);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_75) {
  const char *str = "asin(1)";
  long double x = 0;

  long double result = asinl(1);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_EQ(Myresult, result);
}

TEST(test, create_SmartCalc_76) {
  const char *str = "tan(2)";
  long double x = 0;

  long double result = tanl(2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_77) {
  const char *str = "atan(2)";
  long double x = 0;

  long double result = atan(2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_78) {
  const char *str = "log(2)";
  long double x = 0;

  long double result = log10l(2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_79) {
  const char *str = "ln(5)";
  long double x = 0;

  long double result = log(5);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_80) {
  const char *str = "sqrt(2)";
  long double x = 0;

  long double result = sqrtl(2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_81) {
  const char *str =
      "cos(2) - acos(1) + sin(6) / asin(1) - tan(2) + atan(1) - log(2) - ln(5) "
      "* sqrt(1)";
  long double x = 0;

  long double result = cosl(2) - acosl(1) + sinl(6) / asinl(1) - tanl(2) +
                       atanl(1) - log10l(2) - log(5) * sqrtl(1);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_82) {
  const char *str = "sqrtl(1)";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_83) {
  const char *str = "fevgea";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_84) {
  const char *str = "сosl(2)";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_85) {
  const char *str = "cos(2)4";
  long double x = 0;

  long double result = 0;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 1);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_86) {
  const char *str = "(1+2)^2";
  long double x = 0;

  long double result = pow(3, 2);
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_87) {
  const char *str = "-4 - -4";
  long double x = 0;

  long double result = -4 - -4;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_88) {
  const char *str = "-4--4";
  long double x = 0;

  long double result = -4 - -4;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_89) {
  const char *str = "-4+-4";
  long double x = 0;

  long double result = -4 + -4;
  s21::SmartCalc newSmartCalc;
  newSmartCalc.GetInput(str, x);
  long double Myresult = newSmartCalc.GetResult();
  int error = newSmartCalc.GetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_90) {
  const char *str = "-4+-4";
  long double x = 0;

  long double result = -4 + -4;
  s21::SmartCalcController newSmartCalc;
  newSmartCalc.processGetInput(str, x);
  long double Myresult = newSmartCalc.processGetResult();
  int error = newSmartCalc.processGetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_91) {
  const char *str = "-4 + -3 - -4 * cos(1)";
  long double x = 0;

  long double result = -4 + -3 - -4 * cosl(1);
  s21::SmartCalcController newSmartCalc;
  newSmartCalc.processGetInput(str, x);
  long double Myresult = newSmartCalc.processGetResult();
  int error = newSmartCalc.processGetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_92) {
  const char *str = "3.2 - 4";
  long double x = 0;

  long double result = 3.2 - 4;
  s21::SmartCalcController newSmartCalc;
  newSmartCalc.processGetInput(str, x);
  long double Myresult = newSmartCalc.processGetResult();
  int error = newSmartCalc.processGetError();
  EXPECT_EQ(error, 0);
  EXPECT_NEAR(Myresult, result, 1e-6);
}

TEST(test, create_SmartCalc_93) {
  s21::SmartCalcController newSmartCalc;
  newSmartCalc.processDifferentiatedPayment(1000000, 12, 3);
  newSmartCalc.processInputAnnuityPayment(1000000, 12, 3);
}

TEST(test, create_SmartCalc_94) {
  s21::DifferentiatedPaymentCalc newSmartCalc;
  newSmartCalc.GetInput(1000000, 12, 3);
  newSmartCalc.GetMonthlyPayment();
  newSmartCalc.GetOverpayment();
  newSmartCalc.GetTotalPayment();
}

TEST(test, create_SmartCalc_95) {
  s21::AnnuityPaymentCalc newSmartCalc;
  newSmartCalc.GetInput(1000000, 12, 3);
  newSmartCalc.GetMonthlyPayment();
  newSmartCalc.GetOverpayment();
  newSmartCalc.GetTotalPayment();
}

TEST(test, create_SmartCalc_96) {
  s21::SmartCalcController newSmartCalc;
  newSmartCalc.processInputAnnuityPayment(1000000, 12, 3);
  newSmartCalc.processAnnuityGetTotalPayment();
  newSmartCalc.processAnnuityGetMonthlyPayment();
  newSmartCalc.processAnnuityGetOverpayment();
}

TEST(test, create_SmartCalc_97) {
  s21::SmartCalcController newSmartCalc;
  newSmartCalc.processDifferentiatedPayment(1000000, 12, 3);
  newSmartCalc.processDifferentiatedGetTotalPayment();
  newSmartCalc.processDifferentiatedGetMonthlyPayment();
  newSmartCalc.processDifferentiatedGetOverpayment();
  newSmartCalc.processClearError();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
