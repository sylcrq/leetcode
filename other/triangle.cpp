#include <iostream>


int form_a_valid_triangle(const int* array, int array_len)
{
    if(!array || array_len < 3)
    {
        std::cout << "form_a_valid_triangle: invalid parameters" << std::endl;
        return 0;
    }

    int result_num = 0;

    for(int i=0; i<array_len-2; i++)
    {
        for(int j=i+1; j<array_len-1; j++)
        {
            for(int k=j+1; k<array_len; k++)
            {
                if((array[i] < array[j] + array[k]) && 
                   (array[j] < array[i] + array[k]) && 
                   (array[k] < array[i] + array[j]))
                {
                    std::cout << "ok: " << array[i] << ", " << array[j] << ", " << array[k] << std::endl;
                    result_num++;
                }
            }
        }
    }

    return result_num;
}
