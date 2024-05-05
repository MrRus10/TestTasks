#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums;
    ifstream in("array.txt");
    int num = 0;
    if (in.is_open()) {
        while (in >> num) {
            nums.push_back(num);
        }
    }
    in.close();
    for (int i : nums) {
        cout << i << endl;
    }
    cout << endl;
    sort(nums.begin(), nums.end());
    int min_sum = 0;
    int m = 0;
    if (nums.size() % 2 == 0) {
        m = (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
    }
    else {
        m = nums[nums.size() / 2];
    }
    for (int i : nums) {
        min_sum += abs(i - m);
    }
    cout << min_sum << endl;
    return 0;
}