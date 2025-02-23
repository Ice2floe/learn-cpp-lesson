#include<cmath>
#include <iostream>

class Point2d
{
  private:
  double m_one {0.0};
  double m_two {0.0};
  
  public:
  Point2d ()=default;
  Point2d (double one, double two)
  :m_one{one}, m_two{two}
  {
    
  }
  
  void print () const 
  {
    std::cout << "Point2d (" << m_one << ", "
    << m_two << ")\n";
  }
  
  double distanceTo(const Point2d& p) const
  {
  return std::sqrt ((m_one-p.m_one)*(m_one-p.m_one)+(m_two-p.m_two)*(m_two-p.m_two));  
  }
  
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    //Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();
    
    std::cout << "Distance between two points: " 
    << first.distanceTo(second) << '\n';

    return 0;
}

