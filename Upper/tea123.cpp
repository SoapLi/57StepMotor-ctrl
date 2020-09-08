#include "tea123.h"

TEA123::TEA123()
{

}

/*
*key  maybe 128bit =16 Bytes.
*buf  maybe BLOCK_SIZE
*/

void TEA123::btea_encrypt( unsigned char* buf, unsigned char* key )
{
    unsigned char n=BLOCK_SIZE/4;
    unsigned long *v=(unsigned long *)buf;
    unsigned long *k=(unsigned long *)key;
    unsigned long z = v[n - 1],y = v[0],sum = 0,e ;
    unsigned char p,q ;
    // Coding Part

    q = S_LOOPTIME + 52 / n ;
    while ( q-- > 0 )
    {
        sum += DELTA ;
        e = sum >> 2 & 3 ;
        for ( p = 0 ; p < n - 1 ; p++ )
          y = v[p + 1],
          z = v[p] += MX;
          y = v[0] ;
        z = v[n - 1] += MX;
    }
}


/*
*key  maybe 128bit =16Bytes.
*buf  maybe BLOCK_SIZE
inbuf == outbuf == buf
*/

void TEA123::btea_decrpyt( unsigned char* buf, unsigned char* key )
{
    unsigned char n=BLOCK_SIZE/4;
    unsigned long *v=(unsigned long *)buf;
    unsigned long *k=(unsigned long *)key;
    unsigned long z = v[n - 1],y = v[0],sum = 0,e ;
    unsigned char  p,q ;

    //Decoding Part...
    q = S_LOOPTIME + 52 / n ;
    sum = q * DELTA ;
    while ( sum != 0 )
    {
        e = sum >> 2 & 3 ;
        for ( p = n - 1 ; p > 0 ; p-- )
            z = v[p - 1],
            y = v[p] -= MX;
            z = v[n - 1] ;
        y = v[0] -= MX;
        sum -= DELTA ;
    }
}
