#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QMap>
#include <QString>

class Translator
{
private:

    //dictionary of letters and their codes
    QMap<QString, QString> dictionary;

    //initialization of dictionary
    void initDictionary();
public:
    Translator();

    //text encoding method
    QString textToMorse(QString text);

    //text decoding method
    QString morseToText(QString encodedText);
};

#endif // TRANSLATOR_H
