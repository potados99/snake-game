//
//  linkedList.h
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <stdlib.h>

#define DATATYPE int*

#define INDEX_OUT "Index out of range."
#define NODE_EMPTY "Node is empty."
#define LIST_EMPTY "List is empty."


#pragma mark - Structures

typedef DATATYPE element;

typedef struct Node {
    element data;
    struct Node * nextNode;
} Node;

typedef struct _List {
    Node * head;
    Node * last;
} _List;
typedef _List* List;

#pragma mark - List methods

List new_list(void);
void init_list(List list);
void list_append(List list, element value);
void list_delete(List list, int index);

#pragma mark - List functions

int list_isEmpty(List list);
int list_get_length(List list);
int get_safe_index(List list, const int index);
element list_get_value(List list, const int index);


#pragma mark - Node functions

Node *create_node(element value, Node *next);
Node *find_node(List list, const int index);
Node *find_last_node(List list);


#pragma mark - Utils

void error(char *mes);
int *new_point(int X, int Y);


#endif /* linkedList_h */
