#ifndef IHASHER_H
#define IHASHER_H
#include<QString>
typedef unsigned int UInt32;
typedef unsigned char Byte;
enum HashType{
    MD5,
    CRC32,
    CRC64,
    SHA1,
    SHA256
};
class IHasher
{
public:
    virtual void init()  =0;
    virtual void update(const void* data,UInt32 size) =0;
    virtual QString final(Byte *digest) = 0;
};

#endif // IHASHER_H
