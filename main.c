
/* You are not allowed to use <stdio.h> */
#include "io.h"
#include <stdlib.h>

/**
 * @name  main
 * @brief This function is the entry point to your program
 * @return 0 for success, anything else for failure
 *
 *
 * Then it has a place for you to implementation the command
 * interpreter as  specified in the handout.
 */
  /*-----------------------------------------------------------------
   *TODO:  You need to implement the command line driver here as
   *       specified in the assignment handout.
   *
   * The following pseudo code describes what you need to do
   *
   *  Declare the counter and the collection structure variables
   *
   *
   *  In a loop
   *    1) Read a command from standard in using read_char function
   *    2) If the command is not 'a', 'b', 'c': then break the loop
   *    3) Process the command as specified in the handout
   *  End loop
   *
   *  Print your collection of elements as specified in the handout
   *    as a comma delimited series of integers
   *-----------------------------------------------------------------*/
typedef struct {
  int *data;
  int size;
  int cap;
} indexList;

static void list(indexList *list) {
    list->cap = 8;
	list->size = 0;
	list->data = malloc(list->cap * sizeof(int));
}

static void push_List(indexList *list, int value) {
    if (list->size >= list->cap) {
	int newCap = (list->cap == 0) ? 1 : list->cap * 2;
    int *p = (int*)realloc(list->data, sizeof(int) * newCap);
	if (p == NULL) return; // realloc failed, keep using old buffer
        list->data = p;
		list->cap = newCap;
	}
	list->data[list->size++] = value;
}

static void free_List(indexList *list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->cap = 0;
}

static void pop_List(indexList *list) {
    if (list->size > 0) {
        list->size--;
    }
}

int main(void) {
indexList pos;
list(&pos);

int idx = 0;
int c;

while (1) {
c = read_char();
if (c == EOF) break;
if (c != 'a' && c != 'b' && c != 'c') break;

if (c  == 'a'){
		push_List(&pos, idx);
	} else if (c == 'b') {
		// do nothing
	} else if (c == 'c') {
    	pop_List(&pos);
	} else {
    	break;
	}
	idx++;
}

int first = 1;
int *p = pos.data;
int *end = pos.data + pos.size;

while (p < end) {
    if (!first) write_char(',');
    write_int(*p);
	first = 0;
	p++;
}
write_char(';');
write_char('\n');

free_List(&pos);
  return 0;
}
