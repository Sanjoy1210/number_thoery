/**
 * Name: Sanjoy Paul
 * CSE, Canadian University of Bangladesh
 * emil: sanjoypp@gmail.com
 *
 */

#include <iostream>
using namespace std;

#define LL long long

int main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);
  while (t--)
  {
    LL n;
    int nod = 1;
    scanf("%lld", &n);

    for (LL i = 2; i * i <= n; i++)
    {
      int pow = 0;
      while (n % i == 0)
      {
        pow++;
        n /= i;
      }
      nod = nod * (pow + 1);
    }

    if (n > 1)
      nod = nod * 2;
    printf("%d\n", nod);
  }

  return 0;
}