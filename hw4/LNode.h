#ifndef LNode_H  
#define LNode_H

#include <stdio.h>

class LNode {
public:
    int val;
    LNode* next;
    LNode(int x=0);
};

#endif /* LNode_hpp */
