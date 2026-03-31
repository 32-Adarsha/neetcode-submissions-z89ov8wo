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
        int maxCount = 0;
        int count = 0;
        std::vector<int> _start;
        std::vector<int> _end;
        for(Interval meeting : intervals){
            _start.push_back(meeting.start);
            _end.push_back(meeting.end);
        }
        sort(_start.begin(), _start.end());
        sort(_end.begin() , _end.end());

        int l = 0;
        int r = 0;
        while(l < _start.size()){
            if(_start[l] < _end[r]){
                count++;
                l++;
            } else {
                count--;
                r++;
            }
            maxCount = max(maxCount , count);
        }
        return maxCount;


    }
};
