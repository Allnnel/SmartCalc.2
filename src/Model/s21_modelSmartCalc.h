#ifndef SRC_MODEL_S21MODELSMARTCALC
#define SRC_MODEL_S21MODELSMARTCALC

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <vector>

namespace s21 {
class SmartCalc {
 private:
  int error_, countBrackets_;
  long double x_, result_;
  const char* str_;
  std::stack<char> stackSign_;
  std::stack<long double> stackNum_;

 public:
  SmartCalc();
  void GetInput(const char* string, long double x);
  int GetError();
  long double GetResult();
  void clearError();

 private:
  void Input(const char* string, long double xNum);
  long double Result();
  void Parser();
  void BraceProcessing();
  void NumberProcessing();
  void OperatorProcessing();
  int Priority(char str_);
  void ArithmeticOperators();
  long double OperatorsResult(char sign, long double numOne,
                              long double numTwo);
  char SignNegative();
  char NameOption();
  long double TrigonometricOptions(long double oneNum);
};

class AnnuityPaymentCalc {
 private:
  double totalPayment_, overpayment_, monthlyPayment_;

 public:
  AnnuityPaymentCalc();
  void GetInput(long double summ, long double time, long double rate);
  double GetTotalPayment();
  double GetMonthlyPayment();
  double GetOverpayment();

 private:
  void AnnuityPayment(long double summ, long double time, long double rate);
};

class DifferentiatedPaymentCalc {
 private:
  double totalPayment_, overpayment_, monthlyPayment_;

 public:
  DifferentiatedPaymentCalc();
  void GetInput(long double summ, long double time, long double rate);
  double GetTotalPayment();
  double GetMonthlyPayment();
  double GetOverpayment();

 private:
  void DifferentiatedPayment(long double summ, long double time,
                             long double rate);
};
}  // namespace s21

#endif
