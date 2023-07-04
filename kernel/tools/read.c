#include <tools.h>

void read(uint8_t *buf, uint8_t *from, size_t n) {
	for (size_t i = 0; i < n; i++)  {
		*(buf+i) = *(from+i);
	}
}