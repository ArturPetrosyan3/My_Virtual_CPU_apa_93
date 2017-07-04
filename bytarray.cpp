#include "bytarray.h"

BytArray::BytArray()
    : m_MaxAddress(255)
    , m_Memoery (new char[m_MaxAddress])
{
    Clear();
}

void BytArray::Clear()    {
    for (int i = 0; i < m_MaxAddress; ++i) {
        m_Memoery[i] = 0;
    }
}


void BytArray::WriteInToMemory(char val, int index) {
    m_Memoery[index] = val;
}

void BytArray::Print() {
    for (int i = 0; i < m_MaxAddress; ++i) {
        qDebug() << m_Memoery[i];
    }
}
