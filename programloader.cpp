#include "programloader.h"


ProgramLoader::ProgramLoader(RAM *mem, int Offset)
   : AddressCounter(0)
   , AddressOffset(Offset)
   , Memory(mem)
{ }


void ProgramLoader::loadFile(QString path)
{
    // Open and read the file.
    QFile Input(path);
    if (!Input.open(QIODevice::ReadOnly | QIODevice::Text))
         return;
    QTextStream in(&Input);

    while (!in.atEnd()) {
        QString Line = in.readLine();
        parse(Line);
    }
}
QString ProgramLoader::TokenizeString( QQueue<QString> &Tokens, QString LineToParse) {
    LineToParse.remove(QRegExp("[\t]"));
    LineToParse.remove(QRegExp("[,]"));
    LineToParse.remove(QRegExp("[$]"));
    QChar CommentCharacter = '#';
    int CommentIndex = LineToParse.indexOf('#');
    if (CommentIndex != -1) {
        LineToParse.remove(CommentIndex,LineToParse.size());
    }
    QStringList list = LineToParse.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    foreach (QString item, list) {
        Tokens.push_back(item);
    }
    return LineToParse;
}

void ProgramLoader::parse(QString Line)
{


//    if (Line.length() < 4)
//    {
//        load(stoi(Line.substr(0, line.find(';'))));
//        return;
//    }
    QQueue<QString> Tokens;
    QString Commands;
    QString OpName;
    QString FirstVariable;
    Commands = TokenizeString(Tokens, Line);
    OpName = Tokens.front();
    Tokens.pop_front();
    FirstVariable = Tokens.front();

    if (OpName == "HAL") {
        load(HALT);
    }
    else if (OpName == "LD0")
    {
        load(LOAD0);
        load(FirstVariable.toInt());
    }
    else if (OpName == "LD1")
    {
        load(LOAD1);
        load(FirstVariable.toInt());
    }
    else if (OpName == "ADD")
    {
        load(ADD);
    }
//    else if (Tokens.front() == "BEL")
//    {
//        load(BEEP);
//    }
//    else if (Tokens.front() == "PRT")
//    {
//        load(PRINT);
//        load(stoi(addr));
//    }
//    else if (Tokens.front() == "STR")
//    {
//        load(STORE);
//        load(stoi(addr));
//    }
//    else if (Tokens.front() == "JMP")
//    {
//        load(JMP);
//        load(stoi(addr));
//    }
//    else if (Tokens.front() == "JPE")
//    {
//        load(JMP_EQ);
//        load(stoi(addr));
//    }
//    else if (Tokens.front() == "CL0")
//    {
//        load(CLEAR0);
//    }
//    else if (Tokens.front() == "CL1")
//    {
//        load(CLEAR1);
//    }
//    else if (Tokens.front() == "CP0")
//    {
//        load(COPY0);
//    }
//    else if (Tokens.front() == "CP1")
//    {
//        load(COPY1);
//    }
}


void ProgramLoader::load(int b)
{
    //cout << b;
    Memory->Write(AddressOffset + AddressCounter, QByteArray::number(b) );
    AddressCounter++;
}
