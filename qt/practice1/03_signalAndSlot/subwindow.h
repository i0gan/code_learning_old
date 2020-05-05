#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
class subWindow : public QWidget
{
    Q_OBJECT
public:
    explicit subWindow(QWidget *parent = 0);

signals:
    void S_changeWindow();
public slots:
    void BChangMain();
private:
    QPushButton b;
};

#endif // SUBWINDOW_H
