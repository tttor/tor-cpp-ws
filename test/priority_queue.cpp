// priority_queue::push/pop
#include <iostream>
#include <queue>
using namespace std;

int main ()
{
  priority_queue<int> mypq;

  mypq.push(25);
  mypq.push(30);
  mypq.push(100);
  mypq.push(40);

  cout << "Popping out elements...";
  while (!mypq.empty())
  {
     cout << " " << mypq.top();
     mypq.pop();
  }
  cout << endl;

  return 0;
}
