/*
23. Merge k Sorted Lists
Time: 2017 - 5 - 4
Difficulty: Hard
Method: Priority Queue
url: https://leetcode.com/problems/merge-k-sorted-lists/#/description
Runtime: 26ms, beats 90.26 % of cpp submissions
*/

/***********
学到的：
1. 如何使用priority_queue，如何改变堆的大小比较
2. 如何使用可调用对象
************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp{
    //默认的采用小于符号，得到大根堆，为了得到小根堆，这里应该用 大于
    bool operator()(ListNode* a, ListNode *b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* re_head = new ListNode(-1);
        ListNode*re = re_head;
        //这里不用range初始化比较好，可以避免将NULL入队列
        //priority_queue<ListNode *, vector<ListNode*>, cmp > Q(lists.begin(), lists.end());

        priority_queue<ListNode *, vector<ListNode*>, cmp > Q;

        int i;
        for(i = 0; i < lists.size(); i++){
            if(lists[i]) Q.push(lists[i]);
        }
        while(!Q.empty()){
            re->next = Q.top();
            re = re->next;
            Q.pop();
            if(re->next){
                Q.push(re->next);
            }

        }
        return re_head->next;
    }


};
