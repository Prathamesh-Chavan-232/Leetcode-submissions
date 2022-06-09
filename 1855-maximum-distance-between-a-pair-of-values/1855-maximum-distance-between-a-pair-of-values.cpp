class Solution {
public:
int maxDistance(vector<int>& n1, vector<int>& n2) {

    int ans=0,k=min(n1.size(),n2.size());
    for(int i=0; i<k;i++){
            int l=i,r=n2.size()-1,m;
        while(l<=r){
            m=l+(r-l)/2;
            int t= n1[i];
            if(n2[m]>=t){
                l=m+1;
                if(m-i>ans)ans=m-i;
            } 
            else r=m-1;
        }  
    }
    return ans;
    }
};