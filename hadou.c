/***************************************************/
/*    波動方程式の差分による数値解法    hadou.c    */
/*    解曲面の数値データを数表として出力する．     */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define   M     18
#define   N     10
#define  FNF(x)  0.05*x*(2.0-x)  /* 初めの弦の位置 */
int main(void)
{   int     i, j, n;
    double  a, b, h, c, k, t, x, z[N+1][M+1];
    char    zz;
    /*  M:tのステップ数  a,b:xの区間  h:xの刻み幅  */
    /***  初期設定  ***/
    a = 0.0;           b = 2.0;   h = 0.25;   
    n = (int)(b-a)/h;  c = 9.0;   k = h / sqrt(c);
    /***  Z(x,0)の計算値 ***/
    for(i=0; i<=n; i++) {
        x = a + h * i;
        z[i][0] = FNF(x);
    }
    /***  Z(0,t)=0.0  Z(8,t)=0.0  の設定  ***/
    for(j=0; j<=M; j++) {
        z[0][j] = 0.0;
        z[n][j] = 0.0;
    }
    for(i=1; i<=n-1; i++) {
        z[i][1] = (z[i+1][0] + z[i-1][0]) / 2.0;
    }
    /***  数値解の計算  ***/ 
    for(j=1; j<=M-1; j++) {
        for(i=1; i<=n-1; i++) {
            z[i][j+1]=z[i+1][j]+z[i-1][j]-z[i][j-1];
        }
    }
    printf("波動方程式の差分による数値解\n");
    printf("\n波動方程式：Ztt＝%1.0lfZxx\n",c);
    printf("\nD　      ：");
    printf("%1.0lf≦x≦%1.0lf，0≦t≦%3.1lf\n",a,b,k*M);
    printf("\n初期条件  ：Z(x,0)＝0.05x(2-x)\n");
    printf("\n横の刻み  ：h＝%4.2lf",h);
    printf("\n縦の刻み  ：k＝%4.2lf",k);
    printf("\n\nエンターキーを押せば");
    printf("計算結果を出力します\n");
    scanf("%c",&zz);
    /*  数値解の出力（ z(x,t)の値のみを出力 ）*/
    for(t=0.0, j=0; j<=M; j++) {
        for(x=0.0, i=0; i<=n; i++ ) 
           {  printf("%7.4lf",z[i][j]);  }
        printf("\n");
    }                                                      
    /*  数値解の出力 （ x, t, z(x,t)を出力 ） */
    for(t=0.0, j=0; j<=M; j++) {
        for(x=0.0, i=0; i<=n; i++ ) {
            printf("%7.4lf %7.4lf %7.4lf\n",x,t,z[i][j]);
            x = x + 0.25;
        }
        printf("\n");
        t = t + 0.25 / 3.0;
    }
    return 0;
}
