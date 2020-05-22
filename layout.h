#ifndef LAYOUT_H
#define LAYOUT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Layout; }
QT_END_NAMESPACE

class Layout : public QMainWindow
{
    Q_OBJECT

public:
    Layout(QWidget *parent = nullptr);
    ~Layout();

private slots:



    void on_ExploreFiles_clicked();

    void on_Backbutton_clicked();

    void on_SearchButton_clicked();

private:
    Ui::Layout *ui;

};
#endif // LAYOUT_H
