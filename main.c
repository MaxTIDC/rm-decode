#include <stdlib.h>
#include <stdio.h>
#include "rm_decode.h"

/* Main decode program. */
int main (int argc, char** argv)
{
	uint64_t index;

	if (argc < 1 || argv[1] == NULL || argv[1][0] == '-')
	{
		printf("Usage: ./rm_decode [encoding] \n - [encoding]: natrual (Goedel) number encoding for RM. \n");
		return -1;
	}

	/* Read encoding from input argument. */
	index = strtoul(argv[1], NULL, 10);

	RM_t rm = rm_decode (index);
  print_program (rm);
	free (rm.body);

	return 0;
}