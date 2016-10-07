//
//  LinkList.c
//  xcodeC
//
//  Created by 张宝坤 on 16/10/7.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>


LinkList linkList_create(){
    LinkList linkList = (LinkList)malloc(sizeof(LinkListNode));
    Node* head = (Node*)malloc(sizeof(Node));
    linkList->head = head;
    head->next = head;
    head->prior = head;
    linkList->size = 0;
    return linkList;
}

RESULT linkList_insert(LinkList linkList, int index, Data data){
    Node* p;
    if(index == 0){
        p = linkList->head;
    }else{
        p = linkList_getPointer(linkList, index-1);
    }
    if(p){
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->next = p->next;
        p->next = node;
        node->prior = p;
        node->next->prior = node;
        linkList->size++;
        return OK;
    }
    return ERROR;
}

RESULT linkList_pushback(LinkList linkList, Data data){
    return linkList_insert(linkList, linkList_getSize(linkList), data);
}

RESULT linkList_get(LinkList linkList, int index, Data* data){
    Node* p = linkList_getPointer(linkList, index);
    if(p){
        *data = p->data;
        return OK;
    }
    return ERROR;
}

RESULT linkList_set(LinkList linkList, int index, Data data){
    Node* p = linkList_getPointer(linkList, index);
    if(p){
        p->data = data;
        return OK;
    }
    return ERROR;

}

RESULT linkList_remove(LinkList linkList, int index, Data* data){
    Node* p = linkList_getPointer(linkList, index);
    if(p){
        p->prior->next = p->next;
        p->next->prior = p->prior;
        linkList->size--;
        *data = p->data;
        free(p);
    }
    return ERROR;
}

RESULT linkList_pop(LinkList linkList, Data* data){
    if (linkList_isEmpty(linkList)){
        return ERROR;
    }
    return linkList_remove(linkList, linkList_getSize(linkList)-1, data);
}

bool linkList_isEmpty(LinkList linkList){
    return linkList->size == 0;
}

void linkList_clear(LinkList linkList){
    Node* p = linkList->head->next;
    Node* q;
    while (p != linkList->head){
        q = p;
        p = p->next;
        free(q);
    }
    linkList->head->prior = linkList->head->next = linkList->head;
    linkList->size = 0;
}

void linkList_destroy(LinkList linkList){
    Node* p = linkList->head->next;
    Node* q;
    while (p != linkList->head){
        q = p;
        p = p->next;
        free(q);
    }
    free(linkList->head);
    free(linkList);
}

int linkList_getSize(LinkList linkList){
    return linkList->size;
}


void linkList_debug(LinkList linkList){
    Node* p = linkList->head->next;
    printf("from head\n");
    while(p != linkList->head){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    p = linkList->head->prior;
    printf("from tail\n");
    while (p != linkList->head) {
        printf("%d ", p->data);
        p = p->prior;
    }
    printf("\n");
}

Node* linkList_getPointer(LinkList linkList, int index){
    if(index<0){
        return NULL;
    }
    int size = linkList_getSize(linkList);
    if(index>=size){
        return NULL;
    }
    Node* p;
    int curIndex;
    if(index<=size/2){
        curIndex = 0;
        p = linkList->head->next;
        while (p != linkList->head && curIndex<index){
            p = p->next;
            curIndex++;
        }
    }else{
        int curIndex = size-1;
        p = linkList->head->prior;
        while (p != linkList->head && curIndex>index){
            p = p->next;
            curIndex--;
        }
    }
    return p;
}


