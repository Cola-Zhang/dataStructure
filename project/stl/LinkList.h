//
//  LinkList.h
//  xcodeC
//
//  Created by 张宝坤 on 16/10/6.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h
#include "common.h"
#include <stdbool.h>

typedef struct {
    Node* head;
    int size;
} LinkListNode, *LinkList;

LinkList linkList_create();

RESULT linkList_insert(LinkList linkList, int index, Data data);

RESULT linkList_pushback(LinkList linkList, Data data);

RESULT linkList_get(LinkList linkList, int index, Data* data);

RESULT linkList_set(LinkList linkList, int index, Data data);

RESULT linkList_remove(LinkList linkList, int index, Data* data);

RESULT linkList_pop(LinkList linkList, Data* data);

bool linkList_isEmpty(LinkList linkList);

void linkList_clear(LinkList linkList);

void linkList_destroy(LinkList linkList);

int linkList_getSize(LinkList linkList);

void linkList_debug(LinkList linkList);

Node* linkList_getPointer(LinkList linkList, int index);

#endif /* LinkList_h */
