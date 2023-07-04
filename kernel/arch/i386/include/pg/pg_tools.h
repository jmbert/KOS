#ifndef  _PG_TOOLS
#define _PG_TOOLS

#include <pg/pg_types.h>

pframe_t *get_page_directory(void);

void set_page_directory(pframe_t *pdir);

#endif