class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans={-1,-1};
        int i=0, n=nums.length, j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(j-i==1 && nums[j]==target){
                i=j;
                while(i>=0 && nums[i]==target) i--;
                ans[0]=i+1;
                while(j<n && nums[j]==target) j++;
                ans[1]=j-1;
                break;
            }
            if(nums[mid]<target) i=mid+1;
            else if(nums[mid]>target) j=mid-1;
            else{
                i=mid;
                j=mid;
                while(i>=0 && nums[i]==target) i--;
                ans[0]=i+1;
                while(j<n && nums[j]==target) j++;
                ans[1]=j-1;
                break;
            }
        }
        return ans;
    }
}