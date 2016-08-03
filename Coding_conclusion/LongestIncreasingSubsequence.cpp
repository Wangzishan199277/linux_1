class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int m = nums.size();
        vector<int> temp(m, 0);
        int max = 0;
        for(int i = 0; i < m; i ++) {
            temp[i] = 1;
            for(int j = 0; j < i; j ++) {
                if(nums[j] < nums[i]) {
                    temp[i] = temp[j] + 1 > temp[i] ? (temp[j] + 1) : temp[i];
                }
            }
            if(temp[i] > max){
                max = temp[i];
            }
        }
        return max;
    }
};

