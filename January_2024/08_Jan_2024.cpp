//Merge 2 sorted linked list in reverse order

#include<bits/stdc++.h>
using namespace std;

//The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};
class Solution
{
    public:
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        
        Node* head = new Node;
        Node* curr = head;
         while(node1 != NULL && node2 != NULL){
             if(node1->data <= node2->data){
                 curr->next = node1;
                 node1 = node1->next;
             }
             else{
                 curr->next = node2;
                 node2 = node2->next;
             }
             curr = curr->next;
         }
         
         if(node1 != NULL){
             curr->next = node1;
         }
         if(node2 != NULL){
             curr->next = node2;
             
         }
         // Reverser list
         Node* prev = NULL;
         Node* curr1 = head->next;
         
         while(curr1 != NULL){
             Node* temp ;
             temp = curr1->next;
             curr1->next = prev;
             prev = curr1;
             curr1 = temp;
         }
         return prev;
    }  
};
