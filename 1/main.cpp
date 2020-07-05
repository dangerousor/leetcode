#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, vector<int>> dict;
        for (int i = 0; i != nums.size(); i++) {
            dict[nums[i]].push_back(i);
        }
        vector<int> result;
        for (int i = 0; i != nums.size(); i++) {
            auto tmp = dict.find(target - nums[i]);
            if (tmp != dict.end()) {
                if (target == 2 * nums[i]) {
                    if (tmp->second.size() == 2) {
                        result = tmp->second;
                        break;
                    }
                } else {
                    result.push_back(i);
                    result.push_back(tmp->second[0]);
                    break;
                }
            }
        }
        return result;
    }
};
