bool isPossible(vector<int> &stalls,int N,int k,int minAllowedDist){
	int cows=1,lastStallPos=stalls[0];
	
	for(int i=1;i<N;i++){
		if(stalls[i]-lastStallPos>=minAllowedDist){
			cows++;
			lastStallPos=stalls[i];
		}
		if(cows==k){
			return true;
		}
	}
	return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int N=stalls.size();
    sort(stalls.begin(),stalls.end());
	
	int st=1,end=stalls[N-1]-stalls[0];
    int ans=-1;
	
	while(st<=end){
		int mid=(st+end)/2;
		
		if(isPossible(stalls,N,k,mid)){
			ans=mid;
			st=mid+1;
		}else{
			end=mid-1;
		}
	}
	return ans;
}