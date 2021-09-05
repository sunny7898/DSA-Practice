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
    ListNode* oddEvenList(ListNode* head) {
    
        if (head==NULL)
            return head;
        
        if (head -> next == NULL)
            return head;
        
        ListNode *odd_head = head;
        ListNode *even_head = head -> next;
        ListNode *even_tail = even_head;
        
        ListNode *temp = head;
        while (even_tail && even_tail -> next){
            odd_head -> next = even_tail -> next;
            odd_head = odd_head -> next;
            even_tail -> next = odd_head -> next;
            even_tail  = even_tail -> next;
            
        }
        odd_head -> next = even_head;
        odd_head = head;
        return odd_head;       
    }
};