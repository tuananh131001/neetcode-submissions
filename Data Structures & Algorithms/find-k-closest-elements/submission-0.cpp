class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         priority_queue<int, vector<int>, greater<int>> heap;
         for (int num: arr) {
            if (heap.size() < k){
                heap.push(num);
            } else if (abs(num-x) < abs(heap.top() - x) || 
            (abs(num-x) == abs(heap.top() - x) && (num < x))) {
                heap.pop();
                heap.push(num);
            }
         }
        vector<int> res;
        while (!heap.empty()) { 
            res.push_back(heap.top());
            heap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};