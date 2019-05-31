/****************************************************/
/*    堀之内の数値積分公式による2重積分   cheby2j.c */
/****************************************************/
#include <stdio.h>
#include <math.h>
#define  PI          3.141592653589793
#define  FNF(x,y)    (x + y * y) 
#define  FNP1(x)     1.0
#define  FNP2(x)     1.0 + 0.5 * x
#define  N           20
int main(void)
{   int     m, n, i, j, k;
    double  s1, sx, sy, s, t, x, y, fp1, fp2, yi;
    double  a, b, cs[N], e[N], h[N];
    printf("堀之内の公式による2重積分の計算\n");
    printf("\n  f(x , y) = ( x + y * y )\n\n");
    printf("チェビシェフ補間の次数(1<n<20) n = ");    
    scanf("%d",&n);
    m = n + 1;
    a = 0.0;     b = 2.0;
    /*** 零点の計算 ***/
    for(i=0; i<=n; i++) {
        t    = (2.0*i+1.0)*PI / (2.0*(n+1.0));
        e[i] = t;     cs[i] = cos(t);
    }
    /*** 重みの計算 ***/
    for(i=0; i<=n; i++) {
        s1 = 0.0;     t = e[i];
        for(j=2; j<=n; j+=2) {
            s1 += (cos(j * t)) / (j * j - 1.0);
         }
        h[i] = (1.0 - 2.0 * s1) / m;
    }
    sx = 0.0;
    for(i=0; i<=n; i++) {
        /***  τ（t）による変換  ***/
        x   = ((b - a) * cs[i] + (b + a)) / 2.0;
        fp1 = FNP1(x);   fp2 = FNP2(x);  sy  = 0;
        for(k=0; k<=n; k++) {
            /*** ∫F(x,y)dy　の計算  ***/ 
            y  = ((fp2-fp1)*cs[k]+(fp2+fp1))/2.0 ;
            sy +=  FNF(x,y) * h[k];
        }
        yi = (fp2 - fp1) * sy;
        sx += yi * h[i];
    }
    s = (b - a) * sx;
    printf("\n定積分の値 ＝ %10.6lf\n",s);
    return 0;
}
