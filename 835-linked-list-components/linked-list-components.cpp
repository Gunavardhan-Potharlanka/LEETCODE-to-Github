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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i:nums) mp[i]++;
        int ans=0;
        while(head!=NULL){
            if(mp[head->val]){
                while(head->next!=NULL && mp[head->next->val]) head=head->next;
                ans++;
            }
            head=head->next;
        }
        return ans;
    }
};