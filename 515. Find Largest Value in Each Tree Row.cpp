
/*
515. Find Largest Value in Each Tree Row
Time: 2017 - 4 - 20
Difficulty: Hard
Method: Priority Queue
url: https://leetcode.com/problems/find-largest-value-in-each-tree-row/#/description
Runtime: 19ms, beats beats 15.86 % of cpp submissions.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        if(!root){
            return vector<int>();
        }

        int a[1000];
        a[0] = 1;
        int i;
        Q.push(root);
        for(i = 0;;i++){
            int num_nodes_next = iter(a[i], root);

            if(num_nodes_next == 0){
                break;
            }
            a[i+1] = num_nodes_next;
        }
        return solu;
    }

    vector<int> solu;
    queue<TreeNode*> Q;
    // return how many nodes in the next layer
    int iter(int it_time, TreeNode* root){
        int i;
        int num_nodes_next = 0;
        int max = INT_MIN;
        for(i = 0; i<it_time; i++){
            TreeNode* node;
            if(!Q.empty()){
                node = Q.front();
                Q.pop();
            }

            if(node->val > max){
                max = node->val;
            }

            if(node->left){
                Q.push(node->left);
                num_nodes_next++;
            }

            if(node->right){
                Q.push(node->right);
                num_nodes_next++;
            }
        }
        solu.push_back(max);
        return num_nodes_next;
    }
};
