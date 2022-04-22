#ifndef BASEHASHER_H
#define BASEHASHER_H

#include "ihasher.h"
#include<QCryptographicHash>
#include<QFile>
#include <QDir>
class baseHasher:public IHasher
{
public:
    baseHasher();
    virtual void update(const void* data,UInt32 size) ;
    virtual QString final(Byte *digest);
    virtual void init();
    virtual ~baseHasher();
    QString readFile(const QString &path, HashType hy);
    void reset(HashType ty);
private:
    QString readFile(const QString &path);
    QCryptographicHash *md = nullptr;
};

#endif // BASEHASHER_H
