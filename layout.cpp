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
    ui->FrontButton->setIcon(awesome->icon(fa::arrowright));

    //if(Trie.build_trie("E:/tgroba/SearchEngine/DataSet/"))
    //  ui->pushButton->setVisible(false);
    //ui->statusBar->showMessage("Build Finish,     Time To Build: "+QString::number(Trie.TimeBulding())+" Sec");

    ui->progressBar->setValue(0);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    // ||||||||
    ui->progressBar->setVisible(false);

}

Layout::~Layout()
{
    delete ui;
}

void Layout::on_ExploreFiles_clicked()
{

    GetFiles(RetVal);
    ui->stackedWidget->setCurrentIndex(1);
   // ui->progressBar->setVisible(false);
}

void Layout::on_Backbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Layout::on_SearchButton_clicked()
{
    ui->textEdit->clear();
    // first val
    std::string SearchValue = ui->lineEdit->text().toStdString();
    // call search
    RetVal = Trie.search(SearchValue); /*list*/ ;
    int NumberOfWords = Trie.WordCounts();/* val */;

    ui->lineEdit_2->setText(QString::number(NumberOfWords));
    ui->statusBar->showMessage("Searching Time: "+QString::number(Trie.SearchingTime())+" Sec");
}

void Layout::GetFiles(std::list<int> FileNames)
{
    QFont font;
    ui->progressBar->setVisible(true);
    if(FileNames.empty())
    {
         ui->statusBar->showMessage("Not Find");
         return;
    }
    int i=FileNames.size();
    ui->progressBar->setValue(10);
    for(auto& File: FileNames)
    {
       // QFile file("E:/tgroba/SearchEngine/DataSet/"+QString::number(File)+".txt");
        QFile file("DataSet/"+QString::number(File)+".txt");
        if (!file.open(QIODevice :: ReadOnly))
        {
            QMessageBox ::warning(this,"Opening Problem","Current Files Not Found");
            return;
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
        QCoreApplication::processEvents();
        ui->progressBar->setValue(50);
    }
    ui->progressBar->setValue(100);
    //QCoreApplication::postEvent(ui->progressBar,ui->progressBar->valueChanged(10));
}
void Layout::on_pushButton_clicked()
{
   Trie.build_trie("E:/tgroba/SearchEngine/DataSet/");
   QCoreApplication::processEvents();
   ui->pushButton->setVisible(false);
   ui->statusBar->showMessage("Build Finish,     Time To Build: "+QString::number(Trie.TimeBulding())+" Sec");
}

void Layout::on_FrontButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QCoreApplication::processEvents();
    ui->progressBar->setVisible(false);
}
