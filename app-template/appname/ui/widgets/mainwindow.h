#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void uiInit();
    void uiInitTitle();
    void uiInitMenu();

    void uiLoadIcons();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
