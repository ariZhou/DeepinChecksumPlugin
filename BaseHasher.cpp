#include "BaseHasher.h"
#include<QDebug>
baseHasher::baseHasher(){


}

 void  baseHasher::init(){

}
QString baseHasher::readFile(const QString &path,HashType ty){
    this->reset(ty);
    return this->readFile(path);
 }

QString baseHasher::readFile(const QString &path){
    QFile f(path);
    Byte c =0;


    if (f.open(QIODevice::ReadOnly)){
        QByteArray bt= f.read(15*1024);
        while(bt.isEmpty() == false){
            this->update(bt.constData(),(UInt32)bt.length());
            bt = f.read(15*1024);
        }
        return this->final(&c);
    }
    return  "";
 }
void baseHasher::update(const void *data, UInt32 size){
    md->addData((const char*)data,(int) size);
}
QString baseHasher::final(Byte *digest){
    QString r;
    r.append(md->result().toHex());
    return r;
}
baseHasher::~baseHasher(){
    if (md !=nullptr)
        delete  md;
}
UINT32 baseHasher::GetDigestSize(){
    return 0;
}
void baseHasher::reset(HashType ty){
    if(md !=nullptr){
        delete md;
    }
    if (ty == HashType::MD5){
        md= new  QCryptographicHash(QCryptographicHash::Md5);
    }
    else if(ty == HashType::SHA1){
        md = new QCryptographicHash(QCryptographicHash::Sha1);
    }
    else if(ty == HashType::SHA256){
        md = new QCryptographicHash(QCryptographicHash::Sha256);
    }
    else{
    }
}
