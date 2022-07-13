

## 蒙哥马利算法



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

# 【模板】快速幂||取余运算

## 题目描述

给你三个整数 $a,b,p$，求 $a^b \bmod p$。

## 输入格式

输入只有一行三个整数，分别代表 $a,b,p$。

## 输出格式

输出一行一个字符串 `a^b mod p=s`，其中 $a,b,p$ 分别为题目给定的值， $s$ 为运算结果。

## 样例 #1

### 样例输入 #1

```
2 10 9
```

### 样例输出 #1

```
2^10 mod 9=7
```

## 提示

**样例解释**

$2^{10} = 1024$，$1024 \bmod 9 = 7$。

**数据规模与约定**

对于 $100\%$ 的数据，保证 $0\le a,b < 2^{31}$，$a+b>0$，$2 \leq p \lt 2^{31}$。
