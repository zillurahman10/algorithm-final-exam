#include <bits/stdc++.h>

using namespace std;

bool canDivideChocolates(int N, vector<int>& A) {
    int totalChocolates = 0;
    for (int i = 0; i < N; ++i) {
        totalChocolates += A[i];
    }
    if (totalChocolates % 2 != 0)
        return false;

    int halfChocolates = totalChocolates / 2;

    vector<bool> dp(halfChocolates + 1, false);
    dp[0] = true;

    for (int i = 0; i < N; ++i) {
        for (int j = halfChocolates; j >= A[i]; --j) {
            dp[j] = dp[j] || dp[j - A[i]];
        }
    }

    return dp[halfChocolates];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (canDivideChocolates(n, a))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
