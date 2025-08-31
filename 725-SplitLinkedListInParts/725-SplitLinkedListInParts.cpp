// Last updated: 8/31/2025, 10:49:41 AM
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* h = head;
        int ct = 0;
        while (h != NULL) {
            ct++;
            h = h->next;
        }
        int t = ct / k;
        int mod = ct % k;
        vector<ListNode*> vec(k, NULL);

        ListNode* curr = head;
        for (int i = 0; i < k && curr != NULL; i++) {
            vec[i] = curr;
            int partSize = t + (mod > 0 ? 1 : 0);
            mod--;
            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }
            ListNode* nextPart = curr->next;
            curr->next = NULL;
            curr = nextPart;
        }
        // ListNode* li=head;
        // for (int i=0;i<k && li!=NULL;i++)
        // {
        //     ListNode* temp=li;
        //     ListNode* prev=li;
        //     if (mod>0)
        //     {
        //         int t1=t+1;
        //         int t2=t;
        //         while (t2--)
        //         {
        //             prev=prev->next;
        //         }
        //         while (t1--)
        //         {
        //             temp=temp->next;
        //         }
        //         prev->next=NULL;
        //         vec.push_back(li);
        //         li=temp;
        //         prev=temp;
        //         mod--;
        //     }
        //     else
        //     {
        //         int t1=t;
        //         int t2=t;
        //         while (t2--)
        //         {
        //             prev=prev->next;
        //         }
        //         while (t1--)
        //         {
        //             temp=temp->next;
        //         }
        //         prev->next=NULL;
        //         vec.push_back(li);
        //         li=temp;
        //         prev=temp;
        //     }
        // }
        return vec;
    }
};