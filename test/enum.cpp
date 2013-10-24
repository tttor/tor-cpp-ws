#include <iostream>
using namespace std;

typedef enum
{
  thirteen = 13,
  fourteen,
  fifteen,
  sixteen,
  seventeen,
  eighteen,
  nineteen
} TEENS;
   
//enum
//{
//  thirteen = 10,
//  fourteen,
//  fifteen,
//  sixteen,
//  seventeen,
//  eighteen,
//  nineteen
//} TEENS;


main()
{


   TEENS teen = seventeen;

   if(teen == seventeen)
      cout << seventeen << endl;
   
   teen = nineteen;   
   switch(teen)
   {
    case nineteen:
    {
      cout << nineteen << endl;
      break;
    }
   }
}
          
