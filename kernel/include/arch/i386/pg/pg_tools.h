#ifndef  _PG_TOOLS_H
#define _PG_TOOLS_H

#include "pg_types.h"

pframe_t *get_page_directory(void);

void set_page_directory(pframe_t *pdir);

#endif