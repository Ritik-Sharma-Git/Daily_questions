class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq; 

    for (int h : happiness) {
      pq.push(h);
    }

    long long sum = 0;
    int cnt = 0;
    while (k--) {
      int top = pq.top()-cnt;
        pq.pop();
        if(top>0){
            sum+=top;
        }
        cnt++;
    }

    return sum;
        
    }
};