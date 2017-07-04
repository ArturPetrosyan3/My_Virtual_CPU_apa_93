#include "ram.h"
#include "bytarray.h"

RAM::RAM()
    : m_Size(1024)
{
    // Resizing of the memory to have the size of ours
    m_MemorySpace.resize(m_Size);
    m_MemorySpace.fill(0,m_Size);
}

void RAM::ClearRam() {
    for (int i = 0; i< m_Size; i++) {
        m_MemorySpace.append(QByteArray::number(0));
    }
}

const char* RAM::Read (const int AddressInRam) {

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


void RAM::Write(const int AddressInRam, const QByteArray& ValueInMemAddress) {
    int arr[32];
    QString arr1;
    int count = 0;
    int theValue = 7;
    BytArray aa;
    int index=0;
    int num=0;

    for (int i = 31; i >= -1; --i) {
        int To = theValue & (1 << i) ? 1 : 0;
        //arr[i] = To;
        if (count == 8) {
            //
            num = arr1.toInt();


           char a = (char)convertBinaryToDecimal(num);
           aa.WriteInToMemory(a,index++);
            count = 0;
            ++i;
            arr1.clear();
            continue;
        } else {
            arr1.append(QString::number(To).rightJustified(1, '0'));
            count++;
        }
    }
    aa.Print();

}
