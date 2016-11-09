//
//  BinarySearchTree.h
//  test
//
//  Created by 张宝坤 on 2016/11/8.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "BinaryTree.h"
#include <stdio.h>

BinarySearchTree binarySearchTree_create(Data dt);

TreeNode* binarySearchTree_insert(BinarySearchTree bst, Data dt);

TreeNode* binarySearchTree_delete(BinarySearchTree bst, Data dt);

#endif /* BinarySearchTree_h */
