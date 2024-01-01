#include <bits/stdc++.h>
using namespace std;

int n, i, k, p, m, s;
vector<pair<int, int> >v;
int tree[500001];

int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, int num) {
    while (i <= n) {
        tree[i] += num;
        i += (i & -i);
    }
}

int main()
{
    scanf("%d", &n);
    for ( i = 0 ; i < n ; i++ )
    {
        scanf("%d", &m);
        v.push_back({m, i+1});
    }

    sort(v.begin(), v.end());
    for ( i = 0 ; i < n ; i++ )
    {
        v[i].first = i+1;
        swap(v[i].first, v[i].second);
    }

    sort(v.begin(), v.end());
    memset(tree, 0, sizeof(tree));
    for (int i = 0; i < n; i++) {
        int temp = v[i].second;
        cout << (i + 1) - sum(temp - 1) << "\n";
        update(temp, 1);
    }
    
    return 0;
}


