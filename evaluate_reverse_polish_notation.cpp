#include <stdlib.h>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool isOperator(string& str)
{
    if( str.compare("+") == 0 || str.compare("-") == 0 || 
        str.compare("*") == 0 || str.compare("/") == 0 )
        return true;

    return false;
}

int evalRPN(vector<string> &tokens) 
{
    if(tokens.empty())
        return 0;

    int size = tokens.size();
    stack<int> operand;

    for(int i=0; i<size; i++)
    {
        if(!isOperator(tokens[i]))
        {
            operand.push( atoi(tokens[i].c_str()) );  // atoi fail ?
            continue;
        }

        // stack size >= 2 ?
        int operand_1 = operand.top();
        operand.pop();
        int operand_2 = operand.top();
        operand.pop();

        // overflow ?
        if(tokens[i].compare("+") == 0)
        {
            operand.push(operand_2 + operand_1);
        }
        else if(tokens[i].compare("-") == 0)
        {
            operand.push(operand_2 - operand_1);
        }
        else if(tokens[i].compare("*") == 0)
        {
            operand.push(operand_2 * operand_1);
        }
        else if(tokens[i].compare("/") == 0)
        {
            // math error ?
            operand.push(operand_2 / operand_1);
        }
    }

    return operand.top();
}

