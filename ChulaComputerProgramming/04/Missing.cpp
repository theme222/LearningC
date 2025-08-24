#include <iostream>

int c[256];
int main ()
{
 std:: string g;
  std::getline(std::cin,g);

  for (int a= 0;a<g.size();a++)
  {
    c[(int)g[a]]++;
  }

  bool h=false;

  for (int i='0'; i <= '9'; i++)
  {
    if (c[i]!=0) continue;
    if (h) std::cout << ',';
    std::cout<<(char)i;
    h=true;
  }
  if (!h) std::cout << "None";
  puts("");
}
