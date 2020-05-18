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
     
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) 
            return head;
        ListNode* odd = head;
        ListNode* firstEven = head->next;
        ListNode* even = head->next;
        ListNode* oddItr = even->next;
        while(oddItr!=NULL) {
            ListNode* temp = oddItr->next;
            even->next = oddItr->next;
            oddItr->next = firstEven;
            odd->next = oddItr;
            odd = odd->next;
            even = even->next;
            if(temp!=NULL) 
                oddItr = temp->next;
            else 
                break;
        }
        return head;
    }
};
/*
ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *oddhead=head;
        ListNode *evenhead=head->next;
        ListNode *oddtail=NULL;
        ListNode *eventail=NULL;
        ListNode *temp1=head;
        ListNode *temp2=head->next;
         while(temp2){
            if(!eventail){
                cout<<temp2->next->val<<endl;
                cout<<temp2->next->next->val<<endl;
                eventail=temp2->next->next;
                evenhead->next=eventail;
                cout<<eventail->val;
            }
            else{
                //if(temp2->next)
                eventail->next=temp2->next;
                if(eventail->next)
                eventail=eventail->next;
            }
            //if(temp1->next)
            temp2=temp2->next;
        }
        while(temp1 && temp1->next){
            if(!oddtail){
                oddtail=temp1->next->next;
                oddhead->next=oddtail;
            }
            else{
                oddtail->next=temp1->next->next;
                if(oddtail->next)
                oddtail=oddtail->next;
            }
            //if(temp1->next)
            temp1=temp1->next;
        }
       
       // oddtail->next=evenhead;
       // if(eventail)
          // eventail->next=NULL; 
       // oddtail->next=NULL;
        return oddhead;
    }
*/