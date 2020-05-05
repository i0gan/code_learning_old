#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initData();

}

Widget::~Widget()
{
    delete ui;
}
void Widget::initData() {

    //set window tiltle
    this->setWindowTitle("QQ 2020");
    //set window icon
    setWindowIcon(QPixmap(":/images/res/timg.jpg"));

    QList<QString>nameList;
    nameList << "admin" << "mike" << "logan" << "jonh" << "smith" << "santana" << "trave" << "stock" << "bend";
    QList<QString>iconList;
    iconList << "timg.jpg" << "sunny.png" << "down.png" << "Luffy.png" << "LuffyQ.png" << "OnePiece.png" << "Sunny.jpg"
             << "down.png" << "OnePiece.png";
    QVector <QToolButton *> vToolBtn;
    for(int i = 0; i< 9; i++) {
        //set profile image
        QToolButton *btn = new QToolButton(this);
        vToolBtn.push_back(btn); //save btn to vector
        btn->setText(nameList[i]);
        //set header
        btn->setIcon(QPixmap(QString(":/images/res/%1").arg(iconList.at(i))));
        //set size
        btn->setIconSize(QSize(100, 100));
        //btn->resize(100, 100);
        //stye transparent
        btn->setAutoRaise(true);
        //set text and image on a btn
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->verticalLayout_2->addWidget(btn);
        isShow.push_back(false);
    }
    //add signal to every button
    for(int j = 0; j < vToolBtn.size(); j ++) {
        connect(vToolBtn[j], &QToolButton::clicked, [=]() {
            if(true == isShow[j]) {
                QMessageBox::warning(this, "warning","this window has been opened!");
                return;
            }
            isShow[j] = true;
            DialogList *window = new DialogList(0, nameList[j]); //top show the window
            window->setWindowTitle(nameList[j]); //set window titel
            window->setWindowIcon(vToolBtn[j]->icon());
            window->show();
            connect(window, &DialogList::WindowClose, [=]() {isShow[j] = false; });
        });
    }
}
