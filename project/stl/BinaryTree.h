//
//  BinaryTree.h
//  test
//
//  Created by 张宝坤 on 2016/11/3.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include "common.h"
#include <stdio.h>

BinaryTree binaryTree_create(Data dt);

TreeNode* binaryTree_insertLeft(BinaryTree tree, Data dt);

TreeNode* binaryTree_insertRight(BinaryTree tree, Data dt);

void binaryTree_preorder(BinaryTree tree);

void binaryTree_preorder_loop(BinaryTree tree);

void binaryTree_inorder(BinaryTree tree);

void binaryTree_inorder_loop(BinaryTree tree);

void binaryTree_postorder(BinaryTree tree);

void binaryTree_postorder_loop(BinaryTree tree);

void binaryTree_leveOrder(BinaryTree tree);


void binaryTree_destroy(BinaryTree tree);

#endif /* BinaryTree_h */
