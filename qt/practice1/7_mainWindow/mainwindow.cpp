#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*Menu windows mainly includes controls:
     * menu bar
     * toolbar
     * status bar
     * core controls
     * floating window
     */
    resize(600, 300);
    //Crate menubar
    //QmenuBar *mBar = mnuBar();
    QMenuBar *menuBar = new QMenuBar(this);
    // Add menu
    QMenu *pFile = menuBar->addMenu("File");

    QAction *pNew = pFile->addAction("new");

    connect(pNew, &QAction::triggered,
            [=]() {
        qDebug() << "New";
    });

    pFile->addSeparator(); // Add separator line
    QAction *pOpen = pFile->addAction("open");

    //***************************************
    //Tools bar:A shortcut to a menu item
    QToolBar *toolBar = addToolBar("toolBar");
    //Add shortcut
    toolBar->addAction(pNew);

    //Add little contronl
    QPushButton *b = new QPushButton();
    b->setText("@_@");
    toolBar->addWidget(b);
    connect(b, &QPushButton::clicked,
            [=](){
       b->setText("^_^");
    });

    //***************************************
    //Qtatusbar:

    QStatusBar *sBar = new QStatusBar(this);
    sBar->move(0, 20);

    QLabel *label = new QLabel(this);
    label->setText("Yes! YOu are right!");

    sBar->addWidget(label); //The method 1 of add widget ->
    sBar->addWidget(new QLabel("1314", this)); //The method 2 of add widget ->
    sBar->addPermanentWidget(new QLabel("520", this)); //The method 3 of add widget ->

    //***************************************
    //Core Control
    QTextEdit *Te = new QTextEdit(this);
    setCentralWidget(Te);
    //Te->move(100,50);

    //floating window
    QDockWidget *dock = new QDockWidget(this);
    dock->setWidget(Te);
    addDockWidget(Qt::BottomDockWidgetArea, dock);
}

MainWindow::~MainWindow()
{

}
