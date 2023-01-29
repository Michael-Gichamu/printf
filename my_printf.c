#include <stdarg.h>
#include "main.h"

/**
 * @my_printf : A function that handles the d and i conversion specifiers
 * @args: A va_list pointing to the argument to be converted.
 * Return: 0.
 */

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    for (const char *p = format; *p; ++p) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
            case 'd':
            case 'i': {
                int i = va_arg(args, int);
                printf("%d", i);
                break;
            }
            default:
                putchar(*p);
                break;
        }
    }

    va_end(args);
}

