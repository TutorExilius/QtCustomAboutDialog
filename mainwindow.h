#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "customaboutdialog.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );
    ~MainWindow();

private slots:
    void onAppAbout_triggered();
    void onAboutQt_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
