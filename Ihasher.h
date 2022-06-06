#ifndef IHASHER_H
#define IHASHER_H
#include<QString>
#include"Types.h"

class IHasher
{
public:
    virtual void init()  =0;
    virtual void update(const void* data,UInt32 size) =0;
    virtual QString final(Byte *digest) = 0;
    virtual UInt32 GetDigestSize() = 0;
};

#endif // IHASHER_H
