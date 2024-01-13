#include <stdio.h>

typedef struct Node {
  int data;
  struct Node *next;
} node;

typedef node* list;

/*
  List creation: returns an empty list
*/
list lst_create(void);

/*
  List insertion: returns updated list
*/
list lst_insertion(list l, int value);

/*
  Element add: updates with no return
*/
void lst_add(list* l, int value);

/*
  Element add ascending order: updates list
*/
void lst_add_ord(list* l, int value);

/*
  List print: prints element list values
*/
void lst_print(list l);

/*
  List print: print all list element in a recursive way
*/
void lst_print_rec (list l);

/*
  List emptiness verification: return 1 if it's true
*/
int is_empty(list l);

/*
  List search: search for a given element in the list,
   returns a element node pointer or NULL
*/
list lst_search(list l, int value);

/*
  Element remove: pop removed element
*/
void lst_remove(list* l, int value);

/*
  Lists comparison: 1 if true, 0 if false
*/
int is_equal(list a, list b);

/*
  List copy: returns a copy of given list
*/
list mkcopy(list l);

/*
  Element insertion at the end of the list
*/
void list_add_end(list* l, int value);