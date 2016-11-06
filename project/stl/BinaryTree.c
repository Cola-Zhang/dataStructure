//
//  BinaryTree.c
//  test
//
//  Created by 张宝坤 on 2016/11/3.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#include "BinaryTree.h"
#include "Queue.h"
#include "Stack.h"
#include <stdlib.h>

BinaryTree binaryTree_create(Data dt){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = dt;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* binaryTree_insertLeft(BinaryTree tree, Data dt){
    if(tree->left){
        printf("tree left exist error!\n");

        free(tree->left);
        tree->left = NULL;
    }
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = dt;
    node->left = NULL;
    node->right = NULL;
    
    
    tree->left = node;
    return node;
}

TreeNode* binaryTree_insertRight(BinaryTree tree, Data dt){
    if(tree->right){
        printf("tree right exist error!\n");
        free(tree->right);
        tree->right = NULL;
    }

    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = dt;
    node->left = NULL;
    node->right = NULL;
    tree->right = node;
    return node;
}

void binaryTree_preorder(BinaryTree tree){
    if(tree){
        printf("data %d\n", (int)tree->data);
        binaryTree_preorder(tree->left);
        binaryTree_preorder(tree->right);
    }
}

void binaryTree_preorder_loop(BinaryTree tree){
    Stack stack = stack_create();
    TreeNode* node = tree;
    while (node || !stack_isEmpty(stack)) {
        while(node){
            printf("data %d\n", (int)node->data);
            stack_push(stack, node);
            node = node->left;
        }
        if(!stack_isEmpty(stack)){
            stack_pop(stack, (Data*)&node);
            node = node->right;
        }
    }
    stack_destroy(stack);
}

void binaryTree_inorder(BinaryTree tree){
    if(tree){
        binaryTree_inorder(tree->left);
        printf("data %d\n", (int)tree->data);
        binaryTree_inorder(tree->right);
    }
}

void binaryTree_inorder_loop(BinaryTree tree){
    Stack stack = stack_create();
    TreeNode* node = tree;
    while (node || !stack_isEmpty(stack)) {
        while(node){
            
            stack_push(stack, node);
            node = node->left;
        }
        if(!stack_isEmpty(stack)){
            stack_pop(stack, (Data*)&node);
            printf("data %d\n", (int)node->data);
            node = node->right;
        }
    }
    stack_destroy(stack);
}

void binaryTree_postorder(BinaryTree tree){
    if(tree){
        binaryTree_postorder(tree->left);
        binaryTree_postorder(tree->right);
        printf("data %d\n", (int)tree->data);
    }
}

void binaryTree_postorder_loop(BinaryTree tree){
    Stack stack = stack_create();
    TreeNode* lastVisitNode = NULL;
    TreeNode* node = tree;
    while(node || !stack_isEmpty(stack)){
        while (node) {
            stack_push(stack, node);
            node = node->left;
        }
        stack_peek(stack, (Data*)&node);
        if(!stack_isEmpty(stack)){
            if(!node->right || node->right == lastVisitNode){
                printf("data %d\n", (int)node->data);
                lastVisitNode = node;
                stack_pop(stack, (Data*)&node);
                node = NULL;
            }else{
                node = node->right;
            }
        }
    }
}

void binaryTree_leveOrder(BinaryTree tree){
    Queue queue = queue_create();
    TreeNode* node = NULL;
    queue_add(queue, (Data)tree);
    while(!queue_isEmpty(queue)){
        queue_remove(queue, (Data*)&node);
        printf("data %d\n", (int)(((TreeNode*)node)->data));
        if(node->left){
            queue_add(queue, node->left);
        }
        if(node->right){
            queue_add(queue, node->right);
        }
    }
    queue_destroy(queue);
}


void binaryTree_destroy(BinaryTree tree){
    if(tree){
        binaryTree_destroy(tree->left);
        binaryTree_destroy(tree->right);
        free(tree);
    }
}


