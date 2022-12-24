/**
 * Name: Sanjoy Paul
 * CSE, Canadian University Of Bangladesh
 * email: sanjoypp@gmail.com
 */
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdbool.h>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

#define MAX 10000007
#define LL long long
#define eps 1e-6
#define _max(x, y) x > y ? x : y
#define _min(x, y) x < y ? x : y
#define sq(a) a *a

vector<bool> notPrime(MAX, false);
vector<int> Prime;
vector<int> divisors[MAX];

int _gcd(int a, int b)
{
  if (b == 0)
    return a;
  return _gcd(b, a % b);
}

void sieve()
{
  notPrime[0] = notPrime[1] = true;
  for (int i = 4; i <= MAX; i += 2)
  {
    notPrime[i] = true;
  }
  Prime.push_back(2);
  for (int i = 3; i <= MAX; i += 2)
  {
    if (!notPrime[i])
    {
      Prime.push_back(i);
      if (i * i <= MAX)
      {
        for (int j = i * i; j <= MAX; j += 2 * i)
        {
          notPrime[j] = true;
        }
      }
    }
  }
}

void Divisors(int n)
{
  // know the divisors
  for (int i = 1; i <= n; i++)
  {
    for (int j = i; j <= n; j += i)
    {
      divisors[j].push_back(i);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < divisors[i].size(); j += 1)
    {
      printf("%d ", divisors[i][j]);
    }
    printf("\n");
  }
}

int NOD(LL n)
{
  // number of divisors = NOD
  int nod = 1;
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
  {
    nod = nod * 2;
  }
  return nod;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  // sieve();
  // for (int i = 0; i < 20; i++)
  // {
  //   printf("%d ", Prime[i]);
  // }
  // printf("\n");

  int t;
  scanf("%d", &t);

  while (t--)
  {
    int n;
    scanf("%d", &n);
    // int ans = NOD(n);
    // printf("%d\n", ans);
    Divisors(n);
  }

  return 0;
}

/*
problem links
================
  ** Number of divisors problems **
  =================================
  1. https://cses.fi/problemset/task/1713/
  2. https://www.codechef.com/problems/CODIV?tab=statement
  3. https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/count-divisors/

*/