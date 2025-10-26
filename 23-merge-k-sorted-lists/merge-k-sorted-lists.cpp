/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//stl of minheap expects a comparator type
    struct comp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val; //smaller value has higher priority
            //a is greater than b so a has less priority
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<ListNode*,vector<ListNode*>,comp> minHeap;
        for(ListNode* head: lists){
            if(head) minHeap.push(head); //guarding null heads
        }
        ListNode* ansHead= new ListNode(0);
        ListNode* tail=ansHead;
        while(!minHeap.empty()){
            ListNode* topHead=minHeap.top();
            minHeap.pop();
            tail->next=topHead;
            tail=tail->next;
            if(topHead->next!=NULL){
                minHeap.push(topHead->next);
                
        }
        tail->next==NULL;
        }
        
        

        return ansHead->next;
    }
};