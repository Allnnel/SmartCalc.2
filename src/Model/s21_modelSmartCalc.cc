#include "s21_modelSmartCalc.h"
s21::SmartCalc::SmartCalc()
    : error_(0), countBrackets_(0), x_(0), result_(0), str_(nullptr) {}

void s21::SmartCalc::GetInput(const char* string, long double x) {
  Input(string, x);
}
int s21::SmartCalc::GetError() { return error_; }

long double s21::SmartCalc::GetResult() { return result_; }

void s21::SmartCalc::clearError() { error_ = 0, result_ = 0; }

void s21::SmartCalc::Input(const char* string, long double xNum) {
  if (string != nullptr) {
    str_ = string, x_ = xNum;
    Parser();
    if (error_ == 0) result_ = Result();
    if (((!stackSign_.empty()) || (!stackNum_.empty())) || error_ == 1 ||
        countBrackets_ != 0) {
      error_ = 1, result_ = 0;
    }
    stackSign_ = std::stack<char>();
    stackNum_ = std::stack<long double>();
  }
}

long double s21::SmartCalc::Result() {
  long double res = 0;
  while (!stackSign_.empty() && !stackNum_.empty()) ArithmeticOperators();

  if (!stackNum_.empty() && stackSign_.empty()) {
    res = stackNum_.top();
    stackNum_.pop();
  }
  return res;
}

void s21::SmartCalc::Parser() {
  while (*str_ != '\0' && error_ == 0) {
    if (*str_ == ' ') {
      str_++;
      continue;
    } else if ((*str_ >= '0' && *str_ <= '9') || *str_ == 'x')
      NumberProcessing();
    else if (Priority(*str_) != -1)
      OperatorProcessing();
    else if (*str_ == ')' && *(str_ - 1) != '(')
      BraceProcessing();
    else
      error_ = 1;
    str_++;
  }
}

void s21::SmartCalc::BraceProcessing() {
  SignNegative();
  countBrackets_ -= 1;
  if (countBrackets_ >= 0)
    while (!stackSign_.empty() && !stackNum_.empty() &&
           Priority(stackSign_.top()) != 0)
      ArithmeticOperators();
  if (!stackSign_.empty() && !stackNum_.empty()) stackSign_.pop();
}

void s21::SmartCalc::NumberProcessing() {
  if (*str_ != 'x') {
    char* endPtr;
    stackNum_.push(std::strtold(str_, &endPtr));
    str_ = --endPtr;
  } else
    stackNum_.push(x_);

  if (!stackSign_.empty() &&
      (stackSign_.top() == '~' || stackSign_.top() == '!')) {
    if (stackSign_.top() == '~') stackNum_.top() = -stackNum_.top();
    stackSign_.pop();
  }
  if (*(str_ + 1) == '(') stackSign_.push('*');
}

void s21::SmartCalc::OperatorProcessing() {
  char op = SignNegative();
  if (op == '(') countBrackets_ += 1;
  if (!stackSign_.empty() && !stackNum_.empty() &&
      Priority(stackSign_.top()) == 2 && op == '^' &&
      (*(str_ + 1) == '\0' || *(str_ + 2) == ')' || *(str_ + 1) != '^'))
    ArithmeticOperators();

  while (!stackSign_.empty() && !stackNum_.empty() &&
         (Priority(stackSign_.top()) | Priority(op)) != 1) {
    if (Priority(stackSign_.top()) == 0 ||
        Priority(stackSign_.top()) > Priority(op))
      break;
    ArithmeticOperators();
  }
  stackSign_.push(op);
}

int s21::SmartCalc::Priority(char str_) {
  int priority = 0;
  if (str_ == '+' || str_ == '-')
    priority = 4;
  else if (str_ == '*' || str_ == '/' || str_ == '%')
    priority = 3;
  else if (strchr("cCsStTlmqna", str_) != nullptr)
    priority = 2;
  else if (str_ == '^')
    priority = 1;
  else if (str_ == '(')
    priority = 0;
  else
    priority = -1;
  return priority;
}

void s21::SmartCalc::ArithmeticOperators() {
  long double result = 0;
  if (strchr("cCsStTnql", stackSign_.top()) != nullptr) {
    long double oneNum = stackNum_.top();
    stackNum_.pop();
    result = TrigonometricOptions(oneNum);
  } else if (stackNum_.size() >= 2) {
    long double twoNum = stackNum_.top();
    stackNum_.pop();
    long double oneNum = stackNum_.top();
    stackNum_.pop();
    result = OperatorsResult(stackSign_.top(), oneNum, twoNum);
  }
  stackSign_.pop();
  stackNum_.push(result);
}

long double s21::SmartCalc::OperatorsResult(char sign, long double numOne,
                                            long double numTwo) {
  long double result = 0;
  switch (sign) {
    case '+':
      result = numOne + numTwo;
      break;
    case '-':
      result = numOne - numTwo;
      break;
    case '*':
      result = numOne * numTwo;
      break;
    case '/':
      result = numOne / numTwo;
      break;
    case '^':
      result = std::pow(numOne, numTwo);
      break;
    case 'm':
      result = std::fmod(numOne, numTwo);
      break;
    default:
      error_ = 1;
      break;
  }
  return result;
}

char s21::SmartCalc::SignNegative() {
  char op = NameOption();
  if ((op == '-' || op == '+') &&
      (stackNum_.empty() ||
       (((*(str_ + 1) >= '0' && *(str_ + 1) <= '9') || *(str_ + 1) == 'x') &&
        !((*(str_ - 1) >= '0' && *(str_ - 1) <= '9') || *(str_ - 1) == 'x' ||
          *(str_ - 1) == ')')))) {
    op = (op == '-') ? '~' : '!';
  }
  return op;
}

char s21::SmartCalc::NameOption() {
  char name = *str_;
  if (strchr("cstalm", *str_) != nullptr) {
    if (*(str_ - 1) >= '0' && *(str_ - 1) <= '9' && *str_ != 'm')
      stackSign_.push('*');
    int num = 2;
    if (strncmp(str_, "ln", num) == 0)
      name = 'n';
    else if (strncmp(str_, "sin", ++num) == 0)
      name = 's';
    else if (strncmp(str_, "cos", num) == 0)
      name = 'c';
    else if (strncmp(str_, "tan", num) == 0)
      name = 't';
    else if (strncmp(str_, "log", num) == 0)
      name = 'l';
    else if (strncmp(str_, "mod", num) == 0)
      name = 'm';
    else if (strncmp(str_, "sqrt", ++num) == 0)
      name = 'q';
    else if (strncmp(str_, "asin", num) == 0)
      name = 'S';
    else if (strncmp(str_, "atan", num) == 0)
      name = 'T';
    else if (strncmp(str_, "acos", num) == 0)
      name = 'C';
    str_ += (num - 1);
    if (*str_ != 'd' && *(str_ + 1) != '(') error_ = 1;
  }
  return name;
}

long double s21::SmartCalc::TrigonometricOptions(long double oneNum) {
  long double result = 0;
  if (!stackSign_.empty()) {
    switch (stackSign_.top()) {
      case 'c':
        result = cosl(oneNum);
        break;
      case 'C':
        result = acosl(oneNum);
        break;
      case 's':
        result = sinl(oneNum);
        break;
      case 'S':
        result = asinl(oneNum);
        break;
      case 't':
        result = tanl(oneNum);
        break;
      case 'T':
        result = atanl(oneNum);
        break;
      case 'n':
        result = logl(oneNum);
        break;
      case 'l':
        result = log10l(oneNum);
        break;
      case 'q':
        result = sqrtl(oneNum);
        break;
    }
  }
  return result;
}

s21::AnnuityPaymentCalc::AnnuityPaymentCalc()
    : totalPayment_(0), overpayment_(0), monthlyPayment_(0) {}

void s21::AnnuityPaymentCalc::GetInput(long double summ, long double time,
                                       long double rate) {
  AnnuityPayment(summ, time, rate);
}
double s21::AnnuityPaymentCalc::GetTotalPayment() { return totalPayment_; }
double s21::AnnuityPaymentCalc::GetMonthlyPayment() { return monthlyPayment_; }
double s21::AnnuityPaymentCalc::GetOverpayment() { return overpayment_; }

void s21::AnnuityPaymentCalc::AnnuityPayment(long double summ, long double time,
                                             long double rate) {
  if (time > 0) {
    double p_procent = rate / 100 / 12;
    double payment_part = powl((1 + p_procent), time) - 1;
    monthlyPayment_ = summ * (p_procent + (p_procent / payment_part));
    totalPayment_ = monthlyPayment_ * time;
    overpayment_ = totalPayment_ - summ;
  }
}

s21::DifferentiatedPaymentCalc::DifferentiatedPaymentCalc()
    : totalPayment_(0), overpayment_(0), monthlyPayment_(0) {}

void s21::DifferentiatedPaymentCalc::GetInput(long double summ,
                                              long double time,
                                              long double rate) {
  DifferentiatedPayment(summ, time, rate);
}
double s21::DifferentiatedPaymentCalc::GetTotalPayment() {
  return totalPayment_;
}
double s21::DifferentiatedPaymentCalc::GetMonthlyPayment() {
  return monthlyPayment_;
}

double s21::DifferentiatedPaymentCalc::GetOverpayment() { return overpayment_; }

void s21::DifferentiatedPaymentCalc::DifferentiatedPayment(long double summ,
                                                           long double time,
                                                           long double rate) {
  if (time > 0) {
    double p_procent = rate / 100 / 12;
    monthlyPayment_ = summ / time + summ * p_procent;
    double sum_next = summ;
    for (int i = 1; i <= time; ++i) {
      double payment = summ / time + sum_next * p_procent;
      totalPayment_ += payment;
      sum_next = summ - i * summ / time;
    }
    overpayment_ = totalPayment_ - summ;
  }
}
