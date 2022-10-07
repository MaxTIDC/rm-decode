#include <stdlib.h>
#include <stdio.h>
#include "rm_decode.h"

static pair_t decode_pair (uint64_t, bool);
static RM_Body_t line_decode (uint32_t);

/* Register Machine Decoder.
 * Given any program index, find the corresponding RM. */
RM_t rm_decode (uint64_t index)
{
	uint32_t *coded_program = (uint32_t *) malloc (100 * sizeof (uint32_t));
	RM_t program;
	program.body = (RM_Body_t *) malloc (100 * sizeof (RM_Body_t));

	/* Decode index into list. */
	uint32_t line_count = list_decode (index, coded_program);
	program.line_count = line_count;

	// print_coded_list (line_count, coded_program);

	/* Now indicies[] contains coded program body. */
	for (int i = 0; i < line_count; i++)
	{
		program.body[i] = line_decode (coded_program[i]);
	}

	free (coded_program);
	return program;
}

/* ------------------------------------------------------------------------- */

/* Decodes natural number (program)
 * into program line. */
static RM_Body_t line_decode (uint32_t code)
{
	RM_Body_t body;

	if (code == 0) /* Just HALT. */
	{
		body.type = HALT;
	}
	else /* One of the jump instructions. */
	{
		pair_t big_pair = decode_pair (code, true);
		body.i = big_pair.x / 2;

		if (big_pair.x % 2 == 0) /* ADD jump. */
		{
			body.type = ADD;
			body.j = big_pair.y;
		}
		else /* SUB conditional jump. */
		{
			body.type = SUB;

			pair_t small_pair = decode_pair (big_pair.y, false);
			body.j = small_pair.x;
			body.k = small_pair.y;
		}
	}

	return body;
}

/* Decodes natural number (list)
 * into list of coded program lines. */
uint32_t list_decode (uint64_t program_index, uint32_t * const coded_program)
{
	uint32_t line_count = 0;

	/* Decode until program_index iz zero. */
	while (program_index != 0)
	{
		pair_t working_pair = decode_pair (program_index, true);

		coded_program[line_count] = working_pair.x;
		program_index = working_pair.y;

		line_count++;
	}

	/* Note: if program_index = 0, the program will be empty. */
	return line_count;
}

/* Helper function,
 * decode a natural number into a pair. */
static pair_t decode_pair (uint64_t code, bool double_bracket)
{
	pair_t pair;

	pair.x = 0;
	pair.y = 0;
	pair.double_bracket = double_bracket;

	if (!double_bracket) /* Single bracketed pair. */
	{
		code++;
	}

	/* Actual decode. */
	while (!(code & BIT_MASK))
	{
		code = code >> 1;
		pair.x++;
	}

	/* Here, we have reached a '1' bit in code. */
	pair.y = code >> 1;

	return pair;
}

/* Helper function,
 * proint list of coded program lines. */
void print_program (const RM_t program)
{
	printf ("RM program:\n");
	for (int c = 0; c < program.line_count; c++)
	{
		printf ("L%d: ", c);
		switch (program.body[c].type)
		{
			case HALT:
				printf ("HALT\n");
				break;
			case ADD:
				printf ("R%u(+) -> L%u\n", program.body[c].i, program.body[c].j);
				break;
			case SUB:
				printf ("R%u(-) -> L%u, L%u\n", program.body[c].i, program.body[c].j, program.body[c].k);
				break;
		}
	}

	return;
}

/* Helper function
 * print list of coded program lines. */
void print_coded_list (uint32_t line_count, uint32_t * const coded_program)
{
	printf ("Coded list:\n");
	for (int i = 0; i < line_count; i++)
	{
		printf ("L%d: %u\n", i, coded_program[i]);
	}

	return;
}