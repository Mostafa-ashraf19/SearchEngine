#ifndef LAYOUT_H
#define LAYOUT_H

#include <QMainWindow>
#include"DataProcessesingFiles/trie.h"

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

    void on_pushButton_clicked();
    void on_FrontButton_clicked();

private:

    Ui::Layout *ui;
    void GetFiles(std::list<int> FileNames);
    list<int> RetVal;
    trie Trie;
};
#endif // LAYOUT_H
