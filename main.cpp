#include<iostream>

using namespace std;

//计算(a^b)mod c
long long montgomery(long long a, long long b, long long c){
    long long A = 1;
    long long T = a%c;
    while(b){
        if(b&1){//如果当前的b是1 Kn ！= 1
            A = (A * T) % c;
        }
        b >>= 1;
        T = (T * T) % c;
    }
    return A;
}

int main(){
    long long a,b,c;
    cin >> a >> b >> c;
    printf("%lld^%lld mod %lld=%lld\n",a,b,c, montgomery(a,b,c));

}

