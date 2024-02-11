#ifndef SRC_FRONT_S21GRAPHWONDOW_
#define SRC_FRONT_S21GRAPHWONDOW_

#include <qcustomplot.h>
#pragma once
#include <../Controller/s21_controllerSmartCalc.h>

#include <QDialog>
#include <QVector>

namespace Ui {
class graphwindow;
}

class graphwindow : public QDialog {
  Q_OBJECT

 public:
  explicit graphwindow(QWidget *parent = nullptr);
  ~graphwindow();

 private:
  Ui::graphwindow *ui_;
  char *line_res_;
  s21::SmartCalcController *newSmartCalc_;

 signals:
  void mainWindow();
  void PathlineSignal(QString str);

 private slots:
  void sloatPathSignal(QString str);
  void WidgetGraph();
};

#endif
