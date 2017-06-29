#ifndef CPU_H
#define CPU_H
#include "ram.h"
#include <QQueue>
#include <iostream>
#include <bitset>
#include <QMap>

enum OP {
    HALT,
    LOAD0,
    LOAD1,
    LOAD2,
    LOAD3,
    LOAD4,
    LOAD5,
    LOAD6,
    LOAD7,
    ADD
};

class CPU
{
public:
    CPU(RAM *Memory);
    void SetVar(QByteArray &arr);
    ~CPU();

    void Execute();
    QByteArray Fetch();
    void Decode(QByteArray &Code);
    void Halt();
    void Reset();

    void Load0();
    void Load1();
    void Load2();
    void Load3();
    void Load4();
    void Load5();
    void Load6();
    void Load7();
    void Add();




private:
    int ProgramCounter;
    int Op_Address;
    //QMap <QString, QByteArray> Registers;
    QByteArray Register_0;
    QByteArray Register_1;
    QByteArray Register_2;
    QByteArray Register_3;
    QByteArray Register_4;
    QByteArray Register_5;
    QByteArray Register_6;
    QByteArray Register_7;
    bool OverflowError;
    bool SignedFlag;
    bool Halted;
    RAM *m_Memory;
};

#endif // CPU_H
