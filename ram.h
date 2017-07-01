#ifndef RAM_H
#define RAM_H

#include <QMap>
#include <QByteArray>
#include <QDebug>
#include <QBitArray>

// Declaration of the Ram class
// Which holds the memory where
// The programm will be loaded
class RAM
{
public:
    // Constructor of the Ram
    RAM();
    // Destructor of the Ram
    ~RAM();
public:
    // Clears the memory any time
    // it is colled. So that
    // The items of the memory
    // will be Zero
    void                            ClearRam();
    // Reads an item for the m_MemorySpace
    // it needs an index for the item.
    const char*                     Read(const int AddressInRam);
    // Writes into the index of the m_MemorySpace
    // it needs 2 arguments first is the index to write
    // the secins is the actual value.
    void                            Write(const int AddressInRam, const QByteArray& ValueInMemAddress);

private:
    int                             m_Size;         // The Size that the ram will be
    QByteArray                      m_MemorySpace;  // The Memory space that will be used.
};

#endif // RAM_H
