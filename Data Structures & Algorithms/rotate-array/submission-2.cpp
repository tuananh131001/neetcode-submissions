class Solution {
private:
    void reverse(int startIdx, int endIdx, vector<int>& elements) {
        // swap
        while (startIdx < endIdx) {
            int temp = elements[startIdx];
            elements[startIdx] = elements[endIdx];
            elements[endIdx] = temp;
            startIdx++;
            endIdx--;
        }
        return;
    }
public:
    void rotate(vector<int>& nums, int k) {
        int remain = k % nums.size();
        reverse(0, nums.size() - 1, nums);
        reverse(0, remain - 1,nums);
        reverse(remain, nums.size() - 1, nums);
        return;
    }
};