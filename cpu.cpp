#include "cpu.h"

CPU::CPU(RAM *Memory)
    : OverflowError(false)
    , SignedFlag(false)
    , Halted(false)
    , m_Memory(Memory)
    , ProgramCounter(2)
    , Op_Address(0)
{
    SetVar(Register_0);
    SetVar(Register_1);
}

CPU::~CPU() {
    m_Memory = nullptr;
}
void CPU::SetVar(QByteArray  &arr) {

    arr.setNum(0);
    qDebug() << arr;
}

void CPU::Reset() {

}


void CPU::Execute()
{
    while (!Halted)
    {
        QByteArray FatchReturn = Fetch();
        //m_Memory->Write(Op_Address, FatchReturn);
        //QByteArray ReadOpCode = m_Memory->Read(Op_Address);
        //Decode(ReadOpCode);
    }
}


QByteArray CPU::Fetch()
{
    QByteArray b;
    //b = m_Memory->Read(ProgramCounter);
    ProgramCounter += 1;
    //qDebug() << b;
    return b;
}

void CPU::Decode(QByteArray &Code) {
    int CodeNumber = Code.toInt();
    switch (CodeNumber)
    {
        case HALT:
            Halt();
            break;

        case LOAD0:
            Load0();
            break;

        case LOAD1:
            Load1();
            break;
        case LOAD2:
            Load2();
            break;
        case LOAD3:
            Load3();
            break;
        case LOAD4:
            Load4();
            break;
        case LOAD5:
            Load5();
            break;
        case LOAD6:
            Load6();
            break;
        case LOAD7:
            Load7();
            break;
        case ADD:
            Add();
            break;
    }
}

void CPU::Halt() {
    Halted = true;
}

void CPU::Load0() {
    //Register_0 = m_Memory->Read(ProgramCounter);
    qDebug() << "reg0" << Register_0;
    ProgramCounter++;
}
void CPU::Load1() {
    //Register_1 = m_Memory->Read(ProgramCounter);
    qDebug() << "reg1" << Register_1;
    ProgramCounter++;
}
void CPU::Load2() {
    //Register_2 = m_Memory->Read(ProgramCounter);
    qDebug() << "reg2" << Register_2;
    ProgramCounter++;
}
void CPU::Load3() {
    //Register_3 = m_Memory->Read(ProgramCounter);
    ProgramCounter++;
}

void CPU::Load4() {
    //Register_4 = m_Memory->Read(ProgramCounter);
    ProgramCounter++;
}

void CPU::Load5() {
    //Register_5 = m_Memory->Read(ProgramCounter);
    ProgramCounter++;
}


void CPU::Load6() {
    //Register_7 = m_Memory->Read(ProgramCounter);
    ProgramCounter++;
}


void CPU::Load7() {
    //Register_7 = m_Memory->Read(ProgramCounter);
    ProgramCounter++;
}
void CPU::Add() {
    //QByteArray FirstOperand;
    //FirstOperand = m_Memory->Read(ProgramCounter);
}

