#include "ram.h"

RAM::RAM()
    : Size(256)
    , MemorySpace(new QByteArray[Size])
{
    ClearRam();
}

void RAM::ClearRam() {
    for (int i = 0; i< Size; i++) {
        MemorySpace[i] = 0;
    }
}

const QByteArray RAM::Read (const int AddressInRam) {
   return MemorySpace[AddressInRam];
}

void RAM::Write(const int AddressInRam, const QByteArray& ValueInMemAddress) {
    MemorySpace[AddressInRam] = ValueInMemAddress;
    qDebug() << MemorySpace[AddressInRam];
}
