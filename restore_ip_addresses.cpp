#include <iostream>
#include <string>
#include <vector>

using namespace std;

void process(string& s, int start, int step, string& solution, vector<string>& result);
void process_ii(string& s, int start, int step, string& solution, vector<string>& result);
int strToValidIPNum(string& str);

// Note: std::stoi & std::to_string in C++11
vector<string> restoreIpAddresses(string s) 
{
    vector<string> result;
    string solution;

    if(s.empty())
        return result;

    //process(s, 0, 1, solution, result);
    process_ii(s, 0, 0, solution, result);

    return result;
}

// 一种更简洁的解法
// IP地址每段长度范围为[1, 3]
void process_ii(string& s, int start, int step, string& solution, vector<string>& result)
{
    int size = s.size();
    
    if((step < 0) || (step > 4))
        return;

    if((size-start) < (4-step))
        return;

    if((size-start) > (4-step)*3)
        return;

    if((step == 4) && (start == size))
    {
        result.push_back(solution.substr(0, solution.size()-1));
        return;
    }

    int num = 0;
    int count = 0;
    for(int i=0; i<3; i++)
    {
        num = num*10 + s[start+i] - '0';

        if(num >= 0 && num <= 255)
        {
            solution.push_back(s[start+i]);
            solution.push_back('.');

            process_ii(s, start+i+1, step+1, solution, result);

            solution.pop_back();  // clear '.'
            count++;
        }

        if(num == 0)
            break;
    }

    // clear
    solution.resize(solution.size() - count);
    return;
}

// 递归
void process(string& s, int start, int step, string& solution, vector<string>& result)
{
    int size = s.size();

    if(start >= size)
        return;

    if(step == 4)
    {
        string str = s.substr(start);
        int num = strToValidIPNum(str);
    
        if((num >= 0) && (num <= 255))
        {
            string tmp = std::to_string(num);
    
            solution.append(tmp);
            result.push_back(solution);
    
            solution.resize(solution.size() - tmp.size());
        }
    
        return;
    }

    int len = 1;
    string str = s.substr(start, len);
    int num = strToValidIPNum(str);
    
    while((num >= 0) && (num <= 255))
    {
        // update solution
        string tmp = std::to_string(num);
        solution.append(tmp);
        solution.push_back('.');
    
        process(s, start+len, step+1, solution, result);
    
        // clear solution
        solution.resize(solution.size() - tmp.size() - 1);
    
        if(start+len >= size)
            break;
    
        len++;
        str = s.substr(start, len);
        num = strToValidIPNum(str);
    }

    return;
}

int strToValidIPNum(string& str)
{
    if(str.empty())
        return -1;
    
    if(str.size() > 3)
        return -1;

    // '0'开头的任何非零数字都是没有意义的
    if((str.size() > 1) && (str[0] == '0'))
        return -1;

    return std::stoi(str);
}

