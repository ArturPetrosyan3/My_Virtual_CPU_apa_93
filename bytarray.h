#ifndef BYTARRAY_H
#define BYTARRAY_H
#include <QBitArray>
#include <QDebug>

class BytArray
{
public:
    const int m_MaxAddress;
    //BytArray();
    BytArray();
    void Clear();
    void WriteInToMemory(char val, int index);
    void Print();
private:
    char *m_Memoery;
};

#endif // BYTARRAY_H
