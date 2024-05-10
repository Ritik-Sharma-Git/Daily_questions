class Solution {
public:
    typedef pair<double,pair<int,int>> pp;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        int n=arr.size();
        for(int i=0;i<n-1;i++) pq.push({double(arr[i])/arr[n-1],{i,n-1}});
        for(int i=0;i<k-1;i++){
            pp ans=pq.top();
            pq.pop();
            if(ans.second.second-1>ans.second.first){
                pq.push({(double)arr[ans.second.first]/arr[ans.second.second-1],{ans.second.first,ans.second.second-1}});
            }
        }
        return {arr[pq.top().second.first],arr[pq.top().second.second]};
        
    }
};