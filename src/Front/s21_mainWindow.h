// mainwindow.h
#ifndef SRC_FRONT_S21MAINWINDOW_
#define SRC_FRONT_S21MAINWINDOW_

#include <QDoubleValidator>
#include <QMainWindow>

#include "s21_creditWindow.h"
#include "s21_graphWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void digitsX();
  void digitsNumbers();
  void digitsPrint();
  void performCalculations();
  void openCreditWindow();
  void openChartWindow();
  void clearLabel();
  void removeLastCharacter();

 signals:
  void PathlineSignal(const QString &text);

 private:
  Ui::MainWindow *ui_;
  QDoubleValidator loan_amount_validator_;
  graphwindow *graph_;
  creditwindow *credit_;
  long double X_;
  QString str_;
  s21::SmartCalcController *mySmarCalc_;
};

#endif  // MAINWINDOW_H
