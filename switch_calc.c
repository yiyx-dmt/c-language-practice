#include<stdio.h>
int main()
{
	int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    switch (a) {
    case 1:
        printf("%d+%d=%d\n", b, c, b + c);
        break;
    case 2:
        printf("%d-%d=%d\n", b, c, b - c);
        break;
    case 3:
        printf("%d*%d=%d\n", b, c, b * c);
        break;
    default:
        printf("(%d+%d)*(%d-%d)=%d\n", b, c, b, c, (b + c) * (b - c));
    }
}