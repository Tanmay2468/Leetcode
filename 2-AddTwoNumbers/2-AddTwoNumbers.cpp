// Last updated: 8/31/2025, 10:50:39 AM
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1="";
        string s2="";
        ListNode* ptr=l1;
        while (ptr!=nullptr)
        {
            s1+=to_string(ptr->val);
            ptr=ptr->next;
        }
        ptr=l2;
        while (ptr!=nullptr)
        {
            s2+=to_string(ptr->val);
            ptr=ptr->next;
        }
        if (s1.length()<s2.length())
        {
            int temp=s2.length()-s1.length();
            while (temp--) s1+="0";
        }
        if (s1.length()>s2.length())
        {
            int temp=s1.length()-s2.length();
            while (temp--) s2+="0";
        }
        ListNode* head=nullptr;
        ListNode* curr=nullptr;
        bool carry=false;
        for (int i=0;i<s1.length();i++)
        {
            int bit1=stoi(s1.substr(i, 1));
            int bit2=stoi(s2.substr(i, 1));
            int num;
            if (carry)
            {
                num=(bit1+bit2+1)%10;
                if (bit1+bit2+1>=10) carry=true;
                else carry=false;
            }
            else
            {
                num=(bit1+bit2)%10;
                if (bit1+bit2>=10) carry=true;
                else carry=false;
            }
            ListNode* temp=new ListNode(num);
            if (head==nullptr)
            {
                head=temp;
                curr=head;
            }
            else
            {
                curr->next=temp;
                curr=curr->next;
            }
        }
        if (carry)
        {
            ListNode* temp=new ListNode(1);
            curr->next=temp;
            curr=curr->next;
        }
        return head;
    }
};