# include <stdio.h>

int main()
{
    int n;
    int qNum = 0;

    while (scanf("%d", &n) != EOF && n != 0)
    {
        qNum++;
        if (n == 1) {
            printf("Case %d: %d\n", qNum, 1);
            continue;
        }
        int ans = -1;
        int sum = 0;
        for (int i = n-1; i >= 1; i--)
        {
            sum = 0;
            for (int j = i; j >= 1; j--)
            {
                if (i%j == 0)
                    sum += j;
            }
            if (sum == n)
            {
                ans = i;
                break;
            }
        }

        printf("Case %d: %d\n", qNum, ans);
    }
    return 0;
}
