// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long i=1, mid;
        while(i<=n){
            mid=(i+(long long)n)/2;
            if(isBadVersion(mid)){
                if(mid>1 && !isBadVersion(mid-1)) break;
                if(mid==1) break;
                n=mid-1;
            }
            else{
                if(isBadVersion(mid+1)) {
                    mid++;
                    break;
                };
                i=mid+1;
            }
        }
        return mid;
    }
};