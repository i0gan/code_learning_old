#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    isFirst = true;
    this->setWindowTitle(QString("Simple chess"));
    this->resize(800, 600);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *) {
    this->chess_h = this->height() / 10; // Get chess width and height
    this->chess_w = this->width() / 10;

    QPainter p; //define a painter
    p.begin(this);
    p.drawPixmap(this->rect(),QPixmap("://Frame.jpg")); //set background
    QPen pen;
    pen.setWidth(5); //set width of a pen
    p.setPen(pen);

    for(int i = 0; i < 9; i++) {
        //draw fream
        p.drawLine(chess_w, chess_h * (i +1), chess_w * 9, chess_h * (i +1));
        p.drawLine( chess_w * (i +1), chess_h, chess_w * (i +1), chess_h * 9);
    }
    if(false == isFirst) {
        p.drawPixmap((chessPos.x() + 1) * chess_w, (chessPos.y() + 1) * chess_h, chess_w, chess_h, QPixmap("://Luffy.png"));
    }

    p.end();

}
void Widget::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        isFirst = false;
        int mx = e->x();
        int my = e->y(); //get mouse position in map
        if(( mx >= chess_w && mx <= (9 * chess_w)) && (my >= chess_h && my <= (chess_h * 9)) ) {
        chessPos.setX((mx / chess_w) - 1);
        chessPos.setY((my / chess_h) - 1);
        qDebug() << "[" << chessPos.x() << "," << chessPos.y() << "]";
        this->update();
        }
    }
}
