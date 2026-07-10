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

        // Better cache locality than vector<vector<int>>
        vector<array<int, 20>> up(n);

        const auto &a = nums;
        const auto &id = idx;

        for (int i = 0, left = 0; i < n; i++) {
            while (a[id[i]] - a[id[left]] > maxDiff)
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

            ans.push_back(up[y][0] <= x ? steps + 1 : -1);
        }

        return ans;
    }
};