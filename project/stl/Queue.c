//
//  Queue.c
//  xcodeC
//
//  Created by 张宝坤 on 16/10/7.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#include "Queue.h"

Queue queue_create(){
    return linkList_create();
}

RESULT queue_add(Queue queue, Data data){
    return linkList_pushback(queue, data);
}

RESULT queue_remove(Queue queue, Data* data){
    return linkList_remove(queue, 0, data);
}

bool queue_isEmpty(Queue queue){
    return linkList_isEmpty(queue);
}

int queue_getSize(Queue queue){
    return linkList_getSize(queue);
}

void queue_clear(Queue queue){
    linkList_clear(queue);
}

void queue_destroy(Queue queue){
    linkList_destroy(queue);
}

void queue_debug(Queue queue){
    linkList_debug(queue);
}
