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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode(-1);
        ListNode* temp = list3;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
               temp->next = list2;
                list2 = list2->next;
            }
            
            temp = temp->next;
        }

        if(list1==NULL) temp->next = list2;
        else temp->next = list1;

        return list3->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()!=1){
            //worst T.C = o(nk^2)
            // ListNode* list1 = lists[lists.size()-1];
            // lists.pop_back();
            // ListNode* list2 = lists[lists.size()-1];
            // lists.pop_back();

            // better T.C = O(nklogk)
            ListNode* list1 = lists[0];
            lists.erase(lists.begin());
            ListNode* list2 = lists[0];
            lists.erase(lists.begin());

            ListNode* last = merge(list1, list2);
            lists.push_back(last);
        }
        return lists[0];
    }
};
