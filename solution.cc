// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
//     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        int n = num.size();
        for(int i = 0; i < n-3; ++i) {
            while(i > 0 && i < n-3 && num[i] == num[i-1]) ++i;
            for(int j = i+1; j < n-2; ++j) {
                while(j > i+1 && j < n-2 && num[j] == num[j-1]) ++j;
                int k = j+1;
                int l = n-1;
                while(k < l) {
                    int sum = num[i]+num[j]+num[k]+num[l];
                    if(sum == target) {
                        vector<int> sol = {num[i], num[j], num[k], num[l]};
                        res.push_back(sol);
                        while(++k < l && num[k] == num[k-1]);
                        while(--l > k && num[l] == num[l+1]);
                    } else if(sum < target) {
                        ++k;
                    } else {
                        --l;
                    }
                }
            }
        }
        return res;
    }
};
