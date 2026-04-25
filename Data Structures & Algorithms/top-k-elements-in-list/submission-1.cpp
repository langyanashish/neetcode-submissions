class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> mp;
        for(int n : nums)
            mp[n]++;
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
