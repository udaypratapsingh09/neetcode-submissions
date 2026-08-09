class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        vector<int> bestValue(n);
        bestValue[0] = nums[0];
        bestValue[1] = nums[1];

        for (int i=2;i<n;i++) {
            bestValue[i] = nums[i] + bestValue[i-2];
            if (i != 2 && bestValue[i-3] > bestValue[i-2]) bestValue[i] = nums[i] + bestValue[i-3];
        }

        return max(bestValue[n-1], bestValue[n-2]);
    }
};
