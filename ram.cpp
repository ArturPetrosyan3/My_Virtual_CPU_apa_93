#include "ram.h"
//#include "bytarray.h"

RAM::RAM()
    : m_MaxAddress(255)
    , m_MemorySpace(new unsigned char[m_MaxAddress])
{
    ClearRam();
}

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

void RAM::ClearRam() {
    for (int i = 0; i < m_MaxAddress; ++i) {
        m_MemorySpace[i] = 0;
    }
}

const int RAM::Read(const int AddressInRam, int Integer) {
    QString temp;
    QStringList IntegerValue;
    int index = AddressInRam;
    QString ValuesAsBinary;
    int theValue=0;
    char ItemInMemory;
    while (index < Integer) {
        temp = m_MemorySpace[index];
        if (temp.at(0) == 'A') {
            temp.clear();
            temp.append(QString::number(0).rightJustified(1, '0'));
        } else {
            QChar tmpNum = temp.at(0);
            temp.clear();
            temp.append(QString::number(tmpNum.unicode()).rightJustified(1, '0'));
        }
        IntegerValue.append(temp);
        index++;
        temp.clear();
    }
    for (int ValInByte=Integer-1; ValInByte >= 0; --ValInByte) {
        QString ValueItem = IntegerValue.at(ValInByte);
        theValue =theValue+ ValueItem.toInt();

//        for (int i = 0; i < 8; ++i) {
//            int To = theValue & (1 << i) ? 1 : 0;
//            temp.append(To);
//            ValuesAsBinary.append(QString::number(To).rightJustified(1, '0'));
//            temp.clear();
//        }
    }
    return theValue;
}





void RAM::Write(const int AddressInRam, const int ValueInMemAddress) {
    QString EightBitNum;    // takes 8 bit from the value in memorry address.
    int count = 0;          // The count that indicates that it reched to 8 it.
    int theValue = 57;
    int index=0;            // The address in memory whic is one byte.
    int num=0;              // The number wich will be written in 1 byte.
    unsigned char CurrentItem;
    for (int i = 31; i >= -1; --i) {
        int ABit = theValue & (1 << i) ? 1 : 0; // after shifiting makes a bit.
        if (count == 8) {
            num = EightBitNum.toInt();

            if (convertBinaryToDecimal(num) == 0)
                CurrentItem = 'A';
            else
                CurrentItem = convertBinaryToDecimal(num);
            m_MemorySpace[index++] = CurrentItem;
            count = 0;
            ++i;
            EightBitNum.clear();
            continue;
        } else {
            EightBitNum.append(QString::number(ABit).rightJustified(1, '0'));
            count++;
        }
    }
    Print();
}

void RAM::Print() {
    for (int i = 0; i < m_MaxAddress; ++i) {
        qDebug() << m_MemorySpace[i];
    }
}
