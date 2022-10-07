#include <stdlib.h>
#include <stdio.h>
#include "rm_decode.h"

/* Main decode program. */
int main (void)
{
	uint64_t index = (((uint64_t) 1) << 46) * 20483;

	RM_t rm = rm_decode (index);
  print_program (rm);
	free (rm.body);

	return 0;
}