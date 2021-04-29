#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mathlib.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <algorithm>
#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_A,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_B,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_C,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_D,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_E,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_F,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_Calc,SIGNAL(clicked()),this,SLOT(calculate()));

    connect(ui->pushButton_OpenBrac,SIGNAL(clicked()),this,SLOT(brackets()));
    connect(ui->pushButton_CloseBrac,SIGNAL(clicked()),this,SLOT(brackets()));

    connect(ui->pushButton_fact,SIGNAL(clicked()),this,SLOT(dot_fact()));
    connect(ui->pushButton_dot,SIGNAL(clicked()),this,SLOT(dot_fact()));

    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(ops()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(ops()));
    connect(ui->pushButton_sub,SIGNAL(clicked()),this,SLOT(ops()));
    connect(ui->pushButton_add,SIGNAL(clicked()),this,SLOT(ops()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(ops()));
    connect(ui->pushButton_pow,SIGNAL(clicked()),this,SLOT(ops()));
    connect(ui->pushButton_lg,SIGNAL(clicked()),this,SLOT(ops()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(ops()));

    connect(ui->pushButton_BS,SIGNAL(clicked()),this,SLOT(erase()));
    connect(ui->pushButton_AC,SIGNAL(clicked()),this,SLOT(erase()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_0)
        ui->pushButton_0->click();
    else if (event->key() == Qt::Key_1)
        ui->pushButton_1->click();
    else if (event->key() == Qt::Key_2)
        ui->pushButton_2->click();
    else if (event->key() == Qt::Key_3)
        ui->pushButton_3->click();
    else if (event->key() == Qt::Key_4)
        ui->pushButton_4->click();
    else if (event->key() == Qt::Key_5)
        ui->pushButton_5->click();
    else if (event->key() == Qt::Key_6)
        ui->pushButton_6->click();
    else if (event->key() == Qt::Key_7)
        ui->pushButton_7->click();
    else if (event->key() == Qt::Key_8)
        ui->pushButton_8->click();
    else if (event->key() == Qt::Key_9)
        ui->pushButton_9->click();
    else if (event->key() == Qt::Key_A)
        ui->pushButton_A->click();
    else if (event->key() == Qt::Key_B)
        ui->pushButton_B->click();
    else if (event->key() == Qt::Key_C)
        ui->pushButton_C->click();
    else if (event->key() == Qt::Key_D)
        ui->pushButton_D->click();
    else if (event->key() == Qt::Key_E)
        ui->pushButton_E->click();
    else if (event->key() == Qt::Key_F)
        ui->pushButton_F->click();
    else if (event->key() == Qt::Key_Backspace)
        ui->pushButton_BS->click();
    else if (event->key() == Qt::Key_Delete)
        ui->pushButton_AC->click();
    else if (event->key() == Qt::Key_Slash)
        ui->pushButton_div->click();
    else if (event->key() == Qt::Key_Minus)
        ui->pushButton_sub->click();
    else if (event->key() == Qt::Key_Plus)
        ui->pushButton_add->click();
    else if (event->key() == Qt::Key_Equal)
        ui->pushButton_Calc->click();

    return;
}

void MainWindow::calculate()
{
    std::string expression = ui->result_show->text().toStdString();
    size_t found = expression.find("√");
    while (found != std::string::npos)
    {
        expression.replace(found, 3, "sqrt");
        found = expression.find("√");
    }

    try{
        double result = Equation::solveEquation(expression,ui->spinBox->value());
        if(ui->spinBox->value() == 10){
            ui->result_show->setText(QString::number(result));
        }
        else{
            ui->result_show->setText(QString::fromUtf8(Translator::NumToStrWithBase(result,ui->spinBox->value())));
        }
    }
    catch(std::exception e){
        QMessageBox::warning(
            this,
            tr("Calculator"),
            tr("Rewrite equation!") );
    }

    return;
}

void MainWindow::erase()
{
    QPushButton *button = (QPushButton *)sender();

    std::string sqrt = "√";
    std::string expression = ui->result_show->text().toStdString();
    if (button->text() == "←")
    {
        if (expression[expression.length() - 1] == '(' &&
           (expression[expression.length() - 2] == 'g' || expression[expression.length() - 2] == 'n') &&
            expression[expression.length() - 3] == 'l' && expression.length() == 3)
            expression = "0";
        else if (expression[expression.length() - 1] == '(' &&
                (expression[expression.length() - 2] == 'g' || expression[expression.length() - 2] == 'n') &&
                 expression[expression.length() - 3] == 'l')
            expression.erase(expression.begin() + expression.length() - 3, expression.end());
        else if (expression.compare("√(") == 0)
            expression = "0";
        else if (expression.back() == sqrt.back())
            expression.erase(expression.length() - 3);
        else if (expression.length() > 1)
            expression.erase(expression.length() - 1);
        else
            expression = "0";
    }
    else if (button->text() == "AC")
        expression = "0";
    QString show_string = QString::fromStdString(expression);

    ui->result_show->setText(show_string);
    return;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    std::string str = ui->result_show->text().toStdString();
    if (str.length() == 1 && str.back() == '0')
    {
        ui->result_show->setText(button->text());
        return;
    }
    if (str.back() == '!' || str.back() == ')')
        return;
    std::string expression;
    QString show_string;
    expression = (ui->result_show->text() + button->text()).toStdString();
    show_string = QString::fromStdString(expression);
    ui->result_show->setText(show_string);
    return;
}

void MainWindow::brackets()
{
    QPushButton *button = (QPushButton *)sender();

    std::string str = ui->result_show->text().toStdString();
    if (str.length() == 1 && str.back() == '0')
    {
        ui->result_show->setText(button->text());
        return;
    }

    std::string ops_symbols_no_unars = "+, -, *, /, ^, (, )";
    std::string numsymbs = "0123456789ABCDEF()";
    QString symbol = ui->result_show->text().back();
    std::string utf8_symbol = symbol.toUtf8().constData();
    if ((ops_symbols_no_unars.find(utf8_symbol) == std::string::npos && button->text() == '(') ||
        (numsymbs.find(utf8_symbol) == std::string::npos && button->text() == ')') ||
        (str.back() == '!' || str.back() == '.'))
        return;
    std::string expression;
    QString show_string;
    expression = (ui->result_show->text() + button->text()).toStdString();
    show_string = QString::fromStdString(expression);

    ui->result_show->setText(show_string);
    return;
}

void MainWindow::dot_fact()
{
    QPushButton *button = (QPushButton *)sender();
    std::string str = ui->result_show->text().toStdString();
    char ops_symbols_array[16] = "+-*/√^!gn.";
    size_t found = str.find_last_of(ops_symbols_array);
    if (found != std::string::npos)
        str = str.substr(found);
    std::string ops_symbols = "+, -, *, /, √, %, ^, !, g, n, ., (";
    QString symbol = ui->result_show->text().back();
    std::string utf8_symbol = symbol.toUtf8().constData();

    if (    ops_symbols.find(utf8_symbol) != std::string::npos            ||
            str.length() < 1                                              ||
            (str.find('.') != std::string::npos && button->text() == '.') ||
            (str.back() == ')' && button->text() == '.'))
        return;
    ui->result_show->setText(ui->result_show->text() + button->text());
    return;
}

void MainWindow::ops()
{
    QPushButton *button = (QPushButton *)sender();
    std::string str = ui->result_show->text().toStdString();
    if (str.length() == 1 && str.back() == '0' && (button->text() == '-' || button->text() == "lg" || button->text() == "ln" || button->text() == "√"))
    {
        ui->result_show->setText(button->text());
        if (button->text() == "√" || button->text() == "lg" || button->text() == "ln")
            ui->result_show->setText(ui->result_show->text() + '(');
        return;
    }
    std::string ops_symbols = "+, -, *, /, √, %, ^, g, n, .";
    std::string ops_symbols_no_unars = "+, -, *, /, %, ^";
    QString symbol = ui->result_show->text().back();
    std::string utf8_symbol = symbol.toUtf8().constData();
    if (    (ops_symbols.find(utf8_symbol) == std::string::npos && button->text() != "√" && button->text() != "lg" && button->text() != "ln") ||
            ((button->text() == "√" || button->text() == "lg" || button->text() == "ln") && ops_symbols_no_unars.find(utf8_symbol) != std::string::npos))
    {
        std::string expression;
        QString show_string;
        expression = (ui->result_show->text() + button->text()).toStdString();
        show_string = QString::fromStdString(expression);
        ui->result_show->setText(show_string);
        if (button->text() == "√" || button->text() == "lg" || button->text() == "ln")
            ui->result_show->setText(ui->result_show->text() + '(');
    }
    ui->pushButton_dot->setChecked(false);
    return;
}

void MainWindow::on_spinBox_editingFinished()
{
    ui->result_show->setText("0");
    int value = ui->spinBox->value();
    ui->pushButton_F->blockSignals(false);
    ui->pushButton_E->blockSignals(false);
    ui->pushButton_D->blockSignals(false);
    ui->pushButton_C->blockSignals(false);
    ui->pushButton_B->blockSignals(false);
    ui->pushButton_A->blockSignals(false);
    ui->pushButton_9->blockSignals(false);
    ui->pushButton_8->blockSignals(false);
    ui->pushButton_7->blockSignals(false);
    ui->pushButton_6->blockSignals(false);
    ui->pushButton_5->blockSignals(false);
    ui->pushButton_4->blockSignals(false);
    ui->pushButton_3->blockSignals(false);
    ui->pushButton_2->blockSignals(false);
    if (value == 16)
        return;
    ui->pushButton_F->blockSignals(true);
    if (value == 15)
        return;
    ui->pushButton_E->blockSignals(true);
    if (value == 14)
        return;
    ui->pushButton_D->blockSignals(true);
    if (value == 13)
        return;
    ui->pushButton_C->blockSignals(true);
    if (value == 12)
        return;
    ui->pushButton_B->blockSignals(true);
    if (value == 11)
        return;
    ui->pushButton_A->blockSignals(true);
    if (value == 10)
        return;
    ui->pushButton_9->blockSignals(true);
    if (value == 9)
        return;
    ui->pushButton_8->blockSignals(true);
    if (value == 8)
        return;
    ui->pushButton_7->blockSignals(true);
    if (value == 7)
        return;
    ui->pushButton_6->blockSignals(true);
    if (value == 6)
        return;
    ui->pushButton_5->blockSignals(true);
    if (value == 5)
        return;
    ui->pushButton_4->blockSignals(true);
    if (value == 4)
        return;
    ui->pushButton_3->blockSignals(true);
    if (value == 3)
        return;
    ui->pushButton_2->blockSignals(true);
    return;
}
