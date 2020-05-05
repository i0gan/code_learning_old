#include "doxml.h"
#define qout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"
Doxml::Doxml()
{

}
//creat a null file of xml
void Doxml::createXML(QString filePath) {
    QFile file(filePath);
    if(true == file.exists()) {//if exit wiil return
        return;
    }else {
        bool isOpen = file.open(QIODevice::WriteOnly);
        if(true == isOpen) {
            //create a object of document
            QDomDocument doc;
            //create header of format
            QDomProcessingInstruction ins;
            ins = doc.createProcessingInstruction("xml", "version=\'1.0\' encoding=\'utf-8\'");
            //Additional element
            doc.appendChild(ins);
            //root node element
            QDomElement root = doc.createElement("DailySalesList");
            doc.appendChild(root);

            //save
            QTextStream tStream(&file); //text stream
            doc.save(tStream, 4); //table indent as 4

        }else {
            qout << "WriteOnly error";
        }

    }

}

void Doxml::appendXML(QString filePath, QStringList list) {
    QFile file(filePath);
    bool isOpen = file.open(QIODevice::ReadOnly);
    if(true == isOpen) {
        //file and xml asosiated
        QDomDocument doc;
        bool isOk = doc.setContent(&file);
        if(true == isOk) {
            qout << "ddd";
            file.close(); //close file
            //get element of root node
            QDomElement root = doc.documentElement();
            QDateTime date = QDateTime::currentDateTime();
            QString dateStr = date.toString("yyyy-MM-dd");
            //judge if have child nodes under the root node
            if(root.hasChildNodes()) { //if has
            //find last child node
            QDomElement lastEmt = root.lastChildElement();
            if(lastEmt.attribute("date") == dateStr) {
                writeXML(doc, lastEmt, list);
            }else { //if have no current date
                //create date child node
                QDomElement dateEmt = doc.createElement("date");
                //create attribute of child node
                QDomAttr dateAttr = doc.createAttribute("date");
                //set value of attrbute
                dateAttr.setNodeValue(dateStr);
                //relevant node and attr
                dateEmt.setAttributeNode(dateAttr);
                //add date node to root node
                root.appendChild(dateEmt);
                writeXML(doc, dateEmt, list);
            }

            }else { //has no child nodes
                //create date child node
                QDomElement dateEmt = doc.createElement("date");
                //create attribute of child node
                QDomAttr dateAttr = doc.createAttribute("date");
                //set value of attrbute
                dateAttr.setNodeValue(dateStr);
                //relevant node and attr
                dateEmt.setAttributeNode(dateAttr);
                //add date node to root node
                root.appendChild(dateEmt);
                writeXML(doc, dateEmt, list);
            }
            //save file
            isOpen = file.open(QIODevice::WriteOnly);
            if(isOpen) {
                QTextStream stream(&file);
                doc.save(stream, 4);
                file.close();
            }else {
                qout << "write file fail";
                return;
            }

        }else {
            qout << "setContent error";
            return;
        }
    }else {
        qout << "open read only error";
        return;
    }
}
void Doxml::writeXML(QDomDocument &doc, QDomElement &root, QStringList &list) {
    //get current time
    QDateTime time = QDateTime::currentDateTime();
    QString timeStr = time.toString("hh-mm-ss");
    //create element of time
    QDomElement timeEmt = doc.createElement("Time");
    //crate attribute
    QDomAttr timeAttr = doc.createAttribute("time");
    //set value of time attr
    timeAttr.setNodeValue(timeStr);
    //relevant element and attribute
    timeEmt.setAttributeNode(timeAttr);
    //add time element to date element
    root.appendChild(timeEmt);

    //crete element under root node
    QDomElement factory = doc.createElement("factory");
    QDomElement brand = doc.createElement("brand");
    QDomElement price = doc.createElement("price");
    QDomElement amount = doc.createElement("amount");
    QDomElement total = doc.createElement("total");
    //append text to this
    QDomText text = doc.createTextNode(list.at(0));
    factory.appendChild(text);

    text = doc.createTextNode(list.at(1));
    brand.appendChild(text);

    text = doc.createTextNode(list.at(2));
    price.appendChild(text);

    text = doc.createTextNode(list.at(3));
    amount.appendChild(text);

    text = doc.createTextNode(list.at(4));
    total.appendChild(text);

    //relevant to timeEmt node
    timeEmt.appendChild(factory);
    timeEmt.appendChild(brand);
    timeEmt.appendChild(price);
    timeEmt.appendChild(amount);
    timeEmt.appendChild(total);
}
void Doxml::readXML(QString filePath,
                    QStringList &fList,
                    QStringList &bList,
                    QStringList &pList,
                    QStringList &aList,
                    QStringList &tList){
    QFile file(filePath);
    bool isOpen = file.open(QIODevice::ReadOnly);
    if(true == isOpen) {
        //relevant xml file and object
        QDomDocument doc;
        bool isOk = doc.setContent(&file);
        if(isOk) {
            //close file
            file.close();
            QDateTime date = QDateTime::currentDateTime();
            QString dateStr = date.toString("yyyy-MM-dd");
            //get root node
            QDomElement root = doc.documentElement();
            if(root.hasChildNodes()) { //judge if have child node
                QDomElement lastEmt = root.lastChildElement();
                if(lastEmt.attribute("date") == dateStr) { //judge if have current date in a day
                    QDomNodeList list = lastEmt.childNodes();
                    for(int i = 0; i < list.size(); i++) {
                        //list.at(0).toElement();
                        //change to element, find all child nodes in curent root node
                        QDomNodeList subList = list.at(i).toElement().childNodes();
                        //factory
                        QString factory = subList.at(0).toElement().text();
                        fList.append(factory);

                        QString brand = subList.at(1).toElement().text();
                        bList.append(brand);

                        QString price = subList.at(2).toElement().text();
                        pList.append(price);

                        QString amount = subList.at(3).toElement().text();
                        aList.append(amount);

                        QString total = subList.at(4).toElement().text();
                        tList.append(total);
                    }
                }
            }else {

            }
        }else {
            qout << "readXml setContent error";
        }
    }else {
        qout << "readXml readOnly error";
    }

}
