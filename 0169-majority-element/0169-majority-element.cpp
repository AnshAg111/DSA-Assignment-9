class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>m;
        int n=nums.size(), ans, max=0;
        for(int i=0; i<n; i++) m[nums[i]]++;
        for(auto i:m){
            if(max<i.second){
                max=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};