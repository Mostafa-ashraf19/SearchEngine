#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QTextCursor>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    QFont font;
    QColor color;
    for(int i=0;i<50;i++)
    {
        QFile file("D:/dataStructure/questions/"+QString::number(i)+".txt");
        if (!file.open(QIODevice :: ReadOnly))
        {
            QMessageBox :: information(this,"a","b");
        }
        QTextStream in(&file);
        QString str = file.fileName();
        QStringList parts = str.split("/");
        QString lastBit = parts.at(parts.size()-1);
        color.setRed(200);
        ui->textEdit->setTextColor(color);
        font.setBold(true);
        ui->textEdit->setCurrentFont(font);
        ui-> textEdit ->insertPlainText(lastBit + "\n");
        font.setBold(false);
        ui->textEdit->setCurrentFont(font);
        ui-> textEdit ->insertPlainText(in.readAll() + "\n" );
    }
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
    ui->textEdit->setTextCursor(textCursor);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->find(ui->lineEdit->text());

}
void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->find(ui->lineEdit->text(),QTextDocument::FindBackward);
}
