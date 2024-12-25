#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int,int> >item(N);
    for ( int i = 0 ; i < N ; i++ ) cin >> item[i].first >> item[i].second;

    vector<vector<int> >dp(N+1, vector<int>(K+1,0));
    for ( int i = 1; i <= N; i++ ) {  
        int weight = item[i-1].first;
        int value = item[i-1].second;
        for ( int w = 1; w <= K ; w++) {
            if (w >= weight) dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight] + value); 
            else dp[i][w] = dp[i-1][w]; 
        }
    }
    cout << dp[N][K];
    return 0;
}