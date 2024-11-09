/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head){
            return NULL;
        }
        stack<Node*>st;
        Node*temp=head;
        while(temp){
            if(temp->child!=NULL){
                if(temp->next!=NULL){
                     st.push(temp->next);
                }
                temp->next=temp->child;
                if(temp->next){
                    temp->next->prev=temp;
                }
                temp->child=NULL;
            }
            if(temp->next==NULL && !st.empty()){
                Node*temp2=st.top();
                st.pop();
                temp->next=temp2;
                if(temp2){
                    temp2->prev=temp;
                }

            }




            temp=temp->next;
        }
        return head;
    }
};