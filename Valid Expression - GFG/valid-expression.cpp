// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}// } Driver Code Ends


bool valid(string s)
{
    stack<char> stck;
    
    for(int i=0; i<s.length(); i++){
        
        // if opening brackets add in stack
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            
            stck.push(s[i]);
        }
        // when closing brackets remove corresponding bracket from stack
        else{
  
            if(!stck.empty()){
                
                char top = stck.top();
                
                if( (s[i] == ')' && top == '(') ||
                    (s[i] == ']' && top == '[') ||
                    (s[i] == '}' && top == '{')){
                
                    stck.pop();
                }
                // couldn't find corresponding bracket -> invalid case
                else{
                    return false;
                }
            }
            // stack is empty -> invalid case
            else{
                return false;
            }
        }
    }
    
    if(stck.empty())
        return true;
        
    return false;
}