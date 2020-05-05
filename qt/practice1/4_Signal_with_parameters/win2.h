#ifndef WIN2_H
#define WIN2_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QDebug>
#include <QTextEdit>
class win2 : public QWidget
{
    Q_OBJECT
public:
    explicit win2(QWidget *parent = 0);

signals:
    void MySingal();
    void MySingal(QString, int);

public slots:
    void SendSingal();
private:
    QTextEdit *te;
};

#endif // WIN2_H
