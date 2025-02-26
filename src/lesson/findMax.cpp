#include<iostream>
#include<vector>

template<typename T>
T findMax(const std::vector<T>& data)
{
  
  std::size_t length { data.size() };

    if (length==0)
        return T{};
  
  T maxSum {data[0]};
 
  for (std::size_t index{0}; index<data.size(); ++index)
  {
    if (maxSum<data[index])
    maxSum=data[index];
  }
  
  return maxSum;
}
int main()
{
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findMax(data3) << '\n';

    return 0;
}
