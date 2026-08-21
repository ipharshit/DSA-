class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sorting method
        sort(nums.rbegin(),nums.rend());
        return nums[k-1];
    }
};