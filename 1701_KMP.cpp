#include <bits/stdc++.h>
using namespace std;

int maxx;

void KMP(string substring) 
{   
    int table[5001] = { 0 };
    fill_n(table, substring.length(),0);

    int start = 0;
    for (int end = 1; end < substring.length(); end++) 
    {
        while (start > 0 && substring[start] != substring[end]) 
            start = table[start - 1];
        
        if (substring[start] == substring[end]) 
        {
            table[end] = ++start;
            if (maxx < table[end]) 
                maxx = table[end];
            
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string plain_text;
    string substring;

    cin >> plain_text;
    for (int i = 0; i < plain_text.length(); i++) 
    {
        substring = plain_text.substr(i, plain_text.length() - i);
        KMP(substring);
    }

    cout << maxx;
    return 0;
}
