#ifndef CPU_H
#define CPU_H
#include "ram.h"
#include <QQueue>
#include <iostream>
#include <bitset>

enum OP {
    HALT,
    LOAD0,
    LOAD1,
    ADD,
    BEEP,
    PRINT,
    STORE,
    JMP,
    JMP_EQ,
    CLEAR0,
    CLEAR1,
    COPY0,
    COPY1
};

class CPU
{
public:
    CPU(RAM *Memory);
    void SetVar(QByteArray &arr);
    ~CPU();

    void Execute();
    void Reset();

    enum {MOV, ADD, CLR, VAR};

    QMap<QString,QString> Decode(QQueue<QString> &Token);
    QString GetBinFormatInt(const int Width, int Num);
    int GetCommandEnum(QString CommandName);


private:
    int ProgramCounter;
    QByteArray Register_0;
    QByteArray Register_1;
    bool OverflowError;
    bool SignedFlag;
    bool Halted;
    RAM *m_Memory;
};

#endif // CPU_H
