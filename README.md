

## 蒙哥马利算法


$$
目的是为了快速求出a^b\%c的结果\\

一般来说b是很大的值\\

先把b转换成n位二进制数表示如下\\
b = {b_0}*2^0 + {b_1}*2^1+ ...+b_{n-1}*2^{n-1}\\
然后可以改写a^b为\\
a^b = a^{{b_0}*2^0 + {b_1}*2^1+ ...+b_{n-1}*2^{n-1}} = a^{{b_0}*2^0}a^{{b_1}*2^1}...a^{{b_{n-1}*2^{n-1}}}\\
所以a^b\%c可以写成\\
(a^{{b_0}*2^0}a^{{b_1}*2^1}...a^{{b_{n-1}*2^{n-1}}} )\%c = ((a^{{b_0}*2^0}a^{{b_1}*2^1}...a^{{b_{n-2}*2^{n-2}}})\%c)*(a^{{b_{n-1}*2^{n-1}}}\%c))\%c \\
设A_{n-1} = (a^{{b_0}*2^0}a^{{b_1}*2^1}...a^{{b_{n-1}*2^{n-1}}} )\%c ，则A_{n-1} = (A_{n-2}*(a^{{b_{n-1}*2^{n-1}}}\%c))\%c\\
A_0 = a^{b_0}\%c\\
K_{n-1}=a^{{b_{n-1}*2^{n-1}}}\%c的值由b_{n-1}来决定.\\当b_{n-1}=1的时候，K_{n-1} = a^{2^{n-1}}\%c;\\当b_{n-1}=0的时候，K_{n-1}=1;\\
对于K_n，同样可以使用递归的方式求值:(只考虑b_n = 1，因为b_n = 0的时候K_n都等于1)\\
b_n = 1, K_n = a^{2^{n}}\%c = T_n = (T_{n-1}*T_{n-1})\%c，最开始T_0=a\%c\\
\\
b_{n-1} = 1 , A_{n-1} = (A_{n-2}*T_{n-1})\%c\\
b_{n-1}=0,A_{n-1}=A_{n-2}\%c =A_{n-2}
$$




代码如下：

```c++
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


```
