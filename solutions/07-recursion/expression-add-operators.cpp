#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string S;
    int T;
    int N;
    vector<string> ans;

    void solve(int idx, long long curr_val, long long last_op_val, string exp) {
        if (idx == N) {
            if (curr_val == T) {
                ans.push_back(exp);
            }
            return;
        }

        for (int i=idx; i<N; i++) {
            if (i > idx && S[idx] == '0') {
                break;
            }

            string operand_str = S.substr(idx, i - idx + 1);
            long long operand_val = stoll(operand_str);

            if (idx == 0) {
                solve(i + 1, operand_val, operand_val, operand_str);
            } else {
                solve(i + 1, curr_val + operand_val, operand_val, exp + "+" + operand_str);
                solve(i + 1, curr_val - operand_val, -operand_val, exp + "-" + operand_str);
                solve(i + 1, curr_val - last_op_val + (last_op_val * operand_val), last_op_val * operand_val, exp + "*" + operand_str);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        S = num;
        T = target;
        N = num.length();
        ans.clear();

        solve(0, 0, 0, "");
        return ans;
    }
};
