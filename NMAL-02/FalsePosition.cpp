#include<bits/stdc++.h>
#define ll long long
using namespace std;

const float N = 1e-4;

float f(float x){
    return log(3 * x) - 3;
}

float regulaFalsi(float a, float b){
    if(f(a) * f(b) > 0) return -10000;
    float err = abs(a - b), c;
    ll iteration = 0;
    while(err >= N){
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
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
    cout << regulaFalsi(1, 10) << '\n';
}
