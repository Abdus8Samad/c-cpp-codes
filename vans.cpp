#include<iostream>
#include<string>
#include<stack>
using namespace std;

int oper(char a)
{
    if(a=='+'||a=='-'||a=='*'||a=='/')
    {return 1;}
    return 0;
}

int precedence(char a)
{
    if(a=='*'||a=='/')
    {return 2;}
    if(a=='+'||a=='-')
    {return 1;}
    else
    {return 0;}
}

string convert(string s)
{
    stack<char> st;
    string postfix = "";
    int j=0;
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
            i++;
        }
        else if(s[i]==')')
        {
            while(st.top()!='(')
            {
                postfix+=st.top();
                st.pop();
                j++;
            }
            i++;
            st.pop();
        }        
        else if(s[i]>='A' && s[i]<='Z')
        {
           postfix+=s[i];
           j++;
           i++;
        }
        else if(oper(s[i])==1)
        {
         if(precedence(st.top())>=precedence(s[i]))
        {
            postfix+=st.top();
            st.pop();
            st.push(s[i]);
            i++;  
            j++;
        }
        else
        {
           st.push(s[i]);
           i++;
        }
        }

    }
    while(!st.empty())
    {
        postfix+=st.top();
        st.pop();
        j++;
    }
    return postfix;
}

int main()
{
    string s="((A+B)*C-D)";
    cout<<convert(s)<<endl;
}