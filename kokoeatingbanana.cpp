class Solution {
  public:
  
  long long maxEle(vector<int>& piles){
        long long n=piles.size();
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++){
             if(piles[i]>maxi){
                maxi=piles[i];
             }
        }
        return maxi;
    }

    long long totalHour(vector<int>& piles, long long hours){
       long long totalH=0;
       long long n=piles.size();
       for(int i=0;i<n;i++){
        totalH+=ceil(piles[i] + hours - 1) / hours;
       }
       return totalH;
    }
  
  
    int KoKoEat(vector<int>& arr, int k) {
          long long low=0;
       long long high=maxEle(arr);
        while(low<=high){
           long long mid=(low+high)/2;
            long long totalHours=totalHour(arr,mid);
            if(totalHours<=k){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    
    }
};

