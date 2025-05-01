class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0;
        int right = min(tasks.size(), workers.size());
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canAssign(int mid, const vector<int>& tasks, const vector<int>& workers, int pills, int strength) {
        multiset<int> w(workers.end() - mid, workers.end());
    int p = pills;
    for (int i = mid - 1; i >= 0; i--) {
        auto fit = w.lower_bound(tasks[i]);
        if (fit != w.end()) {
            w.erase(fit);
        } else if (p) {
            fit = w.lower_bound(tasks[i] - strength);
            if (fit == w.end()) return false;
            w.erase(fit);
            p--;
        } else {
            return false;
        }
    }
    return true;
    }
};
