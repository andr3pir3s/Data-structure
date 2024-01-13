#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-list.h"

list lst_create(void) {
  return NULL;
}

list lst_insertion(list l, int value) {
  node* new = (node*) malloc(sizeof(node));
  new->data = value;
  new->next = l;
  return new;
}

void lst_add(list* l, int value) {
  node* new = (node*) malloc(sizeof(node));
  new->data = value;
  new->next = *l;
  *l = new;
}

void lst_print(list l) {
  list pointer;
  for (pointer = l; pointer != NULL; pointer = pointer->next){ 
    printf("[%d]->", pointer->data);
  }
  printf("\n");
}

void lst_print_rec(list l ) {
  if (is_empty(l)){
    printf("\n");
    return;
  }
  else {
    /*  Prints first element  */
    printf("[%d]->", l->data);
    /*  Prints sub-list  */
    lst_print_rec(l->next);
  }
}

list lst_search(list l, int value) {
  list pointer;
  for (pointer = l; pointer != NULL; pointer = pointer->next)
    if (pointer->data == value)
      return pointer;
  return NULL;
}

void lst_remove(list* l, int value) {
  list previous = NULL;
  list current = *l;

  while (current != NULL && current->data != value){
    previous = current;
    current = current->next;
  }

  if (previous == NULL)
    *l = current->next;
  else 
    previous->next = current->next;
  free(current);
}

void lst_add_ord(list* l, int value) {
  list previous = NULL;
  list current = *l;
  
  while (current != NULL && current->data < value){
    previous = current;
    current = current->next;
  }
  
  if (previous == NULL)
    lst_add(l, value);
  else {
    node* new = (node*) malloc(sizeof(node));
    new->data = value;

    new->next = previous->next;
    previous->next = new;
  }
}

void list_add_end(list* l, int value) {
  if (*l == NULL){
    lst_add(l, value);
  } else {
    list pointer = *l;
    node* new = (node*) malloc(sizeof(node));
    new->data = value;
    while (pointer->next != NULL)
      pointer=pointer->next;
    pointer->next = new;
  }
}

int is_empty(list l){
  return (l == NULL);
}

void lst_destroy(list l) {
  list current = l;
  while (current != NULL){
    list next = current->next;
    free(current);
    current = next;
  }
}

int is_equal(list a, list b) {
  while (a != NULL && b != NULL){
    if (a->data != b->data)
      return 0;
    a = a->next;
    b = b->next;
  }
  return (a == b);
}

list mkcopy(list l) {
  list copy = lst_create();
  for (; l != NULL; l = l->next)
    list_add_end(&copy, l->data);
  return copy;
}