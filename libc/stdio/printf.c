#include <stdio.h>

#include <stdarg.h>
#include <string.h>


void printf(char *s, ...) {
    #if defined __is_libk /* Building for kernel */

    va_list var_args;

    va_start(var_args, s);

    for (;*s != '\0';s++) {
        if (*s == '%') {
            s++;
            switch (*s)
            {
            case 's': ;
                char *s_1 = va_arg(var_args, char*);
                for (;*s_1 != '\0';s_1++) {
                    putc(*s_1);
                }
                break;
            case 'c': ;
                char c_1 = va_arg(var_args, int);
                putc(c_1);    
                break;
            case 'd': ;
                int d_1 = va_arg(var_args, int);
                int d_2 = 0;
                for (;d_1 > 0;d_1 /= 10) {
                    d_2 *= 10;
                    d_2 += d_1%10;
                }
                for (;d_2 > 0; d_2 /= 10) {
                    putc(d_2%10 + '0');
                }
                break;
            case 'x': ;
                int x_1 = va_arg(var_args, int);
                int x_2 = 0;
                for (;x_1 > 0;x_1 /= 16) {
                    x_2 *= 16;
                    x_2 += x_1%16;
                }
                for (;x_2 > 0; x_2 /= 16) {
                    if (x_2%16 > 9) {
                        putc(x_2%16 - 10 + 'a');
                    } else {
                        putc(x_2%16 + '0');
                    }
                    
                }
                break;
            case 'X': ;
                int X_1 = va_arg(var_args, int);
                int X_2 = 0;
                for (;X_1 > 0;X_1 /= 16) {
                    X_2 *= 16;
                    X_2 += X_1%16;
                }
                for (;X_2 > 0; X_2 /= 16) {
                    if (X_2%16 > 9) {
                        putc(X_2%16 - 10 + 'a');
                    } else {
                        putc(X_2%16 + '0');
                    }
                    
                }
                break;
            default:
                putc('%');
                putc(*s);
                break;
            }
        } else {
            putc(*s);
        }
    }

    #else                 /* Building for libc */

    #endif
}