 
#include <iostream>
#include <string>
using namespace std;

int g, n;
int cnt = 0, ans = 0;
char cur;
string s, w;
int char_w[128], char_s[128];

void solution() 
{
	cin >> g >> n >> w >> s;
	for (int i = 0; i < g; i++) 
		++char_w[w[i]];
	
    
	for (int i = 0; i < g; i++) 
    {
		cur = s[i];
		++char_s[cur];
		if (char_s[cur] <= char_w[cur]) ++cnt;
	}

	if (cnt >= g) ++ans;

	for (int i = g; i < n; i++) 
    {
		cur = s[i - g];
        
		if (char_w[cur] && char_s[cur] <= char_w[cur])
         --cnt;

		--char_s[cur];
		cur = s[i];
		++char_s[cur];
		if (char_w[cur] && char_s[cur] <= char_w[cur]) 
            ++cnt;
            
		if (cnt >= g) 
            ++ans;
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solution();

	return 0;
}
/* 
//라빈카프로 구현한 거, 사실 구현을 제대로 못했지만 애초에 라빈카프로 안되는거였다
#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int w_size, s_size, result=0;
    cin >> w_size >> s_size;

    string W_string;
    string S_string;

    cin >> W_string;
    cin >> S_string;
    
    int key=3, w_hash=0;

    vector<pair<int, int>> pigeon(27, make_pair(0, 0));
    vector<int> visit;
    
    for ( int i = 0 ; i < w_size ; i++ )
    {
        if ( W_string[i] >= 'a' && W_string[i] <= 'z' )
        {
            
            w_hash += W_string[i]-96;
            pigeon[W_string[i]-96].first += 1;
            pigeon[W_string[i]-96].second += 1;
            visit.push_back(W_string[i]-96);
        }
        else
        {
            w_hash += W_string[i]-64;
            pigeon[W_string[i]-64].first += 1;
            pigeon[W_string[i]-96].second += 1;
            visit.push_back(W_string[i]-64);
        }
    }
    
    for ( int i = 0 ; i <= s_size - w_size ; i++ )
    {
        int s_hash=0, cnt=0;
        for ( int j = i ; j < i + w_size ; j++ )
        {
            if ( S_string[j] >= 'a' && S_string[j] <= 'z' )
                s_hash += S_string[j]-96;
            else
                s_hash += S_string[j]-64;
        }
    
        if ( s_hash == w_hash )
        {
            for ( int j = i ; j < i + w_size ; j++ )
            {   
                if ( S_string[j] >= 'a' && S_string[j] <= 'z' )
                {
                    if ( pigeon[S_string[j]-96].first == 0 ) 
                        break;
                    else
                    {
                        cnt++;
                        pigeon[S_string[j]-96].second--;
                    }
                }
                else
                {
                    if ( pigeon[S_string[j]-64].first == 0 ) 
                        break;
                    else
                    {
                        cnt++;
                        pigeon[S_string[j]-64].second--;
                    }
                }
            }
        }

        for ( int j = 0 ; j < visit.size() ; j++ )
            pigeon[visit[j]].second = pigeon[visit[j]].first;
        

        if ( cnt == w_size )
            result++;
    }
        
    cout << result;
    return 0;
}*/