class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<int> idx(n), pos(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(),
             [&](int a, int b) {
                 return nums[a] < nums[b];
             });

        for (int i = 0; i < n; i++)
            pos[idx[i]] = i;

        int LOG = __lg(n) + 1;

        vector<vector<int>> up(n, vector<int>(LOG));

        int left = 0;
        for (int i = 0; i < n; i++) {
            while (nums[idx[i]] - nums[idx[left]] > maxDiff)
                left++;
            up[i][0] = left;
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto &q : queries) {

            int x = pos[q[0]];
            int y = pos[q[1]];

            if (x > y)
                swap(x, y);

            if (x == y) {
                ans.push_back(0);
                continue;
            }

            int steps = 0;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[y][j] > x) {
                    y = up[y][j];
                    steps += (1 << j);
                }
            }

            if (up[y][0] <= x)
                ans.push_back(steps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};