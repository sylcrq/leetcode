#include <string>
#include <vector>

using namespace std;

void letterCombinations_helper(string& digits, size_t start, string& solution, vector<string>& combinations);
string digit_to_letters(int digit);

vector<string> letterCombinations(string digits) 
{
    //string table[10] = {" ", "", "abc", "def", "ghi", 
    //                    "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string solution;

    letterCombinations_helper(digits, 0, solution, result);

    return result;
}

void letterCombinations_helper(string& digits, size_t start, string& solution, vector<string>& combinations)
{
    if(start >= digits.size())
    {
        combinations.push_back(solution);
        return;
    }

    int index = digits[start] - '0';
    string letters = digit_to_letters(index);

    for(size_t i=0; i<letters.size(); i++)
    {
        solution.push_back(letters[i]);

        letterCombinations_helper(digits, start+1, solution, combinations);

        solution.erase(solution.end()-1);
    }
}

string digit_to_letters(int digit)
{
    switch(digit)
    {
    case 0: return " "; break;
    case 1: return ""; break;
    case 2: return "abc"; break;
    case 3: return "def"; break;
    case 4: return "ghi"; break;
    case 5: return "jkl"; break;
    case 6: return "mno"; break;
    case 7: return "pqrs"; break;
    case 8: return "tuv"; break;
    case 9: return "wxyz"; break;
    } 

    return "";
}

