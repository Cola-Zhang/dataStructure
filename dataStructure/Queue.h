//
//  Queue.h
//  xcodeC
//
//  Created by 张宝坤 on 16/10/7.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "LinkList.h"

typedef LinkList Queue;

Queue queue_create();

RESULT queue_add(Queue queue, Data data);

RESULT queue_remove(Queue queue, Data* data);

bool queue_isEmpty(Queue queue);

int queue_getSize(Queue queue);

void queue_clear(Queue queue);

void queue_destroy(Queue queue);

void queue_debug(Queue queue);

#endif /* Queue_h */
