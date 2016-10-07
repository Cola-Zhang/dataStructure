//
//  Stack.c
//  xcodeC
//
//  Created by 张宝坤 on 16/10/6.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#include "Stack.h"
#include "stdlib.h"
#include "stdio.h"

Stack stack_create(){
    return linkList_create();
}

RESULT stack_push(Stack stack, Data data){
    return linkList_pushback(stack, data);
}

RESULT stack_pop(Stack stack, Data* data){
    return linkList_pop(stack, data);
}

bool stack_isEmpty(Stack stack){
    return linkList_isEmpty(stack);
}

int stack_getSize(Stack stack){
    return linkList_getSize(stack);
}

void stack_clear(Stack stack){
    linkList_clear(stack);
}

void stack_destroy(Stack stack){
    linkList_destroy(stack);
}

void stack_debug(Stack stack){
    linkList_debug(stack);
}
