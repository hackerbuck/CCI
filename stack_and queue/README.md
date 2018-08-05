## Stacks

```C++
 stack<char> st;
 st.push(s[i]);
 if (st.empty()) {...}
 
 p=st.top();
 st.pop();
 ```

*  Balanced paranthesis
 
 ```C++
 bool balance(string s)
{
    char p='a';
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {  
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);

        else if(st.empty())
            return 0;
        else if(s[i]==')' ||s[i]=='}' || s[i]==']')
            {   p=st.top();
                st.pop();
        				if(s[i]==')' && p!='(')
            				return 0;
        				else if(s[i]=='}' && p!='{')
            				return 0;
        				else if(s[i]==']' && p!='[')
            				return 0;
            }
    }
 ```
 
 * Infix to postfix/prefix
