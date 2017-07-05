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
    QQueue<QString> Tokens;
    QString Commands;
    QString OpName;
    QString FirstVariable;
    QString SecondVariable;
    Commands = TokenizeString(Tokens, Line);
    OpName = Tokens.front();
    Tokens.pop_front();
    if (OpName != "HALT") {
        FirstVariable = Tokens.front();
        Tokens.pop_front();
        SecondVariable = Tokens.front();
    }


    if (OpName == "HALT") {
        load(HALT);

    }
    else if (OpName == "LOAD" && FirstVariable == "R0")
    {
        load(LOAD0);
        //load(FirstVariable.toInt());
        load(SecondVariable.toInt());
    }
    else if (OpName == "LOAD"  && FirstVariable == "R1")
    {
        load(LOAD1);
        load(SecondVariable.toInt());
    }
    else if (OpName == "LOAD"  && FirstVariable == "R2")
    {
        load(LOAD2);
        load(SecondVariable.toInt());
    }
    else if (OpName == "LOAD"  && FirstVariable == "R3")
    {
        load(LOAD3);
        load(SecondVariable.toInt());
    }
    else if (OpName == "LOAD"  && FirstVariable == "R4")
    {
        load(LOAD4);
        load(SecondVariable.toInt());
    }
    else if (OpName == "LOAD"  && FirstVariable == "R5")
    {
        load(LOAD5);
        load(SecondVariable.toInt());
    }
    else if (OpName == "LOAD"  && FirstVariable == "R6")
    {
        load(LOAD6);
        load(SecondVariable.toInt());
    }
    else if (OpName == "LOAD"  && FirstVariable == "R7")
    {
        load(LOAD7);
        load(SecondVariable.toInt());
    }

    else if (OpName == "ADD")
    {
        load(ADD);
        load(GetRegEnumNumber(FirstVariable));
        load(GetRegEnumNumber(SecondVariable));
    }
}
int ProgramLoader::GetRegEnumNumber(QString RegisterName) {
    if (RegisterName == "R0")
        return 1;
    else if (RegisterName == "R1")
        return 2;
    else if (RegisterName == "R2")
        return 3;
    else if (RegisterName == "R3")
        return 4;
    else if (RegisterName == "R4")
        return 5;
    else if (RegisterName == "R5")
        return 6;
    else if (RegisterName == "R6")
        return 7;
    else if (RegisterName == "R7")
        return 8;
}


void ProgramLoader::load(int b)
{
    //cout << b;
  //  Memory->Write(AddressOffset + AddressCounter, QByteArray::number(b) );
    AddressCounter++;
}
