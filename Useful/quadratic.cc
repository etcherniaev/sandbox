#include <iostream>
#include <cmath>
 
using namespace std;

 
void quad_root1 (double aa, double bb, double cc, double & ra, double & rb)
{
  double a = aa, b = 0.5*bb, c = cc;
  double d, e;

  if (fabs(b) > fabs(c)) {
    e = 1. - (a / b) * (c / b);
    d = sqrt(e) * fabs(b);
  } else {
    e = b * (b / c) - a;
    d = sqrt(fabs(e)) * sqrt(fabs(c));
  }
 
  d = (b >= 0) ? d : -d;
  e = (d - b) / a;
  d = e ? (c / e) / a : 0;
  ra = d;
  rb = e;
  return;
}

void quad_root2 (double aa, double bb, double cc, double & ra, double & rb)
{
  double a = aa, b = 0.5*bb, c = cc;
  double d, e, q;

  e = 1. - (a/b)*(c/b);
  q = (sqrt(e) - 1.)*b;
  ra = c/q;
  rb = q/a;
  return;
}


int main() {
  double a, b, c, x1, x2;
  a = 94906265.625;
  b = -189812534;
  c = 94906268.375;
  quad_root1 (a, b, c, x1, x2);

  cout.precision(16);
  cout << "x1 = " << x1 << endl;
  cout << "x2 = " << x2 << endl;

  quad_root2 (a, b, c, x1, x2);
  cout << "x1 = " << x1 << endl;
  cout << "x2 = " << x2 << endl;
}
