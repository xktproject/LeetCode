/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int nCarry = 0;
        int nSum = 0;
        int nIsL1 = 1;
        ListNode * pL1 = l1;
        ListNode * pL2 = l2;
        ListNode * tmp = 0;
        ListNode * tmpLast = 0;
        ListNode * pLastL1 = l1;
        ListNode * pLastL2 = l2;
        while(pL1 != 0 && pL2 !=0)
        {
            nSum = (pL1->val + pL2->val + nCarry) % 10;
            nCarry = (pL1->val + pL2->val + nCarry) / 10;
            pL1->val = nSum;
            pL2->val = nSum;
            pLastL1 = pL1;
            pLastL2 = pL2;
            pL1 = pL1->next;
            pL2 = pL2->next;
        }
        if(pL1 != 0 || pL2 !=0)
        {
           nIsL1 = (pL1==0? 0:1);
            tmp = nIsL1? pL1:pL2;
            while(tmp != 0)
             {
                nSum = (tmp->val + nCarry) % 10;
                nCarry = (tmp->val + nCarry) / 10;
                tmp->val = nSum;
                tmpLast = tmp;
                tmp = tmp->next;
             }  
        }
        else
           tmpLast = pLastL1;
           
        if(nCarry > 0)
        {
            ListNode * pNode = new ListNode(1);
            tmpLast->next = pNode;
        }
        return nIsL1?l1:l2;
    }
};