//
//  BinarySearchTree.c
//  test
//
//  Created by 张宝坤 on 2016/11/8.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "stdlib.h"

BinarySearchTree binarySearchTree_create(Data dt){
    return binaryTree_create(dt);
}

TreeNode* binarySearchTree_insert(BinarySearchTree bst, Data dt){
    Data targetDt;
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = dt;
    node->left = NULL;
    node->right = NULL;
    while(bst){
        targetDt = bst->data;
        if(targetDt>=dt){
            if(bst->left){
                bst = bst->left;
            }else{
                bst->left = node;
                return node;
            }
        }else{
            if(bst->right){
                bst = bst->right;
            }else{
                bst->right = node;
                return node;
            }
        }
    }
    return node;
}

TreeNode* binarySearchTree_delete(BinarySearchTree bst, Data dt){
    return NULL;
}


