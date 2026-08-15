class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        int prev = 1e9;
        for (int i=0;i<n-2;i++) {
            if (nums[i] == prev) continue;
            prev = nums[i];
            int j=i+1, k=n-1;
            while (j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int x = nums[k];
                    while (k>j && nums[k] == x) k--;
                }
                else if (sum > 0) k--;
                else j++;
            }
        }
        return ans;
    }
};
