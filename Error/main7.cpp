#include <iostream>
#include "linkstack.h"
#include "staticstack.h"

using namespace std;
using namespace ZXRLib;

bool is_left(char c)
{
    return (c == '(')||(c == '{')||(c == '[')||(c == '<');
}
bool is_right(char c)
{
    return (c == ')')||(c == '}')||(c == ']')||(c == '>');
}
bool is_quto(char c)
{
    return (c == '\'' )||(c == '\"');
}
bool is_match(char l,char r)
{
    return ((l == '(')&&(r == ')'))||
           ((l == '{')&&(r == '}'))||
           ((l == '[')&&(r == ']'))||
           ((l == '<')&&(r == '>'))||
           ((l == '\'')&&(r == '\''));
           ((l == '\"')&&(r == '\"'));
}
bool scan(const char* code)
{
    LinkStack<char> stack;
    int i = 0;
    bool ret = true;
    code = (code == NULL)?"":code;
    while(ret && (code[i]!='\0'))
    {
        if(is_left(code[i]))
        {
            stack.push(code[i]);
        }
        else if(is_right(code[i]))
        {
            if((stack.size() > 0)&&(is_match(stack.top(),code[i])))
            {
                stack.pop();
            }
            else
            {
                ret = false;
            }
        }
        else if(is_quto(code[i]))
        {
            if((stack.size() == 0)||!is_match(stack.top(),code[i]))
            {
                    stack.push(code[i]);
            }
            else if(is_match(stack.top(),code[i]))
            {
                    stack.pop();

            }
        }
        i++;
    }
    return ret && (stack.size() == 0);
}
int main()
{
    //cout << scan("<a{b(\'x\')c}>\"") << endl;
    //cout << scan("bool is_match(char l,char r) { return ((l == '(')&&(r == ')'))|| ((l == '{')&&(r == '}'))|| ((l == '[')&&(r == ']'))|| ((l == '<')&&(r == '>'))|| ((l == '\'')&&(r == '\'')); ((l == '\"')&&(r == '\"')); }") << endl;
    cout << scan(" else if(is_quto(code[i])) { if((stack.size() == 0)||!is_match(stack.top(),code[i])) { stack.push(code[i]); } else if(is_match(stack.top(),code[i])) { stack.pop();  } }") << endl;
    return 0;
}


class Test:public Object
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }
};
int main2()
{
    LinkStack<Test> stack;
    cout << stack.size() << endl;
    return 0;
}
int main1()
{
    StaticStack<int,5>stack;
    try
    {
        stack.pop();
    }catch(const Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    for(int i = 0;i < 5;i++)
    {
        stack.push(i);
    }
    while(stack.size() > 0)
    {
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}
