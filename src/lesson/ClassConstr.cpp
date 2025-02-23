#include<iostream>
#include<string>
#include<string_view>

class Ball 
{
  private:
 
  std::string m_colorName {};
  double m_radius {};
  
  public:
  
  Ball (std::string_view colorName, double radius)
  : m_colorName {colorName}
  , m_radius {radius}
  {
    
  }
  
  const std::string getBallColor () const
  {
    return m_colorName;
  }
  
  const int& getBallRadius () const
  {
    return m_radius;
  }
  
  
  
  
};

void print ( const Ball& ball)
  {
    std::cout << "Ball (" << ball.getBallColor () << ", "
    << ball.getBallRadius() << ")\n";
  }

int main()
{
 Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);
  
  return 0;
}
