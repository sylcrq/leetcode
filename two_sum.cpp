#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

std::vector<int> twoSum(std::vector<int> &numbers, int target)
{
    std::vector<int> result;
    //对数组进行排序，但不改变numbers
    std::vector<int> sorted(numbers);
    //数组numbers中value -> index[]
    //重复元素index都要记录
    //排序后的数值元素查找原来的位置
    std::map< int, std::vector<int> > number_to_index;

    for(size_t i=0; i<numbers.size(); i++)
    {
        //number_to_index.insert(std::pair<int, int>(numbers[i], i+1));
        number_to_index[numbers[i]].push_back(i+1);
    }

    std::sort(sorted.begin(), sorted.end());

    int i = 0;
    int j = numbers.size() - 1;

    while(i < j)
    {
        if(sorted[i] + sorted[j] > target)
        {
            j--;
        }
        else if(sorted[i] + sorted[j] < target)
        {
            i++;
        }
        else
        {
            std::cout << "two sum:" << sorted[i] << ", " << sorted[j] << std::endl;

            std::vector<int>::iterator it_i = (number_to_index.find(sorted[i])->second).begin();
            std::vector<int>::iterator it_j = (number_to_index.find(sorted[j])->second).begin();

            if(sorted[i] == sorted[j])
                it_j++;

            result.push_back(std::min(*it_i, *it_j));
            result.push_back(std::max(*it_i, *it_j) );
            break;
        }    
    }

    return result;
}
