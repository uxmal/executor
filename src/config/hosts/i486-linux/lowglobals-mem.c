/* Copyright 1994 - 1997 by Abacus Research and
 * Development, Inc.  All rights reserved.
 */

#if !defined (OMIT_RCSID_STRINGS)
char ROMlib_rcsid_lowglobals_mem[] = "$Id: lowglobals-mem.c 63 2004-12-24 18:19:43Z ctm $";
#endif

#include "rsys/common.h"
#include "target-config.h"

#include <sys/types.h>
#include <sys/mman.h>

#include "rsys/memory_layout.h"
#include "rsys/assert.h"

void
mmap_lowglobals ()
{
  caddr_t addr;
  
  addr = mmap ((caddr_t) PAGE_ZERO_START,
	       PAGE_ZERO_SIZE,
	       PROT_READ | PROT_WRITE,
	       MAP_ANONYMOUS | MAP_FIXED | MAP_PRIVATE, -1, 0);
  gui_assert (addr == (caddr_t) PAGE_ZERO_START);
}
