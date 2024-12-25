#include <iostream>
using namespace std;

int main() {
    int dp[1500002] = {0};
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int period, price;
        cin >> period >> price;

        dp[i] = max(dp[i], dp[i-1]);

        if (i + period <= n + 1) 
            dp[i + period] = max(dp[i + period], dp[i] + price);
    }

    int max_profit = 0;
    for (int i = 1; i <= n+1; i++) {
        max_profit = max(max_profit, dp[i]);
    }

    cout << max_profit << endl;
    return 0;
}
