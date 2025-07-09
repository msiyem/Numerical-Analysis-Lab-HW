#include<bits/stdc++.h>
#define ll long long
using namespace std;

const float N = 1e-4;
const float x_true = ((-3 + sqrt(57.0)) / 8.0);

float f(float x){
    return 4 * x * x + 3 * x - 3;
}

float Bisection(float a, float b){
    if(f(a) * f(b) > 0) return LLONG_MIN;
     float err = abs(a - b);
     float cc;
     ll iteration = 0;
     while(err >= N){
        cc = (a + b) / 2;
        float tpre = fabs((x_true - cc) / x_true) * 100;
        cout << "c = " << cc << ", TPRE = " << tpre << "%\n";
        if(f(cc) == (float)0) return cc;
        if(f(a) * f(cc) < 0) b = cc;
        else a = cc;

        err = abs(a - b);
        iteration++;
     }
     cout << "Number of Iterations: " << iteration << '\n';
     return cc;
}

float regulaFalsi(float a, float b){
    if(f(a) * f(b) > 0) return -10000;
    float err = abs(a - b), c;
    ll iteration = 0;
    while(err >= N){
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        float tpre = fabs((x_true - c) / x_true) * 100;
        cout << "c = " << c << ", TPRE = " << tpre << "%\n";
        if(f(c) == 0){
            //return c;
            break;
        }
        else if(f(a) * f(c) < 0){
            b = c;
        }
        else a = c;
        err = abs(a - b);
        iteration++;
    }
    cout << "Iterations Taken :" << iteration << '\n';
    return c;
}

int main(){
    cout << regulaFalsi(0, 1) << '\n';
    cout << Bisection(0, 1) << '\n';
}
