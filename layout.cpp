#include "layout.h"
#include "ui_layout.h"

#include "QtAwesome/QtAwesome.h"
#include "QtAwesome/QtAwesomeAnim.h"

#include<QPalette>
#include <QPushButton>
#include<QColor>
#include<QMessageBox>
#include<QTextStream>
#include<QFile>

Layout::Layout(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Layout)
{
    ui->setupUi(this);

    QtAwesome* awesome = new QtAwesome(this);
    awesome->initFontAwesome();     // This line is important as it loads the font and initializes the named icon map
    ui->Backbutton->setIcon(awesome->icon(fa::arrowleft));

    int TrieBuildTime = 10;
    ui->statusBar->showMessage("Time To build Trie: "+QString::number(TrieBuildTime));
    // ||||||||
    ui->progressBar->setVisible(false);

}

Layout::~Layout()
{
    delete ui;
}

void Layout::on_ExploreFiles_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

   /* QFont font;
    for(int i=0;i<50;i++)
    {
        QFile file("E:/lastds/SearchEngine/backend/questions/"+QString::number(i)+".txt");
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
    }*/
}

void Layout::on_Backbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Layout::on_SearchButton_clicked()
{
//
    ui->progressBar->setVisible(true);
    // first val
    std::string SearchValue = ui->lineEdit->text().toStdString();
    // call search
    int numberoffiles = 50/* val */;
    // sec val

    GetFiles(numberoffiles);//edit
}

void Layout::GetFiles(int NumberofFile)
{
    QFont font;
    for(int i=0;i<NumberofFile;i++)
    {
       // QFile file("E:/lastds/SearchEngine/backend/questions/"+QString::number(i)+".txt");
        QFile file(":/questions/"+QString::number(i)+".txt");
        if (!file.open(QIODevice :: ReadOnly))
        {
            QMessageBox ::warning(this,"Opening Problem","Current Files Not Found");
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
