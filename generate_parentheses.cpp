#include <string>
#include <vector>

using namespace std;

void generate(int left_n, int right_n, string& val, vector<string>& result);
//bool left_is_valid(int left_n, int right_n);
//bool right_is_valid(int left_n, int right_n);

vector<string> generateParenthesis(int n)
{
    vector<string> result;

    //string val("(");
    //generate(n-1, n, val, result);

    string val;

    if(n > 0)
        generate(n, n, val, result);

    return result;
}

void generate(int left_n, int right_n, string& val, vector<string>& result)
{
    if(left_n == 0 && right_n == 0)
    {
        result.push_back(val);
        return;
    }

    // insert "("
    if(left_n > 0)
    {
        val.push_back('(');
        generate(left_n - 1, right_n, val, result);
        val.erase(val.end() - 1);  // clear
    }

    // insert ")"
    if(right_n > left_n)
    {
        val.push_back(')');
        generate(left_n, right_n - 1, val, result);
        val.erase(val.end() - 1);  // clear
    }

}

// 以下代码逻辑合并到递归函数中
//bool left_is_valid(int left_n, int right_n)
//{
//    if(left_n > 0) return true;
//    
//    return false;
//}

//bool right_is_valid(int left_n, int right_n)
//{
//    if(right_n > left_n)
//        return true;
//
//    return false;
//}

