#include <iostream>

int main() {
  constexpr int perfectSqur[]{0,1,4,9,16,25,36,49,64,81};
  int root{};
  
 
  while (true) {
    std::cout << "Enter a single digit integer, or -1 to quit: ";
    std::cin >> root;

    if (root == -1)
      break;
      
    bool check {false}; 

    for (const auto &i : perfectSqur) {

      if (root == i) 
      {
      check=true;
      break;
      }
        
  }
  if (check)
  std::cout << root << " is a perfect square!\n";
  else
  std::cout << root << " is not a perfect square!\n";
  }
  

  return 0;
}

