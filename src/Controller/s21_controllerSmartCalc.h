#ifndef SRC_CONTROLLER_S21CONTROLLERSMARTCALC
#define SRC_CONTROLLER_S21CONTROLLERSMARTCALC

#include <memory>

#include "../Model/s21_modelSmartCalc.h"

namespace s21 {

class SmartCalcController {
 public:
  SmartCalcController()
      : calculator(std::make_unique<SmartCalc>()),
        Differentiated(std::make_unique<DifferentiatedPaymentCalc>()),
        Annuity(std::make_unique<AnnuityPaymentCalc>()) {}

  void processGetInput(const char* string, long double x_Num) {
    if (calculator) calculator->GetInput(string, x_Num);
  }

  long double processGetResult() const {
    return (calculator) ? calculator->GetResult() : 0;
  }

  int processGetError() const {
    return (calculator) ? calculator->GetError() : 0;
  }

  void processClearError() const { calculator->clearError(); }

  void processInputAnnuityPayment(long double summ, long double time,
                                  long double rate) {
    if (Annuity) Annuity->GetInput(summ, time, rate);
  }

  double processAnnuityGetTotalPayment() const {
    return (Annuity) ? Annuity->GetTotalPayment() : 0;
  }

  double processAnnuityGetMonthlyPayment() const {
    return (Annuity) ? Annuity->GetMonthlyPayment() : 0;
  }

  double processAnnuityGetOverpayment() const {
    return (Annuity) ? Annuity->GetOverpayment() : 0;
  }

  void processDifferentiatedPayment(long double summ, long double time,
                                    long double rate) {
    if (Differentiated) Differentiated->GetInput(summ, time, rate);
  }

  double processDifferentiatedGetTotalPayment() const {
    return (Differentiated) ? Differentiated->GetTotalPayment() : 0;
  }

  double processDifferentiatedGetMonthlyPayment() const {
    return (Differentiated) ? Differentiated->GetMonthlyPayment() : 0;
  }

  double processDifferentiatedGetOverpayment() const {
    return (Differentiated) ? Differentiated->GetOverpayment() : 0;
  }

 private:
  std::unique_ptr<SmartCalc> calculator;
  std::unique_ptr<DifferentiatedPaymentCalc> Differentiated;
  std::unique_ptr<AnnuityPaymentCalc> Annuity;
};

}  // namespace s21

#endif
