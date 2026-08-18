class Solution {
public:
    long long minSum(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        int x=0;
        int y=0;
        long long k1=0,k2=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)x++;
            k1+=a[i];
        }

        for(int i=0;i<m;i++){
            if(b[i]==0)y++;
            k2+=b[i];
        }

        if(x==0 && y==0 && k1!=k2){
            return -1;
        }
        else{
            long long ans=-1;
            long long low=x;
            long long high=x*10000000000;

            while(low<=high){
                long long mid=(high-low)/2+low;

                if(k1+mid-k2>=y){
                    ans=mid;
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }
            if(k1+ans>=k2+y && k1+ans<=10000000000*y+k2){
                return k1+ans;
            }
            else return -1;

        }

    }
};
