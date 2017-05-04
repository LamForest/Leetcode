/*
23. Merge k Sorted Lists
Time: 2017 - 5 - 4
Difficulty: Hard
Method: Divide and Conquer, Recursion
url: https://leetcode.com/problems/merge-k-sorted-lists/#/description
Runtime: 29 ms, beats 70.21% cpp submissions.
*/

/***********
学到的：
1. 不能引用一个匿名变量
2. vector可以用两个迭代begin, end初始化，范围为[begin, end) C++98
************/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //归并的方式

        int num = lists.size();

        //cout << num << endl;
        //Divide: split the lists until only 2 list
        ListNode *a, *b;
        if(num > 2){
            int mid = num / 2;
            //错误的做法，不能够对一个匿名变量做引用
            //Wrong!! Compile Error : mergeKLists(vector<ListNode*>(lists.begin(), lists.begin() + mid);)
            vector<ListNode*> va = vector<ListNode*>(lists.begin(), lists.begin() + mid);
            a = mergeKLists(va);
            vector<ListNode*> vb = vector<ListNode*>(lists.begin() + mid, lists.end() );
            b = mergeKLists(vb);
            lists = vector<ListNode*>();
            lists.push_back(a);
            lists.push_back(b);
        }

        //Conquer: merge 2 lists(maybe 1 list)
        return merge2Lists(lists);


    }

    ListNode *merge2Lists(vector<ListNode*> &li){
        if(li.size() == 0){
            return NULL;
        }

        if(li.size() == 1){
            return li[0];
        }


        ListNode *re_head = new ListNode(-1); //这是一个假的头结点，方便迭代的处理

        ListNode *re = re_head;
        ListNode *a_head = li[0], *b_head = li[1];
        ListNode *a, *b;
        for(a = a_head, b = b_head; a != NULL && b!=NULL;){
            if(a->val < b->val){
                re->next = a;
                a = a->next;
                re = re->next;
            }else{
                re->next = b;
                b = b->next;
                re = re->next;
            }
        }

        //判断哪个链表由剩余部分
        ListNode *longer;
        if(a == NULL){
            longer = b;
        }else{
            longer = a;
        }

        //将链表的剩余部分直接插到最后
        while(longer){
            re->next = longer;
            longer = longer->next;
            re = re->next;
        }

        return re_head->next;
    }
};
