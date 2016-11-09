//
//  Node.h
//  xcodeC
//
//  Created by 张宝坤 on 16/10/6.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#ifndef Node_h
#define Node_h

typedef enum RESULT{
    ERROR,
    OK
}RESULT;

typedef void* Data;

struct Node{
    Data data;
    struct Node* next;
    struct Node* prior;
};

typedef struct Node Node;


struct TreeNode{
    Data data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;
typedef struct TreeNode* BinaryTree;
typedef struct TreeNode* BinarySearchTree;

#endif /* Node_h */
