/*************************************************/
/*       ��`�����ɂ��ϕ��v�Z      daikei.c    */
/*************************************************/
#include <stdio.h>
#include <math.h>
#define  FNF(x)   (1.0-x)*exp(-x)
int main(void)
{   int     i, n;
    double  a, b, h, s, x;
    char    z, zz;
    while( 1 ) {
        printf("��`�����ɂ��ϕ��v�Z \n\n");
        printf(" f(x) = (1.0 - x) * exp(-x)\n\n");
        printf("�ϕ����[a , b] �� a = ");   
        scanf("%lf%c",&a,&zz);
        printf("�ϕ����[a , b] �� b = ");   
        scanf("%lf%c",&b,&zz);
        printf("������             n = ");   
        scanf("%d%c",&n,&zz);
        printf("\n\n���������͂��܂������H(y/n)");  
        scanf("%c%c",&z,&zz);
        if(z == 'y')    break; 
    }
    h = (b - a) / n;
    s = FNF(a) * h / 2.0 + FNF(b) * h / 2.0;
    for(i=1; i<=n-1; i++) {
        x = a + h * i;
        s += FNF(x) * h;
    }
    printf("\n�ϕ��̋ߎ��l = %10.6lf\n",s);
    return 0;
}
