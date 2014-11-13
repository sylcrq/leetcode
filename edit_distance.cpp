#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) 
{
    int word1_size = word1.size();
    int word2_size = word2.size();

    if(word1.empty())
        return word2_size;

    if(word2.empty()) 
        return word1_size;

    // Note: distance[word1_size + 1][word2_size + 1]
    vector<vector<int> > distance(word1_size+1, vector<int>(word2_size+1, 0));

    // init distance
    for(int i=0; i<=word1_size; i++)
    {
        distance[i][0] = i;
    }
    for(int i=0; i<=word2_size; i++)
    {
        distance[0][i] = i;
    }

    for(int i=1; i<=word1_size; i++)
    {
        for(int j=1; j<=word2_size; j++)
        {
            // Note: compare word1[i - 1] and word2[j - 1]
            if(word1[i-1] == word2[j-1])
            {
                distance[i][j] = distance[i-1][j-1];
            }
            else
            {
                distance[i][j] = std::min(distance[i-1][j]+1, distance[i][j-1]+1);
                distance[i][j] = std::min(distance[i][j], distance[i-1][j-1]+1);
            }
        }
    }

    return distance[word1_size][word2_size];
}

