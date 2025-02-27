
#include "hashmap.h"
#include "shared.h"

#ifndef _DEFINES_H
#define _DEFINES_H

#define HINT_NONE  0
#define HINT_8BIT  1
#define HINT_16BIT 2
#define HINT_24BIT 3
#define HINT_32BIT 4

#define HINT_TYPE_NONE    0
#define HINT_TYPE_GIVEN   1
#define HINT_TYPE_DEDUCED 2

#define STACK_CALCULATE_DELAY 2
#define STACK_RETURN_LABEL 1024

#define STACK_NONE    0
#define STACK_INSIDE  1
#define STACK_OUTSIDE 2

#define INPUT_NUMBER_EOL           2
#define INPUT_NUMBER_ADDRESS_LABEL 3
#define INPUT_NUMBER_STRING        4
#define INPUT_NUMBER_STACK         5
#define INPUT_NUMBER_FLOAT         6

#define GET_NEXT_TOKEN_STRING         2
#define EVALUATE_TOKEN_NOT_IDENTIFIED 2
#define EVALUATE_TOKEN_EOP            6
#define DIRECTIVE_NOT_IDENTIFIED      9

#define OUTPUT_OBJECT  0
#define OUTPUT_LIBRARY 1
#define OUTPUT_NONE    2

#define ERROR_NONE 0
#define ERROR_LOG  1
#define ERROR_DIR  2
#define ERROR_NUM  3
#define ERROR_INC  4
#define ERROR_INB  5
#define ERROR_UNF  6
#define ERROR_INP  7
#define ERROR_STC  8
#define ERROR_WRN  9
#define ERROR_ERR 10
#define ERROR_FAI 11

/**************************************************************/
/* wla internal datatypes                                     */
/**************************************************************/

/* A - absolute section      */
/* c - stack (1 byte)        */
/* C - stack (2 bytes)       */
/* T - stack (3 bytes)       */
/* U - stack (4 bytes)       */
/* - - stack (9-bit short)   */
/* d - data (1 byte)         */
/* y - data (2 bytes)        */
/* z - data (3 bytes)        */
/* u - data (4 bytes)        */
/* D - data block (incbin)   */
/* O - origin                */
/* o - absolute origin       */
/* B - ROM bank              */
/* b - BASE                  */
/* L - label                 */
/* r - 16-bit reference      */
/* R - 8-bit pc ref          */
/* M - 16-bit pc ref         */
/* Q - 8-bit reference       */
/* q - 24-bit reference      */
/* V - 32-bit reference      */
/* * - 9-bit short reference */
/* S - section               */
/* s - end of section        */
/* x - dsb                   */
/* X - dsw                   */
/* h - dsl                   */
/* w - dsd                   */
/* E - end of file           */
/* f - file name id          */
/* k - line number           */
/* P - add_old = add         */
/* p - add = add_old         */
/* g - block (start)         */
/* G - block (end)           */
/* Y - symbol                */
/* Z - breakpoint            */
/* i - macro call start      */
/* I - macro call end        */
/* j - rept start            */
/* J - rept end              */
/* v - special case ID       */
/* t - namespace             */
/* n - 0-7 + label (2 bytes) */
/* N - 0-7 + stack (2 bytes) */
/* + - .bits [bits]: a [value] / b [label] / c [stack] */

/**************************************************************/
/* gb-z80                                                     */
/**************************************************************/

#ifdef GB

/* opcode types */

/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 3 - plain text 16b */
/* 8 - *           8b */
/* 9 - *          16b */

#define OP_SIZE_MAX 16
#define ARCH_STR "GB-Z80"
#define WLA_NAME "gb"

#endif

/**************************************************************/
/* superfx                                                    */
/**************************************************************/

#ifdef SUPERFX

/* opcode types */

/* 0  - plain text */
/* 1  - * (0-15)   */
/* 2  - e          */
/* 3  - * (0-15) x */
/* 4  - * (0-15) ? */
/* 5  - * (0-15) y */
/* 6  - * (0-15) * */
/* 7  - MOVE R*,#? - MACRO INSTRUCTION */
/* 8  - MOVE R*,(?) - MACRO INSTRUCTION */
/* 9  - MOVE (?),R* - MACRO INSTRUCTION */
/* 10 - MOVEB R*,(R*) - MACRO INSTURCTION */
/* 11 - MOVEB (R*),R* - MACRO INSTRUCTION */
/* 12 - MOVEW R*,(R*) - MACRO INSTURCTION */
/* 13 - MOVEW (R*),R* - MACRO INSTRUCTION */
/* 14 - ? * (0-15) */
/* 15 - y * (0-15) */

#define OP_SIZE_MAX 16
#define ARCH_STR "SuperFX"
#define WLA_NAME "superfx"

#endif

/**************************************************************/
/* 6502                                                       */
/**************************************************************/

#ifdef MCS6502

/* opcode types */

/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 3 - plain text 16b */
/* 4 - x (absolute)   */

#define OP_SIZE_MAX 12
#define ARCH_STR "6502"
#define WLA_NAME "6502"

#endif

/**************************************************************/
/* 65C02                                                      */
/**************************************************************/

#ifdef WDC65C02

/* opcode types */

/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 3 - plain text 16b */
/* 4 - x (absolute)   */
/* 5 - x-abs x-rel    */

#define OP_SIZE_MAX 12
#define ARCH_STR "WDC65C02"
#define WLA_NAME "65c02"

#endif

/**************************************************************/
/* 65CE02                                                     */
/**************************************************************/

#ifdef CSG65CE02

/* opcode types */

/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 3 - plain text 16b */
/* 4 - x (absolute)   */
/* 5 - x-abs x-rel    */

#define OP_SIZE_MAX 12
#define ARCH_STR "CSG65CE02"
#define WLA_NAME "65ce02"

#endif

/**************************************************************/
/* huc6280                                                    */
/**************************************************************/

#ifdef HUC6280

/* opcode types */

/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 3 - plain text 16b */
/* 4 - ? ? ?          */
/* 5 - x x            */
/* 6 - x ?            */
/* 7 - x (absolute)   */
/* 8 - x-abs x-rel    */

#define OP_SIZE_MAX 12
#define ARCH_STR "HUC6280"
#define WLA_NAME "huc6280"

#endif

/**************************************************************/
/* 6510                                                       */
/**************************************************************/

#ifdef MCS6510

/* opcode types */

/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 3 - plain text 16b */
/* 4 - x (absolute)   */

#define OP_SIZE_MAX 12
#define ARCH_STR "MSC6510"
#define WLA_NAME "6510"

#endif

/**************************************************************/
/* spc700                                                     */
/**************************************************************/

#ifdef SPC700

/* opcode types */

/* 0 - plain text   */
/* 1 - x            */
/* 2 - ?            */
/* 3 - x ~ (odd)    */
/* 4 - x ~ (even)   */
/* 5 - ~ (direct)   */
/* a - x x          [1, 2] */
/* b - x x          [2, 1] */
/* c - x ~ x (odd)  [1, 2] */
/* d - x ~ x (even) [1, 2] */
/* f - ? (13-bit) ~ */

#define OP_SIZE_MAX 12
#define ARCH_STR "SPC700"
#define WLA_NAME "spc700"

#endif

/**************************************************************/
/* z80                                                        */
/**************************************************************/

#ifdef Z80

/* opcode types */

/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 3 - plain text 16b */
/* 4 - x              */
/* 5 - x          24b */
/* 6 - ?          16b */
/* 7 - x x        16b */
/* 8 - *           8b */
/* 9 - *          16b */
/* a - * x        24b */

#define OP_SIZE_MAX 20
#define ARCH_STR "Z80"
#define WLA_NAME "z80"

#endif

/**************************************************************/
/* 6800                                                       */
/**************************************************************/

#ifdef MC6800

/* opcode types */

/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 3 - plain text 16b */
/* 4 - x (absolute)   */

#define OP_SIZE_MAX 12
#define ARCH_STR "MC6800"
#define WLA_NAME "6800"

#endif

/**************************************************************/
/* 6801                                                       */
/**************************************************************/

#ifdef MC6801

/* opcode types */

/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 3 - plain text 16b */
/* 4 - x (absolute)   */

#define OP_SIZE_MAX 12
#define ARCH_STR "MC6801"
#define WLA_NAME "6801"

#endif

/**************************************************************/
/* 6809                                                       */
/**************************************************************/

#ifdef MC6809

/* opcode types */

/* 0  - plain text  8b */
/* 1  - x              */
/* 2  - ?              */
/* 3  - plain text 16b */
/* 4  - x (absolute)   */
/* 5  - 8-bit signed operand, relative address */
/* 6  - 5-bit signed operand, absolute address + post op byte code */
/* 7  - 8-bit signed operand, relative address + post op byte code */
/* 8  - 16-bit operand + post op byte code */
/* 9  - plain text 8-bit + post op byte code */
/* 10 - exg / tfr */
/* 11 - pshs / pshu / puls / pulu */

#define OP_SIZE_MAX 16
#define ARCH_STR "MC6809"
#define WLA_NAME "6809"

#endif

/**************************************************************/
/* 8008                                                       */
/**************************************************************/

#ifdef I8008

/* opcode types */
 
/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 8 - *           8b */
 
#define OP_SIZE_MAX 12
#define ARCH_STR "I8008"
#define WLA_NAME "8008"

#endif

/**************************************************************/
/* 8080                                                       */
/**************************************************************/

#ifdef I8080

/* opcode types */
 
/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 8 - *           8b */
 
#define OP_SIZE_MAX 12
#define ARCH_STR "I8080"
#define WLA_NAME "8080"

#endif

/**************************************************************/
/* 65816                                                      */
/**************************************************************/

#ifdef W65816

/* opcode types */

/* 0 - plain text  8b */
/* 1 - x              */
/* 2 - ?              */
/* 3 - &              */
/* 4 - x/? (mem/acc)  */
/* 5 - x x            */
/* 6 - REP/SEP        */
/* 7 - x/? (index)    */
/* 8 - plain text 16b */
/* 9 - relative ?     */
/* a - x (absolute)   */

#define OP_SIZE_MAX 16
#define ARCH_STR "W65816"
#define WLA_NAME "65816"

#endif


#if defined(SUPERFX)

struct optcode {
  char *op;
  unsigned char type;
  unsigned char hex;
  unsigned char prefix;
  unsigned char min;
  unsigned char max;
};

#else

struct optcode {
  char *op;
  unsigned short hex;
  unsigned char type;
#if defined(Z80)
  unsigned char hex_x;
#endif
#if defined(Z80) || defined(GB) || defined(I8008) || defined(I8080)
  unsigned char value;
#endif
#if defined(MCS6502) || defined(WDC65C02) || defined(CSG65CE02) || defined(HUC6280) || defined(MCS6510) || defined(MC6800) || defined(MC6801) || defined(MC6809)
  unsigned char skip_8bit;
#endif
#if defined(W65816)
  unsigned char skip_xbit;
#endif
#if defined(MC6809)
  unsigned char addressing_mode_bits;
#endif
};

#endif


#ifndef WLA_NAME
  #error "Unknown WLA_NAME!"
#endif
#ifndef ARCH_STR
  #error "Unknown ARCH_STR!"
#endif

#define DEFINITION_TYPE_VALUE         0
#define DEFINITION_TYPE_STRING        1
#define DEFINITION_TYPE_STACK         2
#define DEFINITION_TYPE_ADDRESS_LABEL 3

struct definition {
  char   alias[MAX_NAME_LENGTH + 1];
  char   string[MAX_NAME_LENGTH + 1];
  double value;
  int    type;
  int    size;
};

struct after_section {
  char  alive;
  char  is_appendto;
  struct section_def *section;
  char  after[MAX_NAME_LENGTH + 1];
  struct after_section *next;
};

struct macro_argument {
  int type;
  double value;
  int start;
  char has_leading_hashtag;
  char string[MAX_NAME_LENGTH + 1];
};

struct macro_static {
  char name[MAX_NAME_LENGTH + 1];
  int  start;
  int  calls;
  int  filename_id;
  int  start_line;
  int  nargument_names;
  char **argument_names;
  struct macro_static *next;
};

struct macro_incbin {
  unsigned char *data;
  int swap;
  int position;
  int left;
};

#define MACRO_CALLER_NORMAL 0
#define MACRO_CALLER_DBM    1
#define MACRO_CALLER_DWM    2
#define MACRO_CALLER_DLM    3
#define MACRO_CALLER_DDM    4
#define MACRO_CALLER_INCBIN 5
#define MACRO_CALLER_FILTER 6

struct macro_runtime {
  struct macro_static *macro;
  int  macro_return_i;
  int  macro_return_line;
  int  macro_return_filename_id;
  int  supplied_arguments;
  int  caller;
  char string[MAX_NAME_LENGTH + 1];
  int  string_current;
  int  string_last;
  int  offset;
  struct macro_incbin *incbin_data;
  struct macro_argument **argument_data;
};

struct label_def {
  char label[MAX_NAME_LENGTH + 1];
  unsigned char section_status;
  unsigned char alive;
  unsigned char type;
  unsigned char symbol;
  int  section_id;
  int  special_id;
  int  address; /* in bank */
  int  bank;
  int  slot;
  int  base;
  int  filename_id;
  int  linenumber;
  int  bits_position;
  int  bits_to_define;
  struct section_def *section_struct;
  struct label_def *next;
};

struct section_def {
  char name[MAX_NAME_LENGTH + 1];
  int  alignment;
  int  offset;
  int  priority;
  int  address; /* in bank */
  int  keep;
  int  bank;
  int  base;
  int  slot;
  int  size;
  int  status; /* see SECTION_STATUS_* */
  int  bitwindow;
  int  window_start;
  int  window_end;
  int  alive;
  int  id;
  int  i;
  int  filename_id;
  int  advance_org;
  int  maxsize_status; /* ON/OFF */
  int  maxsize;
  int  listfile_items;
  int  *listfile_ints;
  char *listfile_cmds;
  unsigned char *data;
  struct namespace_def *nspace;
  struct map_t *label_map;
  struct section_def *next;
};

struct ext_include_collection {
  int count;
  int max_name_size_bytes;
  char **names;
};

struct incbin_file_data {
  struct incbin_file_data *next;
  char *data;
  char *name;
  int  size;
};

struct export_def {
  char   name[MAX_NAME_LENGTH + 1];
  struct export_def *next;
};

struct active_file_info {
  int    filename_id;
  int    line_current;
  char   namespace[MAX_NAME_LENGTH + 1];
  struct active_file_info *next;
  struct active_file_info *prev;
};

struct file_name_info {
  char   *name;
  int    id;
  unsigned long checksum;
  struct file_name_info *next;
};

struct slot {
  char name[MAX_NAME_LENGTH + 1];
  int  address;
  int  size;
  struct slot *next;
};

struct block {
  char name[MAX_NAME_LENGTH + 1];
  int  address;
  int  filename_id;
  int  line_number;
  struct block *next;
};

struct block_name {
  char name[MAX_NAME_LENGTH + 1];
  int  id;
  struct block_name *next;
};

struct stack {
  struct stack_item *stack;
  struct stack *next;
  int id;
  int position;
  int filename_id;
  int stacksize;
  int linenumber;
  int type;
  int bank;
  int slot;
  int relative_references;
  int base;
  int section_status;
  int section_id;
  int address;
  int special_id;
  int bits_position;
  int bits_to_define;
};

struct stack_item {
  int type;
  int sign;
  double value;
  char string[MAX_NAME_LENGTH + 1];
};

#define STRUCTURE_ITEM_TYPE_DATA            0
#define STRUCTURE_ITEM_TYPE_DOTTED          1
#define STRUCTURE_ITEM_TYPE_INSTANCEOF      2
#define STRUCTURE_ITEM_TYPE_UNION           3

struct structure_item {
  char name[MAX_NAME_LENGTH + 1];
  int type;
  int size;

  /* only for TYPE_INSTANCE */
  struct structure *instance;
  int num_instances;
  int start_from;

  /* only for TYPE_UNION; each union entry is stored as a structure. */
  struct structure *union_items;

  struct structure_item *next;
};

struct structure {
  char name[MAX_NAME_LENGTH + 1];
  struct structure_item *items;
  struct structure_item *last_item;
  int size;
  struct structure *next;
};

struct union_stack {
  struct structure *active_struct;
  struct structure *union_first_struct;
  int union_base_offset, max_enum_offset;
  struct union_stack *prev;
};

struct repeat_runtime {
  int start;
  int start_line;
  int counter;
  int repeats;
  char index_name[MAX_NAME_LENGTH + 1];
};

struct filepointer {
  char name[MAX_NAME_LENGTH + 1];
  char *filename;
  FILE *f;
  struct filepointer *next;
};

struct stringmap_entry {
  int bytes_length;
  unsigned char *bytes;
  int text_length;
  char *text;
  struct stringmap_entry *next;
};

struct stringmaptable {
  char name[MAX_NAME_LENGTH + 1];
  struct stringmap_entry *entries;
  struct stringmaptable *next;
};

#define TYPE_STRING            0
#define TYPE_VALUE             1
#define TYPE_LABEL             2
#define TYPE_STACK_CALCULATION 3

struct array {
  char name[MAX_NAME_LENGTH + 1];
  int size;
  int *data;
  struct array *next;
};

struct stack_item_priority_item {
  int op;
  int priority;
};

struct data_stream_item {
  char label[MAX_NAME_LENGTH + 1];
  int  section_id;
  int  address;
  struct data_stream_item *next;
};

#endif /* _DEFINES_H */

