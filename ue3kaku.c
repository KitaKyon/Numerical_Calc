/***************************************************/
/*     上三角型の連立方程式の解法     ue3kaku.c    */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define    N       8
int main(void)
{   int     k, j, n;
    char    z, zz;
    static double  p, s, a[N][N+1], x[N];
    /***  a[N][N+1]: 拡大係数行列,  x[N]: 解 ***/
    while ( 1 ) {
        printf("上三角型の連立方程式の解法 \n");
        printf("未知数の個数 n を");
        printf("入力してください．(1<n<7) n="); 
        scanf("%d%c",&n,&zz);
        if((n <= 1) || (7 <= n))   continue;
        printf("係数を入力してください\n\n");
        /***  拡大係数行列を入力する． ***/ 
        /***  右辺の値は第 n+1 列目に入れる  ***/  
        for(k=1; k<=n; k=k+1) {
            for(j=k; j<=n+1; j=j+1) {
                printf("a( %d , %d ) = ",k,j); 
                scanf("%lf%c",&a[k][j],&zz);
            }
            printf("\n");
        }
        printf("正しく入力しましたか？ (y/n) ");   
        scanf("%c%c",&z,&zz);
        if(z == 'y')    break; 
    }
    /***  計算開始  ***/
    for(k=1; k<=n; k=k+1) {
        p = a[k][k];
        if(fabs(p) < 1.0e-6) {
            printf("一意解をもちません．\n"); 
            exit(-1);
        }
        /*** 第 k 行を (k,k) 成分で割る．***/
        for(j=k; j<=n+1; j=j+1)
            {  a[k][j] = a[k][j] / p;  }
    }
    /***  逆進代入による計算  ***/
    for(k=n; k>=1; k=k-1) {
        s = 0.0;
        for(j=k+1; j<=n; j=j+1) {
            s = s + a[k][j] * x[j];
        }
        x[k] = a[k][n+1] - s;
    }
    /***  解の出力  ***/
    printf("\n上三角型の連立方程式の解\n\n");
    for(k=1; k<=n; k=k+1) {
        printf("x( %d ) = %10.6lf\n",k,x[k]);
    }
    return 0;
}
