#include <bits/stdc++.h>
using namespace std;

bool canObtainMarks(vector<int>& marks, int target) {
    int n = marks.size();
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = target; j >= marks[i]; j--) {
            dp[j] = dp[j] || dp[j - marks[i]];
        }
    }

    return dp[target];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> marks(n);
        for (int i = 0; i < n; i++) {
            cin >> marks[i];
        }

        if (canObtainMarks(marks, 1000 - m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
