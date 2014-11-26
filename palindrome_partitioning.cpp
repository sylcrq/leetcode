#include <iostream>
#include <vector>
#include <string>

using namespace std;

void partition_helper(string& s, size_t start, vector<string>& solution, vector<vector<string> >& result);
bool is_palindrome(string& s);

vector<vector<string> > partition(string s) 
{
    vector<string> solution;
    vector<vector<string> > result;

    partition_helper(s, 0, solution, result);

    return result;
}

void partition_helper(string& s, size_t start, vector<string>& solution, vector<vector<string> >& result)
{
    if(start >= s.length())
    {
        result.push_back(solution);
        return;
    }

    for(size_t i=start; i<s.length(); i++)
    {
        string substr = s.substr(start, i-start+1);

        if(is_palindrome(substr))
        {
            solution.push_back(substr);

            partition_helper(s, i+1, solution, result);

            solution.pop_back();
        }
    }

    return;
}

bool is_palindrome(string& s)
{
    if(s.empty())
        return false;
    
    int start = 0;
    int end = s.length() - 1;

    while(start <= end)
    {
        if(s[start] != s[end])
            return false;

        start++;
        end--;
    }

    return true;
}

