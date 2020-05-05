#include "subwindow.h"

subWindow::subWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("SubWindow");
    b.setParent(this);
    b.setText("Change to main window");
    this->resize(400, 200);
    connect(&b, SIGNAL(clicked()), this, SLOT(BChangMain()));
}

void subWindow::BChangMain() {
    emit S_changeWindow();

}
