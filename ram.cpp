#include "ram.h"

RAM::RAM()
    : m_Size(1024)
{
    // Resizing of the memory to have the size of ours
    m_MemorySpace.resize(m_Size);
    // Setting the memory values 0;
    ClearRam();
}

void RAM::ClearRam() {
    for (int i = 0; i< m_Size; i++) {
        m_MemorySpace.append(QByteArray::number(0));
    }
}

const char* RAM::Read (const int AddressInRam) {
  // return m_MemorySpace[AddressInRam];
    //qDebug() <<
    //char Data = m_MemorySpace[AddressInRam];

    //return Data;
}

void RAM::Write(const int AddressInRam, const QByteArray& ValueInMemAddress) {
    m_MemorySpace.insert(AddressInRam,ValueInMemAddress);
    //m_MemorySpace[AddressInRam] = ValueInMemAddress;
    //qDebug() << m_MemorySpace.at
}
