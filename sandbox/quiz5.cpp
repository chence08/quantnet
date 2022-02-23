#include <iostream>

// class A
// {
// private:
//   int m_da;

// public:
//   A(int da): m_da(da) {}
//   int GetA() { return m_da; }
//   A& operator = (const A& source) 
//   { m_da=source.m_da; return *this; }
// };

// class B: public A
// {
// private:
//   int m_db;

// public:
//   B(int da, int db): A(da), m_db(db) {}
//   int GetB() { return m_db; }
//   B& operator = (const B& source) 
//   { m_db=source.m_db; return *this; }
// };

// int main()
// {
//   B b1(10, 20); B b2(30, 40);
//   b1=b2;
//   std::cout<<b1.GetA()<<", "<<b1.GetB()<<std::endl;
//   return 0;
// }

// =========================================================

// class A
// {
// private:
//   int m_data;

// public:
//   A(): m_data(GetValue()) {}
//   int Calculate() { return m_data*1.5; }
//   virtual int GetValue() { return 10; }
// };

// class B: public A
// {
// public:
//   virtual int GetValue() { return 20; }
// };

// int main()
// {
//   A a; B b; A* ap;

//   ap=&a; std::cout<<ap->GetValue()<<", "<<ap->Calculate()<<", ";
//   ap=&b; std::cout<<ap->GetValue()<<", "<<ap->Calculate()<<std::endl;

//   return 0;
// }


class A
{
public:
  std::string F() { return "A"; }
};

class B: public A
{
public:
  std::string F() { return "B"; }
};

int main()
{
  A a; B b;
  A* ap;

  std::cout<<a.F()<<", ";
  std::cout<<b.F()<<", ";

  ap=&a; std::cout<<ap->F()<<", ";
  ap=&b; std::cout<<ap->F()<<std::endl;

  return 0;
}