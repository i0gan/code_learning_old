#include "qt4_tread.h"

Qt4_Tread::Qt4_Tread(QObject *parent) : QThread(parent)
{

}
void Qt4_Tread::run() {
    sleep(5); //Similar to very complex data processing
    emit isDone();
}
