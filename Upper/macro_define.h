#ifndef MACRO_DEFINE_H
#define MACRO_DEFINE_H

#define MX                (z>>5^y<<2)+(y>>3^z<<4)^(sum^y)+(k[p&3^e]^z)
#define DELTA             0x9e3779b9
#define S_LOOPTIME        1        //5
#define BLOCK_SIZE        31


static unsigned char TEA_key0[16]=
{
    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10
};



#define GET_DEV_ID_MODE 0


#endif // MACRO_DEFINE_H
