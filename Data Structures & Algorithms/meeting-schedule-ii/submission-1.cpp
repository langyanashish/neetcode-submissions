/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), []
        (auto& x, auto& y)
        {
            return x.start < y.start;
        });
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i < n; i++)
        {
            int start_i = intervals[i].start;
            int end_i = intervals[i].end;
            int end_top = minHeap.top();
            if(!minHeap.empty() && end_top <= start_i)
                minHeap.pop();
            minHeap.push(end_i);
        }
        return minHeap.size();
    }
};
