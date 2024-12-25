#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> answer;

void search(int tmp, stack<pair<int, int>>& koi) {
    while (!koi.empty()) {
        if (koi.top().first >= tmp) {
            answer.push_back(koi.top().second);
            return;
        } else {
            koi.pop();
        }
    }
    answer.push_back(0);
    return;
}

int main() {
    int n;
    cin >> n;
    stack<pair<int, int>> koi;

    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        koi.push({tmp, i});
    }

    while (!koi.empty()) {
        int tmp = koi.top().first;
        koi.pop();
        search(tmp, koi);
    }

    for (auto it = answer.rbegin(); it != answer.rend(); ++it)  cout << *it << " ";
    
    return 0;
}
