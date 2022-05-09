# include <stdio.h>

/*
    2021/11/Problem

    假設買 n 個車輪餅
    可以可以多買 n/3 個
    這 n/3 個又可以多買到 n/9 個

    s  =      n + n/3 + n/9 + ... + 3 + 1
    3s = 3n + n + n/3 + n/9 + ... + 3
    -)
    => 2s = 3n - 1
    => s = (3n-1) / 2

    題目輸入s，求n
    2s = 3n - 1
    => 3n = 2s + 1
    => n = (2s + 1) / 3
    
    檢查一下
    s = 17   =>   n = 11.666  // 需要進位到12
    s = 13   =>   n = 9

    步驟
    step1. int n = (2s + 1) / 3
    step2. if (2s+1)%3 != 0
                n++
*/

int main()
{
    int qNum, s, n;
    scanf("%d", &qNum);
    for (int q = 1; q <= qNum; q++)
    {
        scanf("%d", &s);

        n = (2*s + 1) / 3; // 公式
        if ((2*s + 1) % 3 != 0)  // 若有小數點
            n++;  // 需再買一個

        printf("%d\n", n);
    }
    return 0;
}
