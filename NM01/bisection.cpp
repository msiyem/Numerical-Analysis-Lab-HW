#include <bits/stdc++.h>
#define ll long long
using namespace std;

const float tolerance = 1e-6;

float f(float x)
{
  return (4 * x * x + 3 * x - 3);
}

float Bisection(float a, float b)
{
  if (f(a) * f(b) > 0)
    return LLONG_MIN;
  float err = abs(a - b);
  float cc;
  ll iteration = 0;
  while (err >= tolerance)
  {
    cc = (a + b) / 2;
    if (f(cc) == (float)0)
      return cc;
    if (f(a) * f(cc) < 0)
      b = cc;
    else
      a = cc;

    err = abs(a - b);
    iteration++;
  }
  cout << "Number of Iterations: " << iteration << '\n';
  return cc;
}

void TraditionalApproach()
{
  float l = 0, r = 10;
  float kk = Bisection(l, r);
  cout << "Root: " << kk << '\n';
}

void ImprovedApproach()
{
  float iniL = 0, iniR = 10, l = LLONG_MIN, r = LLONG_MIN;
  for (float xx = iniL; xx <= iniR; xx += 0.1)
  {
    if (f(xx) * f(xx + 0.1) < 0)
    {
      l = xx;
      r = xx + 0.1;
      break;
    }
  }
  if (l != LLONG_MIN && r != LLONG_MIN)
  {
    float kk = Bisection(l, r);
    cout << "Root: " << kk << '\n';
  }
  else
  {
    cout << "Root isnt in this range.";
  }
}

int main()
{
  TraditionalApproach();
  ImprovedApproach();
}
