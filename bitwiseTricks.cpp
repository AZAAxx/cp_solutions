#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;

    //1. Check if k is odd/even
    int odd = k & 1; //1 if odd and 0 if even

    //2. Check if a number is a power of 2
    int notPowerOf2 = k & (k-1); //0 if a power of 2 and 0 if not

    //3. Kth bit
    int x, b;
    b = x & (1<<k); //get Kth bit
    x = x ^ (1<<k); //toggle kth bit
    x = x | (1<<k); //set Kth bit to 1
    x = x & ~(1<<k); //preset Kth bit to 0

    //4. Find x modulo 2^k
    int modulo = x & (1<<k - 1);

    //5. Swapping X and Y without a third var
    int X, Y;
    X = X ^ Y;
    Y = X ^ Y;
    X = X ^ Y;

    //6. These 2 are equivalent
    if(k == X) k = Y;
    else if(k == Y) k = X;

    k = X ^ Y ^ k;


    //7. Computing X + Y
    int sum;
    sum = (X | Y) + (X & Y); //X+Y
    sum = (X ^ Y) + 2*(X & Y); //X+Y


}