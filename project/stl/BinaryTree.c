//
//  BinaryTree.c
//  test
//
//  Created by 张宝坤 on 2016/11/3.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#include "BinaryTree.h"
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

void binaryTree_destroy(BinaryTree tree){
    TreeNode* node = tree;
    if(node){
        binaryTree_destroy(node->left);
        binaryTree_destroy(node->right);
        printf("free %d\n", node->data);
        free(node);
    }
}


