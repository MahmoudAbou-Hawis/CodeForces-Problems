#include <stdio.h>

int main()
{
    int vp,vd,t,f,c;
    scanf("%d%d%d%d%d",&vp,&vd,&t,&f,&c);
    double dist = (vp*t);
    int steps = 0;
    while (c - dist > 0 && vp <= vd)
    {
        double dx = ((double)(dist * vp) / (-vp + vd));
        if(dx + dist < c) steps++;
        double totalTime = ((double)(dx + dist) /vd) + f;
        dist += (totalTime * vp) + dx;
    }
    printf("%d",steps);

    return 0;
}