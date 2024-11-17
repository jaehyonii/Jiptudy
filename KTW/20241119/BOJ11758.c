#include <stdio.h>

int main() {
    int x1,x2,x3,y1,y2,y3;
    int result;
    
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    
    if ((x2 - x1) * y3 - (y2 - y1) * x3 > (x2 - x1) * y1 - (y2 - y1) * x1)
        result = 1;
    else if((x2 - x1) * y3 - (y2 - y1) * x3 < (x2 - x1) * y1 - (y2 - y1) * x1)
        result = -1;
    else result = 0;
    
    printf("%d\n", result);
    return 0;
}