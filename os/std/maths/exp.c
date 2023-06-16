/**
 * \file exp.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <std/maths.h>

uint64_t exp(uint64_t a, uint64_t b) {
    int res = 1;
    for (uint64_t i = 0; i < b; i++) {
        res *= a;
    }

    return res;
}