#include <stdio.h>

int main() {
    int r1,r2;
    scanf("%d%d",&r1,&r2);
    printf("%.1f",(float)(r1*r2)/(r1+r2));
    return 0;
}
#include <stdio.h>

int main() 
{
    int h,r;
    scanf("%d%d",&h,&r);
    float v = 3.14*h*r*r;
    int count = 0;
    float c = 10000;
    while(c>0)
    {
        c = c-v;
        count++;
    }
    printf("%d",count);
    return 0;
}
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d",&a,&b);
    int d = b-a;
    int c = b +d;
    printf("%d",c);
    return 0;
}
#include <stdio.h>

int main() {
    int r;
    scanf("%d",&r);
    printf("%.2f",(float)4/3*3.14*r*r*r);
    return 0;
}
#include <stdio.h>

int main() {
    int hour1,hour2,min;
    scanf("%d:%d %d",&hour1,&hour2,&min);
    hour1 = (hour1+(hour2+min)/60)%24;
    hour2 = (hour2+min)%60;
    printf("%#02d:%#02d",hour1,hour2);
    return 0;
}