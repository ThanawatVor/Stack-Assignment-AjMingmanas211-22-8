#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>
#include <string.h>

int main(int argc, char *argv[]) {
  int i,match=1;
  char c;
  bool toomanyclose=false;
  for(i=1;i<argc;i++)
  {
    Stack s; 
    for(int j=0;j<strlen(argv[i]);j++)
      {
        switch(argv[i][j])
          {
            case '}':
              if(s.get_size()==0) toomanyclose=true;
              c=s.pop();
              if(c!='{') match=0; 
              if(c=='{') match=1;
              break;
            case ']':
              if(s.get_size()==0) toomanyclose=true;
              c=s.pop();
              if(c!='[') match=0;
              if(c=='[') match=1;
              break;
            case ')':
              if(s.get_size()==0) toomanyclose=true;
              c=s.pop();
              if(c!='(') match=0;
              if(c=='(') match=1;
              break;
            case '{': s.push(argv[i][j]); break;
            case '[': s.push(argv[i][j]); break;
            case '(': s.push(argv[i][j]); break;
          
            default:break;
          }
        if(match==0) break;
      }
    if(match==0)
    {
      if(toomanyclose)
      {
        cout<<"not match: too many close parenthesis"<<endl;
      }
      else cout<<"not match"<<endl;
      
    }
    else if(s.get_size()!=0)
    {
      cout<<"not match: too many open parenthesis"<<endl;
    }
    else cout<<"match"<<endl;


    
    match=1;
    toomanyclose=false;
  }
}