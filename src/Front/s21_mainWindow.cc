#include "s21_mainWindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui_(new Ui::MainWindow),
      loan_amount_validator_(-100000000, 100000000, 7, this),
      mySmarCalc_(new s21::SmartCalcController) {
  ui_->setupUi(this);
  graph_ = new graphwindow;
  credit_ = new creditwindow;

  QLocale locale(QLocale::English);
  loan_amount_validator_.setNotation(QDoubleValidator::StandardNotation);
  loan_amount_validator_.setLocale(locale);
  loan_amount_validator_.setDecimals(15);
  ui_->label_2->setValidator(&loan_amount_validator_);

  connect(ui_->pushButton_e, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_x, &QPushButton::clicked, this, &MainWindow::digitsX);
  connect(ui_->pushButton_x, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_0, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_1, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_2, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_3, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_4, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_5, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_6, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_7, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_8, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_9, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_divide, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_multiply, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_minus, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_plus, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_point, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_degree, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_bracket1, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_bracket2, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_sin, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_asin, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_cos, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_acos, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_tan, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_atan, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_sqrtl, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_mod, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_log, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_ln, &QPushButton::clicked, this,
          &MainWindow::digitsNumbers);
  connect(ui_->pushButton_19, &QPushButton::clicked, this,
          &MainWindow::digitsPrint);
  connect(ui_->pushButton_20, &QPushButton::clicked, this,
          &MainWindow::openCreditWindow);
  connect(ui_->pushButton_chart, &QPushButton::clicked, this,
          &MainWindow::openChartWindow);
  connect(ui_->pushButton_11, &QPushButton::clicked, this,
          &MainWindow::clearLabel);
  connect(ui_->pushButton_ac, &QPushButton::clicked, this,
          &MainWindow::removeLastCharacter);
  connect(ui_->pushButton_equals, &QPushButton::clicked, this,
          &MainWindow::performCalculations);
}

MainWindow::~MainWindow() {
  delete graph_;
  delete credit_;
  delete ui_;
  delete mySmarCalc_;
}

void MainWindow::digitsPrint() {
  QString result = "┐(‘～` )┌ in the pipeline";
  ui_->label->setText(result);
}

void MainWindow::digitsX() {
  QPushButton *button = (QPushButton *)sender();
  QString string = ui_->label_2->text() + button->text();
  X_ = strtold(string.toLatin1().data(), NULL);
}

void MainWindow::digitsNumbers() {
  QPushButton *button = (QPushButton *)sender();
  str_ = ui_->label->text() + button->text();
  ui_->label->setText(str_);
}

void MainWindow::performCalculations() {
  long double num;
  QByteArray text = str_.toLocal8Bit();
  const char *string = text.data();

  mySmarCalc_->processGetInput(string, X_);
  if (mySmarCalc_->processGetError() != 1) {
    num = mySmarCalc_->processGetResult();
    QString result = QString::number(num, 'g', 15);
    ui_->label->setText(result);
  } else {
    QString result = "ଘ(੭ˊ꒳​ˋ)੭✧ERROR✧";
    ui_->label->setText(result);
    delete mySmarCalc_;
    mySmarCalc_ = new s21::SmartCalcController;
  }
}

void MainWindow::removeLastCharacter() {
  QString res = ui_->label->text();
  res.chop(1);
  ui_->label->setText(res);
}

void MainWindow::clearLabel() {
  QString res = "";
  ui_->label->setText(res);
}

void MainWindow::openChartWindow() {
  QString text = ui_->label->text();
  connect(this, SIGNAL(PathlineSignal(QString)), graph_,
          SIGNAL(PathlineSignal(QString)));
  emit PathlineSignal(text);
  graph_->show();
}

void MainWindow::openCreditWindow() { credit_->show(); }
