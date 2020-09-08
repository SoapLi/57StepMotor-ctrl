#ifndef TEA123_H
#define TEA123_H
#include "macro_define.h"

class TEA123
{
public:
    TEA123();

    static void btea_encrypt( unsigned char* buf, unsigned char* key );

    static void btea_decrpyt( unsigned char* buf, unsigned char* key );
};

#endif // TEA123_H
