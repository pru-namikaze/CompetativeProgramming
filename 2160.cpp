//https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/submissions/
class Solution {
public:
    int minimumSum(int num) {
        vector<int> v{ num % 10, (num/10) % 10, (num/100) % 10, (num/1000) % 10};
        sort(v.begin(), v.end());
        return ((v.at(0) + v.at(1))* 10) + ((v.at(2) + v.at(3)));
    }
};
