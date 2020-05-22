#include "layout.h"
#include "ui_layout.h"

#include "QtAwesome/QtAwesome.h"
#include "QtAwesome/QtAwesomeAnim.h"

#include<QPalette>
#include <QPushButton>
#include<QColor>

Layout::Layout(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Layout)
{


    ui->setupUi(this);


    QtAwesome* awesome = new QtAwesome(this);
    awesome->initFontAwesome();     // This line is important as it loads the font and initializes the named icon map
    ui->Backbutton->setIcon(awesome->icon(fa::arrowleft));

}

Layout::~Layout()
{
    delete ui;
}

void Layout::on_ExploreFiles_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Layout::on_Backbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Layout::on_SearchButton_clicked()
{

}
