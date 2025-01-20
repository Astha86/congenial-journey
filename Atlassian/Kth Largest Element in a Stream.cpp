class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int> > pq; // min heap
    int K = 0;
    
    KthLargest(int k, vector<int>& nums) {

        int n = nums.size();
        K = k;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K) pq.pop();
        return pq.top();
    }
};
