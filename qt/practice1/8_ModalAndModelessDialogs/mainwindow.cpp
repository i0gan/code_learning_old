#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("File");
    QAction *p1 = menu->addAction("Modal_Dialog");
    connect(p1, &QAction::triggered,
            [=](){
        QDialog dlg;
        dlg.exec();
        qDebug() << "finish!1";

    });

    QAction *p2 = menu->addAction("Modaless_Dialog");
    connect(p2, &QAction::triggered,
            [=](){
        dlg = new QDialog;
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        this->dlg->show();  //
        qDebug() << "finish!2";

    });


    QAction *p3 = menu->addAction("Messagebox");
    connect(p3, &QAction::triggered,
            [=](){
        QMessageBox::about(this,"Hello", "About QT");

    });

    QAction *p4 = menu->addAction("Messagebox2");
    connect(p4, &QAction::triggered,
            [=](){
        int ret = QMessageBox::question(this, "Question",
                                        "Are you OK?"
                                        ,QMessageBox::Apply|QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Apply:
            qDebug() << "Apply";
            break;
        case QMessageBox::Cancel:
            qDebug() << "Cancel";
            break;
        default:
            break;
        }
    });

    QAction *p5 = menu->addAction("FileDialog");
    p5->setShortcut(QKeySequence::Open);
    p5->setStatusTip(tr("Open a new file"));
    connect(p5, &QAction::triggered,
            [=](){
        qDebug() << "OK";
        QString path = QFileDialog::getOpenFileName(
                    this,
                    "open file",
                    "../",
                    tr("images (*.png *.jpg);;Text (*.txt *.pro);;all (*.*)")
                     );
        qDebug() << path;
    });


}

MainWindow::~MainWindow()
{

}
