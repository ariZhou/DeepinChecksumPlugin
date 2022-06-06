#ifndef TYPES_H
#define TYPES_H
typedef wchar_t FChar;
typedef const FChar *CFSTR;
typedef unsigned int UInt32;
typedef unsigned char Byte;
enum HashType{
    MD5,
    CRC32,
    CRC64,
    SHA1,
    SHA256
};

#define MAX_PATHNAME_LEN   1024
#define FD_LINK (-2)
typedef int Int32;
typedef int INT;
typedef Int32 INT32;
typedef unsigned int UINT;
typedef UInt32 UINT32;
typedef INT32 LONG;
typedef UINT32 ULONG;
#ifndef __int64
#define __int64 long long
#endif
typedef unsigned __int64 UINT64;
typedef __int64 INT64;
typedef UINT32 DWORD;
typedef long long int Int64;
typedef unsigned long long int UInt64;
#define TRUE 1
#define FALSE 0

typedef enum tagSTREAM_SEEK
{
  STREAM_SEEK_SET = 0,
  STREAM_SEEK_CUR = 1,
  STREAM_SEEK_END = 2
} STREAM_SEEK;

enum
{
  k_HashCalc_Index_Current,
  k_HashCalc_Index_DataSum,
  k_HashCalc_Index_NamesSum,
  k_HashCalc_Index_StreamsSum
};

#define FILE_BEGIN	SEEK_SET
#endif // TYPES_H
