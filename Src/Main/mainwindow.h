#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ElaWindow.h"
#include "ihbHome.h"
// #include "T_Home.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public ElaWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Ui::MainWindow *ui;
    IhbHome* homePage{nullptr};
};

#endif // MAINWINDOW_H
