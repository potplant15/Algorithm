#include <vector> 
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> a,const vector<int> b){return a[0] < b[0];} );
        vector<vector<int> > res;res.reserve(intervals.size());
        int left = intervals[0][0];int right = intervals[0][1];
        intervals.push_back({10001,10001});
        for(int j = 1;j < intervals.size();j++){
            if(intervals[j][0] <= right) { right = max(right, intervals[j][1]); }
            else {
                res.push_back({left, right});
                left = intervals[j][0];
                right = intervals[j][1];
            }
        }
        return res;
    }
};
int main(){
	
}
