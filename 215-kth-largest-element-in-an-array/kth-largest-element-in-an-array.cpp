class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // heap method
        priority_queue<int,vector<int>,greater<int>>pq; // min heap
        // arrrange 1st k elements in the min-heap
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        // now compare remaining with the top(smallest)
        for(int i=k;i<nums.size();i++){
            if(nums[i]<pq.top()){
                // yeh to kabhi answer ban hi nahi  sakt abecause
                // yeh mere top se chota h -> aur niche to sab top se bhi bde h
                continue;
            }
            else{
                // yeh mere top se bada h
                // it can be my ans
                pq.pop();
                pq.push(nums[i]);
            }
        }
    return pq.top();
    }
};