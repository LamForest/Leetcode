/*
62. Unique Paths
Time: 2017 - 4 - 20
Difficulty: Medium（简单的动态规划）
Method: Dynamic Programming(A very basic and easy Dynamic Programming)
url: https://leetcode.com/problems/unique-paths/#/description
Runtime: 3ms, beats beats 10 % of cpp submissions.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0){
            return 1;
        }

        int a[m+1][n+1];
        int i;
        int j;
        for(i = 0; i < m+1; i++){
            a[i][0] = 0;
        }

        for(i = 0; i < n+1; i++){
            a[0][i] = 0;
        }

        a[1][0] = 1;

        for(i = 1; i < m+1; i++){
            for(j = 1; j < n+1; j++){
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        return a[m][n];
    }


};
