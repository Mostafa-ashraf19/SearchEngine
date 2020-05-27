#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMainWindow>
#include <QTextCharFormat>
#include <QFileDialog>
#include <QTextStream>
#include <QTabWidget>
#include <QTextCursor>
#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QFontComboBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QMenu>
#include <QMenuBar>
#include <QTextCodec>
#include <QTextEdit>
#include <QStatusBar>
#include <QToolBar>
#include <QTextCursor>
#include <QTextDocumentWriter>
#include <QTextList>
#include <QtDebug>
#include <QCloseEvent>
#include <QMimeData>
#include <QPainter>
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

/*QTextEdit[styleVariant="1"] {
    font: italic bold 30px serif;
    background-color: white;
    color: black;
}

QTextEdit {
    background-color: white;
    color: black;
}*/
void MainWindow::on_pushButton_clicked()
{
    QFont font;
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
        font.setBold(true);
        ui->textEdit->setCurrentFont(font);
        ui-> textEdit ->insertPlainText(lastBit + "\n");
        font.setBold(false);
        ui->textEdit->setCurrentFont(font);
        ui-> textEdit ->insertPlainText(in.readAll() + "\n" );
    }
}

void MainWindow::on_pushButton_2_clicked()
{
       QString searchString = ui->lineEdit->text();
       QTextDocument *document = ui->textEdit->document();

       bool found = false;

       // undo previous change (if any)
       document->undo();

       if (searchString.isEmpty()) {
           QMessageBox::information(this, tr("Empty Search Field"),
                                    tr("The search field is empty. "
                                       "Please enter a word and click Find."));
       } else {
           QTextCursor highlightCursor(document);
           QTextCursor cursor(document);

           cursor.beginEditBlock();

           QTextCharFormat plainFormat(highlightCursor.charFormat());
           QTextCharFormat colorFormat = plainFormat;
           colorFormat.setForeground(Qt::red);

           while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
               highlightCursor = document->find(searchString, highlightCursor,
                                                QTextDocument::FindWholeWords);

               if (!highlightCursor.isNull()) {
                   found = true;
                   highlightCursor.movePosition(QTextCursor::WordRight,
                                                QTextCursor::KeepAnchor);
                   highlightCursor.mergeCharFormat(colorFormat);
               }
           }

           cursor.endEditBlock();
           if (found == false) {
                       QMessageBox::information(this, tr("Word Not Found"),
                                                tr("Sorry, the word cannot be found."));
                   }
       }

}

void MainWindow::on_pushButton_3_clicked()
{

}
