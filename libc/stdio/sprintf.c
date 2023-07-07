#include <sys/cdefs.h>

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>


int sprintf(char *str, char *fmt, ...) {
    #if defined __is_libk /* Building for kernel */

    va_list var_args;

    va_start(var_args, fmt);

    int n = 0;

    for (;*fmt != '\0';fmt++) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt)
            {
            case 's': ;
                char *s_1 = va_arg(var_args, char*);
                for (;*s_1 != '\0';s_1++, n++) {
                    str[n] = (*s_1);
                }
                break;
            case 'c': ;
                char c_1 = va_arg(var_args, int);
                str[n] = (c_1);  
                n++;
                break;
            case 'd': ;
                uint32_t d_1 = va_arg(var_args, uint32_t);
                if (d_1 == 0) {
                    str[n] = '0';
                    n++;
                    break;
                }
                uint32_t d_2 = 0;
				size_t d_n_end0s = 0;
				uint32_t d_count_end0s = 1;
                for (;d_1 > 0;d_1 /= 10) {
                    d_2 *= 10;
                    d_2 += d_1%10;
					if (d_count_end0s) {
						if (d_1%10) {
							d_count_end0s = 0;
						} else {
							d_n_end0s++;
						}
					}
                }
                for (;d_2 > 0; d_2 /= 10, n++) {
                    str[n] = (d_2%10 + '0');
                }

				for (size_t i = 0; i < d_n_end0s; i++, n++) {
					str[n] = '0';
				}
                break;
            case 'x': ;
                uint32_t x_1 = va_arg(var_args, uint32_t);
                if (x_1 == 0) {
                    str[n] = '0';
                    n++;
                    break;
                }
                uint32_t x_2 = 0;
				size_t x_n_end0s = 0;
				uint32_t x_count_end0s = 1;
                for (;x_1 > 0;x_1 /= 16) {
                    x_2 *= 16;
                    x_2 += x_1%16;
					if (x_count_end0s) {
						if (x_1%16) {
							x_count_end0s = 0;
						} else {
							x_n_end0s++;
						}
					}
                }
                for (;x_2 > 0; x_2 /= 16, n++) {
                    if (x_2%16 > 9) {
                        str[n] = (x_2%16 - 10 + 'a');
                    } else {
                        str[n] = (x_2%16 + '0');
                    }
                    
                }

				for (size_t i = 0; i < x_n_end0s; i++, n++) {
					str[n] = '0';
				}
                break;
            case 'X': ;
                uint32_t X_1 = va_arg(var_args, uint32_t);
                if (X_1 == 0) {
                    str[n] = ('0');
                    break;
                }

                uint32_t X_2 = 0;
				size_t X_n_end0s = 0;
				uint32_t X_count_end0s = 1;
                for (;X_1 > 0;X_1 /= 16) {
                    X_2 *= 16;
                    X_2 += X_1%16;
					if (X_count_end0s) {
						if (X_1%16) {
							X_count_end0s = 0;
						} else {
							X_n_end0s++;
						}
					}
                }

				
				
                for (;X_2 > 0; X_2 /= 16, n++) {
                    if (X_2%16 > 9) {
                        str[n] = (X_2%16 - 10 + 'A');
                    } else {
                        str[n] = (X_2%16 + '0');
                    }
                }

				for (size_t i = 0; i < X_n_end0s; i++, n++) {
					str[n] = ('0');
				}
                break;
            default:
                str[n] = ('%');
                str[n] = (*fmt);
                n += 2;
                break;
            }
        } else {
            str[n] = (*fmt);
            n++;
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