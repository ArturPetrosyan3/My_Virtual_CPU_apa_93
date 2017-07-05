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

    char ItemInMemory;
    while (index < Integer) {
        temp = m_MemorySpace[index];
        IntegerValue.append(temp);
        index++;
        temp.clear();
    }
    for (int ValInByte=0; ValInByte < Integer; ++ValInByte) {
        QString ValueItem = IntegerValue.at(ValInByte);
        int theValue = ValueItem.toInt();
        for (int i = 0; i < 8; ++i) {
            int To = theValue & (1 << i) ? 1 : 0;
            temp.append(To);
            ValuesAsBinary.append(QString::number(To).rightJustified(1, '0'));
            temp.clear();
        }
    }
    long double vv = ValuesAsBinary.toInt();
    int aa = convertBinaryToDecimal(ValuesAsBinary.toInt());
    return aa;
}





void RAM::Write(const int AddressInRam, const int& ValueInMemAddress) {
    int arr[32];
    QString arr1;
    int count = 0;
    int theValue = 7;
   // BytArray aa;
    int index=0;
    int num=0;

    for (int i = 31; i >= -1; --i) {
        int To = theValue & (1 << i) ? 1 : 0;
        //arr[i] = To;
        if (count == 8) {
            //
            num = arr1.toInt();

           unsigned char a = '7';
           //aa.WriteInToMemory(a,index++);
           m_MemorySpace[index++] = a;
            count = 0;
            ++i;
            arr1.clear();
            continue;
        } else {
            arr1.append(QString::number(To).rightJustified(1, '0'));
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
