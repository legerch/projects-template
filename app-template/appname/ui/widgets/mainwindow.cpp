#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ui/widgets/menu/menubar.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Initialize members */

    /* Manage UI */
    uiInit();

    /* Manage connections */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::uiInit()
{
    uiInitTitle();
    uiInitMenu();

    uiLoadIcons();
}

void MainWindow::uiInitTitle()
{
    const QString title = QString("%1 - v%2 - Qt %3").arg(
        qApp->applicationName(),
        qApp->applicationVersion(),
        qVersion()
    );

    setWindowTitle(title);
}

void MainWindow::uiInitMenu()
{
    MenuBar *menu = new MenuBar(this);
    setMenuBar(menu);
}

void MainWindow::uiLoadIcons()
{
    //TODO: implement
#if 0
    const QIcon edit = QIcon::fromTheme("edit");

    ui->btn_permStatusRefresh->setIcon(QIcon::fromTheme("refresh"));
    ui->btn_permAsk->setIcon(edit);

    ui->btn_interfaceOptCacheEdit->setIcon(edit);
#endif
}
