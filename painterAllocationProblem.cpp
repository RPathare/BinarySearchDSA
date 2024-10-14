bool isPossible(vector<int> &boards,int n,int k,int maxTimeAllocated){
    int painter=1;
    int time=0;

    for(int i=0;i<n;i++){
        if(time+boards[i]<=maxTimeAllocated){
            time+=boards[i];
        }else{
            painter++;
            time=boards[i];
        }
    }
    return painter>k?false:true;
}



int findLargestMinDistance(vector<int> &boards, int k)
{
    int n=boards.size();
    int sum=0;
    int maxVal=-1;
    for(int i=0;i<n;i++){
        sum+=boards[i];
        maxVal=max(maxVal,boards[i]);
    }

    int st=maxVal,end=sum;
    int ans=-1;
    while(st<=end){
        int mid=(st+end)/2;

        if(isPossible(boards,n,k,mid)){//left
            ans=mid;
            end=mid-1;
        }else{//right
            st=mid+1;
        }
    }
    return ans;
}