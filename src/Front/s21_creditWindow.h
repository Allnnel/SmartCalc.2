#ifndef SRC_FRONT_S21CREDITWINDOW_
#define SRC_FRONT_S21CREDITWINDOW_
#pragma once
#include <../Controller/s21_controllerSmartCalc.h>

#include <QDialog>
#include <QDoubleValidator>

namespace Ui {
class creditwindow;
}

class creditwindow : public QDialog {
  Q_OBJECT

 public:
  explicit creditwindow(QWidget *parent = nullptr);
  ~creditwindow();

 private:
  Ui::creditwindow *ui_;
  QDoubleValidator loan_amount_validator_;
  s21::SmartCalcController *newSmartCalc_;

 signals:
  void mainWindow();

 private slots:
  void annuityPayment();
  void differentiatedPayment();
};

#endif  // CREDITWINDOW_H
