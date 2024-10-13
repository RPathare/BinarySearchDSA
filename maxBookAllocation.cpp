class Solution {
  public:
  
  bool isValid(int arr[],long long  n, long long  m,long long maxAllowedPages){
      long long  student=1;
      long long pages=0;
      
      for(int i=0;i<n;i++){
          if(arr[i]>maxAllowedPages){
              return false;
          }
          
          if(pages + arr[i] <= maxAllowedPages){
              pages+=arr[i];
          }else{
              student++;
              pages=arr[i];
          }
      }
      
      return student>m?false:true;
  }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m>n){
            return -1;
        }
        long long  sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        long long  ans=-1;
        long long  st=0,end=sum;
        while(st <= end){
            long long  mid=st+(end-st)/2;
            
            if(isValid(arr,n,m,mid)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};