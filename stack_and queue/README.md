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
 
 ```
	stack<char> st;
 for (i = 0 ; i < str.size(); i++) {
					if (!operator (str[i])) {
								cout << s[i];
					}
					else if (s[i] == '(') {
								st.push(s[i]) // push '(' into stack
				 }
					else if (s[i] == ')') {
					
								while (!s.empty() && st.top() != '(') {
													st.pop()
								}
								if (st.top == '(') st.pop()			
				}
				else // an operator is encountered
    {
            while (!s.emoty() && Prec(str[i]) <= Prec(st.top())) {
																cout << st.top()
																st.pop()
												}				
            push(stack, exp[i]);
     }
 }
	 while (!st.empty()) { // Take care of remaining elements left in stack
						cout << st.top();
						st.pop()
		}
 ```
