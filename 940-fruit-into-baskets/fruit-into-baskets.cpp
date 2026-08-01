class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int low=0;
        int high=0;
        int ans=1;
        while(high<fruits.size()){
            // hire kro
            mp[fruits[high]]++;
            while(mp.size()>2){
                // fire
                mp[fruits[low]]--;
                if(mp[fruits[low]]==0) mp.erase(fruits[low]);
                low++;
            }
            if(mp.size()<=2) ans=max(high-low+1,ans);
            high++;
        }
        return ans;
    }
};