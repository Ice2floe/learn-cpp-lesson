#include <iostream>
#include <string>

template <typename T, typename U, typename Z>
class Triad
{
  private:
  T m_one {};
  U m_two {};
  Z m_three {};
  public:
  Triad (const T& one, const U& two, const Z& three)
  :m_one {one}, m_two {two}, m_three {three}
  {
  }
  
   const T& first () const
  {
    return m_one;
  }
  
  const U& second () const
  {
    return m_two;
  }
  
  const Z& third () const
  {
    return m_three;
  }
  
  void print () const;
    
};

template <typename T, typename U,typename Z>
void Triad<T,U,Z>::print() const
{
  std::cout << '{' << m_one << ", " << m_two
  << ", " << m_three << "}\n";
}


int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}

