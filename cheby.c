/***************************************************/
/*     �x�V���̐��l�ϕ������ɂ��v�Z   cheby.c    */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define    FNF(x)  (1.0 - x) * exp(-x)
#define    PI      3.141592653589793
#define    N       50
int main(void)
{   int     i, j, k, n, m;
    double  cs[N], e[N], h[N], a, b, s, x, t, s1;
    char    z, zz;
    while( 1 ) {
        printf("�x�V���̌����ɂ��ϕ��v�Z\n\n");
        printf(" f(x) = (1.0 - x) * exp(-x)\n\n");
        printf("�`�F�r�V�F�t��Ԃ̎���   n = ");    
        scanf("%d%c",&n,&zz);
        printf("�ϕ���� [a , b] �� a = ");
        scanf("%lf%c",&a,&zz);
        printf("�ϕ���� [a , b] �� b = ");
        scanf("%lf%c",&b,&zz);
        printf("\n���������͂��܂������H(y/n) ");  
        scanf("%c%c",&z,&zz);
        if(z == 'y')   break;  
    }
    m = n + 1;
    /***  ��_�̌v�Z  ***/
    for(i=0; i<=n; i++) {
        t = (2 * i + 1) * PI / (2 * m);
        e[i] = t;       cs[i] = cos(t);
    }
    /***  �d�݂̌v�Z  ***/
    for(i=0; i<=n; i++) {
        s1 = 0.0;      t = e[i];
        for(j=2; j<=n; j+=2) {
            s1 += cos(j * t) / (j * j - 1);
        }
        h[i] = (1 - 2 * s1) / m;
    }
    /***  �ϕ��l�̌v�Z  ***/
    s = 0.0;
    for(k=0; k<=n; k++) {
        x = ((b - a) * cs[k] + (b + a)) / 2.0;
        s += FNF(x) * h[k];
    }
    s = (b - a) * s;
    printf("\n��ϕ��̒l = %10.6lf\n",s);
    return 0;
}
