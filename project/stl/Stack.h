//
//  Stack.h
//  xcodeC
//
//  Created by 张宝坤 on 16/10/6.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include "LinkList.h"

typedef LinkList Stack;

Stack stack_create();

RESULT stack_push(Stack stack, Data data);

RESULT stack_pop(Stack stack, Data* data);

RESULT stack_peek(Stack stack, Data* data);

bool stack_isEmpty(Stack stack);

int stack_getSize(Stack stack);

void stack_clear(Stack stack);

void stack_destroy(Stack stack);

void stack_debug(Stack stack);

#endif /* Stack_h */
