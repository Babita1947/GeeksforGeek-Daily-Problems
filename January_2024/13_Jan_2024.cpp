//insertion Sort for Singly Linked List

#include<bits/stdc++.h>
using namespace std;

//Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

class Solution {
public:
    Node* insertionSort(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        Node* sortedHead = NULL;
        Node* current = head;

        while (current != NULL) {
            Node* nextNode = current->next;

            if (sortedHead == NULL || sortedHead->data > current->data) {
                current->next = sortedHead;
                sortedHead = current;
            } else {
                Node* temp = sortedHead;
                while (temp->next != NULL && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }

            current = nextNode;
        }

        return sortedHead;
    }
};