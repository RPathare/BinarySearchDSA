class Solution {
  public:
  int mini(vector<int>& bloomDay){
        int ansMini = 10000;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<ansMini){
                ansMini=bloomDay[i];
            }
        }
        return ansMini;
    }

     int maxi(vector<int>& bloomDay){
        int ansMaxi=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]>ansMaxi){
                ansMaxi=bloomDay[i];
            }
        }
        return ansMaxi;
     }
    int isPossible(vector<int>& bloomDay, int day,int m, int k){
          int n=bloomDay.size();
          int count=0;
          int buqute=0;
          for(int i=0;i<n;i++){
              if(bloomDay[i]<=day){
                count++;
              }else{
                 buqute+=(count/k);
                 count=0;
              }
          }
         buqute+=(count/k);
         return buqute>=m;
      }
    int solve(int M, int K, vector<int> &bloomDay){
     int low=mini(bloomDay);
        int high=maxi(bloomDay);
        int n=bloomDay.size();
        long long val= M * 1LL * K * 1LL;
        if(val > n){
            return -1;
        }
         while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(bloomDay,mid,M,K)){
                high=mid-1;
            }else{
                low=mid+1;
            }
         }
         return low;
    }
};