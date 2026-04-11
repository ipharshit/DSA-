class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxwater=INT_MIN;
        while(i<=j){
            int height1=min(height[i],height[j]);
            int width=j-i;
            int water=height1*width;
            maxwater=max(maxwater,water);
            if(height[i]>height[j]){
                //chote vale ke upar se paani nikal jayega -> bada container chahiye
                j--;
            }
            else i++;
        }
        return maxwater;
    }
};