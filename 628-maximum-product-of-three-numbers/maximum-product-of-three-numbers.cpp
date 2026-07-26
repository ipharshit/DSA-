class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int largest=INT_MIN;
        int second_Largest=INT_MIN;
        int third_Largest=INT_MIN;
        int smallest=INT_MAX;
        int second_Smallest=INT_MAX;
        for(int i=0;i<nums.size();i++){
            // find 3 largest
            if(nums[i]>largest){
                third_Largest=second_Largest;
                second_Largest=largest;
                largest=nums[i];
            }
            else if(nums[i]>second_Largest){
                third_Largest=second_Largest;
                second_Largest=nums[i];
            }
            else if(nums[i]>third_Largest) third_Largest=nums[i];
            //find 2 smaalest
            if(nums[i]<smallest){
                second_Smallest=smallest;
                smallest=nums[i];
            }
            else if(nums[i]<second_Smallest){
                second_Smallest=nums[i];
            }
        }
        int prod2=largest*smallest*second_Smallest;
        int prod1= largest*second_Largest*third_Largest;
        cout<<prod2<<" "<<prod1;
        return prod2>prod1?prod2:prod1;
    }
};