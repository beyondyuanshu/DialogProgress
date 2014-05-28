#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogprogress.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DialogProgress *dp = new DialogProgress;
    dp->setStopable(true);
    dp->slot_setProgress(1, 3);
    dp->slot_setState("Hello Qt.");
    QTimer::singleShot(3000, dp, SLOT(accept()));
    dp->exec();
}
