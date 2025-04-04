#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        nums.push_back(10000);
        nums.insert(nums.begin(),-10000);
        int left = 0;int right = nums.size()-1;
        int mid = 0;
        while(true){
            if(mid == left + (right - left)/2)return mid;

            mid = left + (right - left)/2;
            if(nums[mid] < target){
                left = mid;
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else{
                return mid-1;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int target;
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') break; // 检测到回车时停止输入
    }
    cin >> target;
    int result = sol.searchInsert(nums, target);
    cout << "Insert position of " << target << " is " << result << endl;
    return 0;
}
