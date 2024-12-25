#include <bits/stdc++.h>
using namespace std;

string formula;
stack<char>s;

void postfix()
{
    for ( int i = 0 ; i < formula.length() ; i++ )
    {
        if ( formula[i] >= 'A' && formula[i] <= 'Z' )
            cout << formula[i];
        else if ( formula[i] == '(' )
            s.push(formula[i]);
        else if ( formula[i] == '+' || formula[i] == '-' )
        {   
            if ( s.empty() ) 
            {
                s.push(formula[i]);
                continue;
            }
            else if( !s.empty())
            {
                if ( s.top() == '(' ) 
                {
                    s.push(formula[i]);
                    continue;
                }

                while(!s.empty())
                {
                    if ( s.top() == '(' ) break;
                    
                    cout << s.top();
                    s.pop();
                }
                s.push(formula[i]);
            }
        }
        else if ( formula[i] == '*' || formula[i] == '/' )
        {
            if ( s.empty() ) 
            {
                s.push(formula[i]);
                continue;
            }
            else if ( !s.empty() )
            {
                if ( s.top() == '(' ) 
                {
                    s.push(formula[i]);
                    continue;
                }

                while(1)
                {
                    if ( s.top() == '(' ) break;

                    if ( s.top() == '+' || s.top() == '-' )
                    {
                        s.push(formula[i]);
                        break;
                    }
                    cout << s.top();
                    s.pop();
                }
            }
        }
        else if ( formula[i] == ')' )
        {
            while( s.top() != '(' )
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
    }

    if ( !s.empty() )
    {
        while(!s.empty())
        {
            cout << s.top();
            s.pop();
        }
    }
}

int main()
{
    cin >> formula;
       
    postfix();
    return 0;
}