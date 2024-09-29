#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dp[5001];
    int num, max;
    
    scanf("%d", &num);
    for (int i = 0; i < 5001; i++)
        dp[i] = -1;
    dp[3] = 1;
    dp[5] = 1;
    for (int i = 6; i <= num; i++)
    {
        if (dp[i-3] != -1 || dp[i-5] != -1)
        {
            if (dp[i-3]!=-1 && dp[i-5]!=-1)
                dp[i] = (dp[i-3]<dp[i-5]?dp[i-3]:dp[i-5]) + 1;
            else if (dp[i-3] == -1)
                dp[i] = dp[i-5]+1;
            else
                dp[i] = dp[i-3]+1;
        }
    }
    printf("%d\n", dp[num]);
    return 0;
}