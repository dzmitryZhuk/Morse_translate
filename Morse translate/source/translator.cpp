#include "translator.h"

Translator::Translator()
{
    initDictionary();
}

void Translator::initDictionary()
{
                                        // letters
    dictionary.insert("a", ".-");
    dictionary.insert("b", "-...");
    dictionary.insert("c", "-.-.");
    dictionary.insert("d", "-..");
    dictionary.insert("e", ".");
    dictionary.insert("f", "..-.");
    dictionary.insert("g", "--.");
    dictionary.insert("h", "....");
    dictionary.insert("i", "..");
    dictionary.insert("j", ".---");
    dictionary.insert("k", "-.-");
    dictionary.insert("l", ".-..");
    dictionary.insert("m", "--");
    dictionary.insert("n", "-.");
    dictionary.insert("o", "---");
    dictionary.insert("p", ".--.");
    dictionary.insert("q", "--.-");
    dictionary.insert("r", ".-.");
    dictionary.insert("s", "...");
    dictionary.insert("t", "-");
    dictionary.insert("u", "..-");
    dictionary.insert("v", "...-");
    dictionary.insert("w", ".--");
    dictionary.insert("x", "-..-");
    dictionary.insert("y", "-.--");
    dictionary.insert("z", "--..");

                                        // symbols
    dictionary.insert(".", "......");
    dictionary.insert(";", "-.-.-.");
    dictionary.insert(",", ".-.-.-");
    dictionary.insert(":", "---...");
    dictionary.insert("-", "-....-");
    dictionary.insert("?", "..--..");
    dictionary.insert("!", "--..--");
    dictionary.insert("(", "-.--.");
    dictionary.insert(")", "-.--.-");
    dictionary.insert("\"", ".-..-.");
    dictionary.insert(" ", "  ");
}

QString Translator::textToMorse(QString text)
{
    QString encodedText;
    for(int i = 0; i < text.size(); i++)
    {
        encodedText += dictionary.value(text.at(i));
        if (i == text.size() - 1) break;
        if(text.at(i).toLatin1() != ' ' && text.at(i + 1).toLatin1() != ' ')
            encodedText += " ";
    }
    return encodedText;
}

QString Translator::morseToText(QString encodedText)
{
    QString decodedText, temp;
    for(int i = 0; i < encodedText.size(); i++)
    {
        for(int j = i; j < encodedText.size() && encodedText.at(j).toLatin1() != ' '; j++)
        {
            temp += encodedText.at(j);
            i++;
        }

        decodedText += dictionary.key(temp);
        if(i + 1 < encodedText.size())
            if(encodedText.at(i).toLatin1() == ' ' && encodedText.at(i + 1).toLatin1() == ' ')
                decodedText += " ";

        temp.clear();
    }
    return decodedText;
}
