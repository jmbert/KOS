#include <tools.h>

void write(uint8_t *buf, uint8_t *where, size_t n) {
	for (size_t i = 0; i < n; i++)  {
		*(where+i) = *(buf+i);
	}
}