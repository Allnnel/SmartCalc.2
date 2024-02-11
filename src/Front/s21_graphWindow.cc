#include "s21_graphWindow.h"

#include "ui_graphWindow.h"

graphwindow::graphwindow(QWidget *parent)
    : QDialog(parent), ui_(new Ui::graphwindow) {
  ui_->setupUi(this);
  connect(this, SIGNAL(PathlineSignal(QString)), this,
          SLOT(sloatPathSignal(QString)));
  newSmartCalc_ = new s21::SmartCalcController;
}

graphwindow::~graphwindow() {
  delete ui_;
  delete newSmartCalc_;
}

void graphwindow::sloatPathSignal(QString text) {
  QByteArray ba = text.toLocal8Bit();
  line_res_ = ba.data();
  ui_->widget->clearGraphs();
  WidgetGraph();
}

void graphwindow::WidgetGraph() {
  QVector<double> x, y;
  double h = 0.1;
  double xBegin = -10;
  double xEnd = 10;
  y.clear();
  x.clear();
  QPen my_pen;
  my_pen.setColor(QColor(255, 192, 203));
  my_pen.setWidthF(2);
  int N = (xEnd - xBegin) / h + 2;
  if (N > 1000000) N = 1000000;
  for (long double X = xBegin; X <= xEnd; X += h) {
    long double x_calc = 0;
    newSmartCalc_->processGetInput(line_res_, X);
    x_calc = newSmartCalc_->processGetResult();

    x.push_back(static_cast<double>(X));
    y.push_back(static_cast<double>(x_calc));
  }

  ui_->widget->addGraph();
  ui_->widget->graph(0)->setData(x, y);
  ui_->widget->graph(0)->setPen(my_pen);
  ui_->widget->graph(0)->setAdaptiveSampling(false);
  ui_->widget->setInteraction(QCP::iRangeZoom, true);
  ui_->widget->setInteraction(QCP::iRangeDrag, true);
  ui_->widget->replot();
}
