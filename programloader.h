#ifndef PROGRAMLOADER_H
#define PROGRAMLOADER_H
#include "ram.h"
#include <QFile>
#include <QTextStream>
#include "cpu.h"
#include <QQueue>
#include <QRegExp>


class ProgramLoader
{
private:
    int AddressCounter;
    int AddressOffset;
    RAM *Memory;

public:
    ProgramLoader(RAM *mem, int Offset);
    void loadFile(QString path);
    QString TokenizeString( QQueue<QString> &Tokens, QString LineToParse);
    int GetRegEnumNumber(QString RegisterName);

private:
    void parse(QString code);
    void load(int b);

};

#endif // PROGRAMLOADER_H
