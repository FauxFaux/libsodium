/*
version 20080914
D. J. Bernstein
Public domain.
*/

#include "api.h"
#include "crypto_core_hsalsa20.h"
#include "crypto_stream_salsa20.h"

static const unsigned char sigma[16] = {
    'e', 'x', 'p', 'a', 'n', 'd', ' ', '3', '2', '-', 'b', 'y', 't', 'e', ' ', 'k'
};

int crypto_stream(
        unsigned char *c,uint64_t clen,
  const unsigned char *n,
  const unsigned char *k
)
{
  unsigned char subkey[32];
  crypto_core_hsalsa20(subkey,n,k,sigma);
  return crypto_stream_salsa20(c,clen,n + 16,subkey);
}
