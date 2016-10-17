#include <stdio.h>
#include "Stack.h"
#include "LinkList.h"
#include "Queue.h"
#include <string.h>
#include "tcpClient.h"
#include "tcpServer.h"

void testStack(){
    Stack stack = stack_create();
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_push(stack, 4);
    int number;
    stack_pop(stack, &number);
    printf("stack pop number:%d\n", number);
    printf("stack size:%d\n", stack_getSize(stack));
    stack_debug(stack);
    stack_destroy(stack);
}

void testLinkList(){
    LinkList list = linkList_create();
    //1
    linkList_pushback(list, 1);
    //5 1
    linkList_pushback(list, 5);
    //5 2 1
    linkList_pushback(list, 2);
    //5 10 2 1
    linkList_pushback(list, 10);
    linkList_debug(list);
    Data data;
    linkList_remove(list,1, &data);
    linkList_remove(list,0, &data);
    linkList_pushback(list, 11);
    linkList_debug(list);
    linkList_destroy(list);
}

void testQueue(){
    Queue queue = queue_create();
    queue_add(queue, 1);
    queue_add(queue, 2);
    queue_add(queue, 3);
    queue_add(queue, 4);
    int number;
    queue_remove(queue, &number);
    printf("removeQueue number:%d\n", number);
    queue_debug(queue);
    queue_destroy(queue);
}



int main(int argc, const char * argv[]) {
    //testStack();
    //testLinkList();
    //testQueue();
    //tcpClient_connect("127.0.0.1", 8888);
    tcpServer_socket(8888);
    return 0;
}






