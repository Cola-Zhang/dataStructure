#include <stdio.h>
#include "Stack.h"
#include "LinkList.h"
#include "Queue.h"
#include "BinaryTree.h"
#include <string.h>
#include "tcpClient.h"
#include "tcpServer.h"
#include "BinarySearchTree.h"

void testStack(){
    Stack stack = stack_create();
    stack_push(stack, (Data*)1);
    stack_push(stack, (Data*)2);
    stack_push(stack, (Data*)3);
    stack_push(stack, (Data*)4);
    int number;
    stack_pop(stack, (Data*)&number);
    printf("stack pop number:%d\n", number);
    printf("stack size:%d\n", stack_getSize(stack));
    stack_debug(stack);
    stack_destroy(stack);
}

void testLinkList(){
    LinkList list = linkList_create();
    //1
    linkList_pushback(list, (Data*)1);
    //5 1
    linkList_pushback(list, (Data*)5);
    //5 2 1
    linkList_pushback(list, (Data*)2);
    //5 10 2 1
    linkList_pushback(list, (Data*)10);
    linkList_debug(list);
    Data data;
    linkList_remove(list,1, &data);
    linkList_remove(list,0, &data);
    linkList_pushback(list, (Data*)11);
    linkList_debug(list);
    linkList_destroy(list);
}

void testQueue(){
    Queue queue = queue_create();
    queue_add(queue, (Data*)1);
    queue_add(queue, (Data*)2);
    queue_add(queue, (Data*)3);
    queue_add(queue, (Data*)4);
    int number;
    queue_remove(queue, (Data*)&number);
    printf("removeQueue number:%d\n", number);
    queue_destroy(queue);
}


void testBinaryTree(){
    BinaryTree tree = binaryTree_create((Data*)1);
    TreeNode* left = binaryTree_insertLeft(tree, (Data*)2);
    binaryTree_insertLeft(left, (Data*)4);
    binaryTree_insertRight(left, (Data*)5);
    TreeNode* right =binaryTree_insertRight(tree, (Data*)3);
    binaryTree_insertLeft(right, (Data*)6);
    binaryTree_insertRight(right, (Data*)7);
    printf("======preorder1======\n");
    binaryTree_preorder(tree);
    printf("======preorder2======\n");
    binaryTree_preorder_loop(tree);
    printf("======inorder1======\n");
    binaryTree_inorder(tree);
    printf("======inorder2======\n");
    binaryTree_inorder_loop(tree);
    printf("======postorder1======\n");
    binaryTree_postorder(tree);
    printf("======postorder2======\n");
    binaryTree_postorder_loop(tree);
    printf("======leveOrder======\n");
    binaryTree_leveOrder(tree);
    printf("======free======\n");
    binaryTree_destroy(tree);
}

void testBinarySearchTree(){
    BinarySearchTree bst = binarySearchTree_create((Data*)100);
    binarySearchTree_insert(bst, (Data*)80);
    binarySearchTree_insert(bst, (Data*)70);
    binarySearchTree_insert(bst, (Data*)90);
    binarySearchTree_insert(bst, (Data*)120);
    binarySearchTree_insert(bst, (Data*)85);
    binarySearchTree_insert(bst, (Data*)140);
    binarySearchTree_insert(bst, (Data*)110);
    binaryTree_leveOrder(bst);
}

int main(int argc, const char * argv[]) {
    //testStack();
    //testLinkList();
    //testQueue();
    //tcpClient_connect("127.0.0.1", 8888);
    //tcpServer_socket(8888);
    //testBinaryTree();
    testBinarySearchTree();
    return 0;
}






