#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 一种数学解法
// 设行 = i, 列 = j
// 竖向字符在原字符串的下标为 [i, j] = 2*j*(n-1) + i
// 斜向字符在原字符串的下标为 2*(j+1)*(n-1) - i
string convert_ii(string s, int nRows)
{
    if(s.empty() || nRows <= 1)
        return s;

    //vector<string> row(nRows);
    string result;
    
    int str_len = s.size();

    for(int i=0; i<nRows; i++)
    {
        for(int j=0, index=i; index<str_len; j++, index=2*j*(nRows-1)+i)
        {
            result.push_back( s[index] );

            if(i == 0 || i == (nRows-1))
                continue;

            if((2*(j+1)*(nRows-1)-i) < str_len)
                result.push_back( s[2*(j+1)*(nRows-1)-i] );
        }
    }

    //for(int i=0; i<nRows; i++)
    //{
    //    result.append( row[i] );
    //}

    return result;
}

string convert(string s, int nRows) 
{
    if(s.empty() || nRows <= 1)
        return s;

    vector<string> row(nRows);
    string result;

    int index = 0;
    int str_len = s.size();
    while(index < str_len)
    {
        for(int i=0; i<nRows; i++)
        {
            if(index >= str_len)
                break;

            row[i].push_back( s[index++] );
        }

        for(int i=nRows-2; i>0; i--)
        {
            if(index >= str_len)
                break;

            row[i].push_back( s[index++] );
        }
    }

    for(int i=0; i<nRows; i++)
    {
        result.append( row[i] );
    }

    return result;
}

