#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path) 
{
    string result;

    if(path.empty())
        return result;

    vector<string> nodes;
    string tmp;
    for(size_t i=0; i<path.size(); i++)
    {
        if(path[i] == '/')
        {
            if(!tmp.empty() && tmp.compare(".") != 0)
            {
                if(tmp.compare("..") == 0 && !nodes.empty())
                    nodes.pop_back();
                else if(tmp.compare("..") != 0)
                    nodes.push_back(tmp);
            }

            tmp.clear();
        }
        else
        {
            tmp.push_back(path[i]);
        }
    }

    if(!tmp.empty() && tmp.compare(".") != 0)
    {
        if(tmp.compare("..") == 0 && !nodes.empty())
            nodes.pop_back();
        else if(tmp.compare("..") != 0)
            nodes.push_back(tmp);
    }

    if(nodes.empty())
        return string("/");

    for(size_t i=0; i<nodes.size(); i++)
    {
        result.push_back('/');
        result.append(nodes[i]);
    }

    return result;
}

