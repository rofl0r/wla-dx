
#ifndef _STACK_H
#define _STACK_H

int get_label_length(char *l);
int stack_calculate(char *in, int *value);
int stack_create_label_stack(char *label);
int stack_create_stack_stack(int stack_id);
int resolve_stack(struct stack_item s[], int x);
int compute_stack(struct stack *sta, int x, double *result);

/* TODO: move these to their own file */
int data_stream_parser_free(void);
int data_stream_parser_parse(void);
struct data_stream_item *data_stream_parser_find_label(char *label);

#endif

