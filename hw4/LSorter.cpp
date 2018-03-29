#include "LSorter.h"
#include <iostream>
using namespace std;

//collaborator: Hannah Hebert
//Spring 2016 EC330 HW4
  
LNode* LSorter::sortList(LNode* head){
    int listSize = 1;
	int numMerges, leftSize, rightSize; //use to do size comparisons as the linked list is sorted
    LNode *tail, *left, *right, *next; //use pointers to the different 
    
    if (!head || !head->next){ //checks to make sure input node pointer is not null or if only one node in list, returns it
        return head;  //returns the original passed

    }
    
    do{
        numMerges = 0; //keeps track of merge count
        left = head; //left node is the node passed to list
        tail = 0; //tail is a null ptr
        head = 0; //change the head to null 
        
        while (left){ // Do this list_len/listSize times:
            numMerges++;
            right = left;
            leftSize = 0;
            rightSize = listSize;
         
            while (right && leftSize < listSize){ // cut the list into two halves
                leftSize++;
                right = right->next;
            }
         
            while (leftSize > 0 || (rightSize > 0 && right)) { //run through lists and append onto them
                if (!leftSize){ //if left is empty, take the right
                    next = right;
                    right = right->next;
                    rightSize--;
                }
                
                else if (!rightSize || !right){ //if right is empty, take the left
                    next = left;
                    left = left->next;
                    leftSize--;
                }
                else if (right->val > left->val){//compare the right value with left val
                    next = left;
                    left = left->next;
                    leftSize--;
                }
                else {
                    next = right;
                    right = right->next;
                    rightSize--;
                }
                // Update pointers to keep track of where we are:
                if (tail){
                    tail->next=next;
                }
                else {
                    head=next;
                }
                // Sort prev pointer
                tail=next;
            }
            
            // Right is now AFTER the list we just sorted, so start the next sort there.
            left=right;
        }
        
        tail->next = 0; //terminates list
        listSize <<= 1; //this doubles the size of the list sort (adds the 2^n)
		cout << "list size: " << listSize << endl;
        
    } while (numMerges > 1); // If we only did one merge, then we just sorted the whole list.

    return head; //return sorted version of linked list
}
