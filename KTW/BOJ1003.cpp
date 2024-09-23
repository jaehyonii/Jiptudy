#include <stdio.h>

int zero;
int one;

#include <stdio.h>

int main()
{
    int cnt, num, zero, one;
    int dp[41];
    
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &num);
        dp[0] = 1;
        dp[1] = 0;
        for (int i = 2; i<=num; i++)
            dp[i] = dp[i-2]+dp[i-1];
        zero=dp[num];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i<=num; i++)
            dp[i] = dp[i-2]+dp[i-1];
        one=dp[num];
        printf("%d %d\n", zero, one);
    }
    return 0;
}