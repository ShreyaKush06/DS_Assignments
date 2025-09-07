#include <iostream>
#include<stack>
using namespace std;
 int priority(char c)
 {
    if(c=='^')return 3;
    if(c=='*'||c=='/')return 2;
    if(c=='+'||c=='-')return 1;
    return -1;


 }

string infixtopostfix(string infix)
{
   stack<char>st;
   string res="";
   int n=infix.length();
   int i=0;char c;
      while(i<n)
   { 
      c=infix[i];
       if( c>='0' && c<='9'|| c>='a'&& c<='z'|| c>='A'&& c<='Z')
       res=res+c;

      else if(c=='(')
      {
        st.push(c);
      } 
      else if(c==')')
      {   
        while(!st.empty() && st.top()!='(')
        {
            res=res+st.top();
            st.pop();
        }
        st.pop();
         

      }

      else{

        while(!st.empty() && priority( infix[i])<= priority(infix[st.top()]))
      {
         res=res+st.top();
         st.pop();
        
      }
      st.push(c);

      }
    
      i++;
   }
   while(!st.empty())
   {
    res=res+st.top();
    st.pop();


   }

return res;

}


int main()
{


    cout<<"please enter you string";
    string str;
    cin>>str;
    string result=infixtopostfix(str);
    cout<<result;

}