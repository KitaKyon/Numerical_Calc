/***************************************************/
/*      1�d�w���֐��^�ϊ��ɂ��ϕ�    sisukan1.c  */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define  PI             3.141592653589793
#define  FNF(x)         pow(x, 50.0) 
#define  FNFTAU(a,b,x)  (b-a)/2.0*x+(b+a)/2.0
#define  FNG(x)         2.0/PI*atan(exp(x)-exp(-x))
int main(void) 
{   int     i, n;             /* n   :���a�͈�  */
    double  h, t, u, a, b;    /* a,b :�ϕ����  */
    double  g1, x, s, ss;     /* ss  :�ϕ��l    */
    char    z, zz;
    while( 1 ){
        printf("1�d�w���֐��^�ϊ��ɂ��ϕ�");
        printf("\n\n   f(x) = x^50\n\n");
        printf("�ϕ���� [a , b] ��  a = ");   
        scanf("%lf%c",&a,&zz);
        printf("�ϕ���� [a , b] ��  b = ");   
        scanf("%lf%c",&b,&zz);
        printf("���a�͈̔�( -n �` n-1) n = ");   
        scanf("%d%c",&n,&zz);
        printf("\n���������͂��܂������H(y/n) ");
        scanf("%c%c",&z,&zz);
       if(z == 'y')    break;  
    }
    h = 0.1;    s = 0.0;
    printf("\n   �v�Z���ł��D\n\n");
    for(i = -n; i<=n-1; i++) {
        t = h * i;
        u = FNG(t);
        g1 = 2.0/PI*(exp(t)+exp(-t)) / 
                    (1+pow(exp(t)-exp(-t),2.0));
        x = FNFTAU(a,b,u);
        s += FNF(x) * g1 * h;
    }
    ss = s * (b - a) / 2.0;
    printf("�ϕ��l = %10.6lf\n",ss);
    return 0;
}
