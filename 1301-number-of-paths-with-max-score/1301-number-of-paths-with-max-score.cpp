#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;

        // dp[i][j] stores {max_score, path_count}
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));

        // Base case: Start at the bottom-right corner
        dp[n - 1][n - 1] = {0, 1};

        // Direction vectors for transitions: Down, Right, Diagonal Down-Right
        int dr[] = {1, 0, 1};
        int dc[] = {0, 1, 1};

        // Iterate backwards from bottom-right to top-left
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Skip obstacles and the starting cell processing
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }

                int max_score = -1;
                int path_count = 0;

                // Check all 3 incoming directions
                for (int d = 0; d < 3; ++d) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];

                    // Verify boundaries and reachability
                    if (ni < n && nj < n && dp[ni][nj].first != -1) {
                        int prev_score = dp[ni][nj].first;
                        int prev_paths = dp[ni][nj].second;

                        if (prev_score > max_score) {
                            max_score = prev_score;
                            path_count = prev_paths;
                        } else if (prev_score == max_score) {
                            path_count = (path_count + prev_paths) % MOD;
                        }
                    }
                }

                // If cell is reachable from at least one valid path
                if (max_score != -1) {
                    int current_val = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                    dp[i][j] = {max_score + current_val, path_count};
                }
            }
        }

        // Return final values if top-left corner is reached successfully
        if (dp[0][0].first == -1) {
            return {0, 0};
        }
        return {dp[0][0].first, dp[0][0].second};
    }
};
