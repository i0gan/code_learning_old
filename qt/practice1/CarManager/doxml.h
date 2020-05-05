#ifndef DOXML_H
#define DOXML_H
#include <QString>
#include <QFile>
#include <QDomDocument> //xml file pointer
#include <QDomProcessingInstruction> //the header of format
#include <QDomElement> //element
#include <QDebug>
#include <QTextStream>
#include <QStringList>
#include <QDateTime>
class Doxml
{
public:
    Doxml();
    static void createXML(QString filePath); //create a static function to create xml
    static void appendXML(QString filePath, QStringList list); //append content
    static void writeXML(QDomDocument &doc, QDomElement &root,QStringList &list); //writexml with espetially root element
    static void readXML(QString filePath,
                        QStringList &fList, //factory list
                        QStringList &bList, //brand list
                        QStringList &pList, //price list
                        QStringList &aList, //sell amount list
                        QStringList &tList); //reaming total list
};

#endif // DOXML_H
