//
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#include "linked_list.h"


#pragma mark - List methods

List new_list(void) {
    List list = (List)malloc(sizeof(_List));
    init_list(list);
    return list;
}


void init_list(List list) {
    list->head = NULL;
    list->last = NULL;
    return;
}

void list_append(List list, element value) {
	if (list_isEmpty(list)) {
		list->head = create_node(value, NULL);
        list->last = list->head;
        return;
    }
    
    Node *lastNode = find_last_node(list);
    Node *newNode = create_node(value, NULL);
    
    lastNode->nextNode = newNode;
    list->last = newNode;
    return;
}

void list_delete(List list, int index) {
    Node *toBeHead = list->head->nextNode;
    free(list->head);
    list->head = toBeHead;
}

#pragma mark - List functions

int list_isEmpty(List list) {
    return (list->head == NULL);
}

int list_get_length(List list) {
    if (list_isEmpty(list))
        return 0;
    
    Node *currentNode = list->head;
    register unsigned int currentIndex = 1;
    
    while (currentNode->nextNode != NULL) {
        currentNode = currentNode->nextNode;
        currentIndex ++;
    }
    
    return currentIndex;
}

int get_safe_index(List list, const int index) {
    unsigned const int length = list_get_length(list);
    unsigned int safeIndex = 0;
    
    if (index < 0) {
        if ((index * -1) > length)
            error(INDEX_OUT);
        safeIndex = length + index;
    } else {
        if (index > length - 1)
            error(INDEX_OUT);
        safeIndex = index;
    }
    
    return safeIndex;
}

element list_get_value(List list, int index) {
    Node *node = find_node(list, index);

    return node->data;
}


#pragma mark - Node functions

Node *create_node(element value, Node *next) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    
    newNode->data = value;
    newNode->nextNode = next;
    
    return newNode;
}

Node *find_node(List list, int index) {
    if (list_isEmpty(list))
        error(LIST_EMPTY);
    
    Node *currentNode = list->head;
    
    unsigned const int safeIndex = get_safe_index(list, index);
    register unsigned int i = 0;

    for (i = safeIndex; i != 0; i --) {
        currentNode = currentNode->nextNode;
        if (currentNode == NULL)
            error(NODE_EMPTY);
    }
    
    return currentNode;
}

Node *find_last_node(List list) {
    if (list_isEmpty(list))
        error(INDEX_OUT);
    
    Node *currentNode = (Node *)malloc(sizeof(Node));
    
    currentNode = list->head;
    
    while (currentNode->nextNode != NULL)
        currentNode = currentNode->nextNode;
    
    return currentNode;
}


#pragma mark - Utils

void error(char *mes) {
    fprintf(stderr, "%s\n", mes);
    exit(1);
}

int *new_point(int X, int Y) {
    int *point = (int *)malloc(sizeof(int) * 2);
    point[0] = X;
    point[1] = Y;
    return point;
}

