#include <sys/cdefs.h>

#include <stdio.h>

#include <stdarg.h>
#include <string.h>


int sprintf(char *str, char *fmt, ...) {
    #if defined __is_libk /* Building for kernel */

    va_list var_args;

    va_start(var_args, fmt);

    int n = 0;

    for (;*fmt != '\0';fmt++, n++) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt)
            {
            case 's': ;
                char *s_1 = va_arg(var_args, char*);
                for (;*s_1 != '\0';s_1++) {
                    str[n] = (*s_1);
                }
                break;
            case 'c': ;
                char c_1 = va_arg(var_args, int);
                str[n] = (c_1);    
                break;
            case 'd': ;
                int d_1 = va_arg(var_args, int);
                int d_2 = 0;
                for (;d_1 > 0;d_1 /= 10) {
                    d_2 *= 10;
                    d_2 += d_1%10;
                }
                for (;d_2 > 0; d_2 /= 10) {
                    str[n] = (d_2%10 + '0');
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
                        str[n] = (x_2%16 - 10 + 'a');
                    } else {
                        str[n] = (x_2%16 + '0');
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
                        str[n] = (X_2%16 - 10 + 'a');
                    } else {
                        str[n] = (X_2%16 + '0');
                    }
                    
                }
                break;
            default:
                str[n] = ('%');
                str[n] = (*fmt);
                break;
            }
        } else {
            str[n] = (*fmt);
        }
    }

    return n;

    #else                 /* Building for libc */

    /* Unused, just to satisfy --pedantic */

    fmt++;
    str++;

    return 0;


    #endif
}