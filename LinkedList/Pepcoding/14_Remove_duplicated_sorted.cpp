#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *temp = head;
        while (temp->next){
            if (temp -> val == (temp -> next) -> val){
                ListNode *store = temp -> next;
                temp -> next = store -> next;
                delete(store);
            }
            else {
                temp = temp -> next;
            }
        }
        return head;
    }
};