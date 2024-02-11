#include "s21_creditWindow.h"

#include "ui_creditwindow.h"

creditwindow::creditwindow(QWidget *parent)
    : QDialog(parent),
      ui_(new Ui::creditwindow),
      loan_amount_validator_(0, 100000000, 7, this),
      newSmartCalc_(new s21::SmartCalcController) {
  ui_->setupUi(this);

  QLocale locale(QLocale::English);
  loan_amount_validator_.setNotation(QDoubleValidator::StandardNotation);
  loan_amount_validator_.setLocale(locale);
  loan_amount_validator_.setDecimals(15);
  ui_->lineEdit->setValidator(&loan_amount_validator_);
  ui_->lineEdit_2->setValidator(&loan_amount_validator_);
  ui_->lineEdit_3->setValidator(&loan_amount_validator_);

  connect(ui_->pushButton_8, &QPushButton::clicked, this,
          &creditwindow::differentiatedPayment);
  connect(ui_->pushButton_9, &QPushButton::clicked, this,
          &creditwindow::annuityPayment);
}

creditwindow::~creditwindow() {
  delete ui_;
  delete newSmartCalc_;
}

void creditwindow::annuityPayment() {
  QString str_summ = ui_->lineEdit->text();
  QString str_time = ui_->lineEdit_2->text();
  QString str_rate = ui_->lineEdit_3->text();
  long double summ = strtold(str_summ.toLatin1().data(), NULL);
  long double time = strtold(str_time.toLatin1().data(), NULL);
  long double rate = strtold(str_rate.toLatin1().data(), NULL);

  newSmartCalc_->processInputAnnuityPayment(summ, time, rate);
  QString result_overpayment =
      QString::number(newSmartCalc_->processAnnuityGetOverpayment(), 'g', 15);
  QString result_ResultSumm =
      QString::number(newSmartCalc_->processAnnuityGetTotalPayment(), 'g', 15);
  QString result_MonthPayment = QString::number(
      newSmartCalc_->processAnnuityGetMonthlyPayment(), 'g', 15);
  ui_->label->setText(result_MonthPayment);
  ui_->label_2->setText(result_overpayment);
  ui_->label_3->setText(result_ResultSumm);
}

void creditwindow::differentiatedPayment() {
  QString str_summ = ui_->lineEdit->text();
  QString str_time = ui_->lineEdit_2->text();
  QString str_rate = ui_->lineEdit_3->text();
  long double summ = strtold(str_summ.toLatin1().data(), NULL);
  long double time = strtold(str_time.toLatin1().data(), NULL);
  long double rate = strtold(str_rate.toLatin1().data(), NULL);

  newSmartCalc_->processDifferentiatedPayment(summ, time, rate);

  QString result_overpayment = QString::number(
      newSmartCalc_->processDifferentiatedGetOverpayment(), 'g', 15);
  QString result_ResultSumm = QString::number(
      newSmartCalc_->processDifferentiatedGetTotalPayment(), 'g', 15);
  QString result_MonthPayment = QString::number(
      newSmartCalc_->processDifferentiatedGetMonthlyPayment(), 'g', 15);

  ui_->label->setText(result_MonthPayment);
  ui_->label_2->setText(result_overpayment);
  ui_->label_3->setText(result_ResultSumm);
}
