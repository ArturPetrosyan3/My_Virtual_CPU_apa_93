#include "cpu.h"

CPU::CPU(RAM *Memory)
    : OverflowError(false)
    , SignedFlag(false)
    , Halted(false)
    , m_Memory(Memory)
    , ProgramCounter(0)
{
    //SetVar(ProgramCounter);
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



void CPU::Execute() {
    while(!Halted)  {

    }
}

int CPU::GetCommandEnum(QString CommandName) {
    if (CommandName == "mov")
        return 0;
    else if (CommandName == "add")
        return 1;
    else if (CommandName == "clr")
        return 2;
    else if (CommandName == "var")
        return 3;
    else
        return -1;
}

QMap<QString, QString> CPU::Decode(QQueue<QString> &Code) {
    QTextStream ParsedToken;
    QString InputVariable;
    QString FirstVariable;
    QString SecondVariable;
    QMap <QString, QString> VariableMap;

    switch (GetCommandEnum(Code.front())) {
        case MOV:
            Code.pop_front();
            FirstVariable = Code.front();
            Code.pop_front();
            SecondVariable = Code.front();

            //InputBinaryString = GetBinFormatInt(32,SecondVariable.toInt());
            break;
        case ADD:
            //to do
            break;
        case CLR:
            break;
        case VAR:
             Code.pop_front();
             InputVariable = Code.front();
             VariableMap.insert(InputVariable,GetBinFormatInt(32,0));

            break;

        default:
        break;
    }
    return VariableMap;
}

QString CPU::GetBinFormatInt(const int Width, int Num){
    std::bitset<32> BitStr(Num);
    std::string mystr=  BitStr.to_string();
    QString str = QString::fromUtf8(mystr.c_str());
    return str;
}


