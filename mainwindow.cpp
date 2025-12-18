#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "converter.h"
#include "evaluator.h"
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect GUI buttons to slots
    connect(ui->btnConvertPostfix, &QPushButton::clicked, this, &MainWindow::onConvertPostfixClicked);
    connect(ui->btnConvertPrefix, &QPushButton::clicked, this, &MainWindow::onConvertPrefixClicked);
    connect(ui->btnEvaluate, &QPushButton::clicked, this, &MainWindow::onEvaluateClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Convert to Postfix
void MainWindow::onConvertPostfixClicked()
{
    QString expr = ui->lineEditExpression->text().trimmed();
    if(expr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an expression.");
        return;
    }

    try {
        std::string result = Converter::infixToPostfix(expr.toStdString());
        ui->lineEditResult->setText(QString::fromStdString(result));
        ui->textEditHistory->addItem("Postfix: " + QString::fromStdString(result));
    } catch(const std::exception &e) {
        QMessageBox::critical(this, "Conversion Error", e.what());
    }
}

// Convert to Prefix
void MainWindow::onConvertPrefixClicked()
{
    QString expr = ui->lineEditExpression->text().trimmed();
    if(expr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an expression.");
        return;
    }

    try {
        std::string result = Converter::infixToPrefix(expr.toStdString());
        ui->lineEditResult->setText(QString::fromStdString(result));
        ui->textEditHistory->addItem("Prefix: " + QString::fromStdString(result));
    } catch(const std::exception &e) {
        QMessageBox::critical(this, "Conversion Error", e.what());
    }
}

// Evaluate Expression (Postfix assumed)
void MainWindow::onEvaluateClicked()
{
    QString expr = ui->lineEditExpression->text().trimmed();
    if(expr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an expression.");
        return;
    }

    try {
        int value = Evaluator::evaluatePostfix(expr.toStdString());
        std::string result = std::to_string(value);
        ui->lineEditResult->setText(QString::fromStdString(result));
        ui->textEditHistory->addItem("Evaluated: " + QString::fromStdString(result));
    } catch(const std::exception &e) {
        QMessageBox::critical(this, "Evaluation Error", e.what());
    }
}
