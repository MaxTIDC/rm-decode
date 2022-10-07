#ifndef RM_DECODE_H
#define RM_DECODE_H

#define BIT_MASK 1
#include <stdint.h>
#include <stdbool.h>

enum RM_Type
{
  HALT,
  ADD,
  SUB
};

struct RM_Body
{
  enum RM_Type type;
  uint32_t i;
  uint32_t j;
  uint32_t k;
};

struct RM
{
  struct RM_Body *body;
  uint32_t line_count;
};

struct pair
{
  uint32_t x;
  uint32_t y;
  bool double_bracket;
};

typedef struct RM_Body RM_Body_t;
typedef struct RM RM_t;
typedef struct pair pair_t;

RM_t rm_decode (uint64_t);
uint32_t list_decode (uint64_t, uint32_t *);

void print_program (RM_t);
void print_coded_list (uint32_t, uint32_t *);

int computeLen (uint64_t index);

#endif