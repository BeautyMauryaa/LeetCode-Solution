class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pos, digit;
        vector<long long> prefixSum(n + 1, 0);

        // Store positions, digits and prefix sum
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i];
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
                prefixSum[i + 1] += s[i] - '0';
            }
        }

        int k = digit.size();

        // Powers of 10
        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix number
        vector<long long> prefNum(k + 1, 0);
        for (int i = 0; i < k; i++)
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            // Sum of non-zero digits
            long long sum = prefixSum[r + 1] - prefixSum[l];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L;

            // Number formed by non-zero digits
            long long x = (prefNum[R] - prefNum[L] * pow10[len] % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};