class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
         [&](vector<int> &first, vector<int> &second) {
           return first[1] < second[1];
         });
    int count = 1;
    int n = intervals.size();
    int prevE = intervals[0][1];
    for (int i = 1; i < n; i++) {
      if (intervals[i][0] >= prevE) {
        prevE = intervals[i][1];
        count++;
      }
    }

    return n - count;
    }
};