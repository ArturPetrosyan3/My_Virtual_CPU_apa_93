#ifndef RAM_H
#define RAM_H

#include <QMap>
#include <QByteArray>
#include <QDebug>
#include <QBitArray>

class RAM
{
public:
    RAM();
    ~RAM();
public:
    void ClearRam();
    const QByteArray Read (const int AddressInRam);
    void Write(const int AddressInRam, const QByteArray& ValueInMemAddress);

private:
    int Size;
    QByteArray *MemorySpace;
};

#endif // RAM_H
