#ifndef BIGNUM_HELPERS_H
#define BIGNUM_HELPERS_H

#include <cstddef>
#include <cstdint>

namespace BigNumHelpers
{
void divideByTwo(char *str,size_t n);
size_t convert(const char *str, size_t n,uint8_t **result);
}


#endif
