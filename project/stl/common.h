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

struct Node{
    int data;
    struct Node* next;
    struct Node* prior;
};

typedef struct Node Node;
typedef int Data;


#endif /* Node_h */
