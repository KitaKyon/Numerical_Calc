/***************************************************/
/*     ��O�p�^�̘A���������̉�@     ue3kaku.c    */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define    N       8
int main(void)
{   int     k, j, n;
    char    z, zz;
    static double  p, s, a[N][N+1], x[N];
    /***  a[N][N+1]: �g��W���s��,  x[N]: �� ***/
    while ( 1 ) {
        printf("��O�p�^�̘A���������̉�@ \n");
        printf("���m���̌� n ��");
        printf("���͂��Ă��������D(1<n<7) n="); 
        scanf("%d%c",&n,&zz);
        if((n <= 1) || (7 <= n))   continue;
        printf("�W������͂��Ă�������\n\n");
        /***  �g��W���s�����͂���D ***/ 
        /***  �E�ӂ̒l�͑� n+1 ��ڂɓ����  ***/  
        for(k=1; k<=n; k=k+1) {
            for(j=k; j<=n+1; j=j+1) {
                printf("a( %d , %d ) = ",k,j); 
                scanf("%lf%c",&a[k][j],&zz);
            }
            printf("\n");
        }
        printf("���������͂��܂������H (y/n) ");   
        scanf("%c%c",&z,&zz);
        if(z == 'y')    break; 
    }
    /***  �v�Z�J�n  ***/
    for(k=1; k<=n; k=k+1) {
        p = a[k][k];
        if(fabs(p) < 1.0e-6) {
            printf("��Ӊ��������܂���D\n"); 
            exit(-1);
        }
        /*** �� k �s�� (k,k) �����Ŋ���D***/
        for(j=k; j<=n+1; j=j+1)
            {  a[k][j] = a[k][j] / p;  }
    }
    /***  �t�i����ɂ��v�Z  ***/
    for(k=n; k>=1; k=k-1) {
        s = 0.0;
        for(j=k+1; j<=n; j=j+1) {
            s = s + a[k][j] * x[j];
        }
        x[k] = a[k][n+1] - s;
    }
    /***  ���̏o��  ***/
    printf("\n��O�p�^�̘A���������̉�\n\n");
    for(k=1; k<=n; k=k+1) {
        printf("x( %d ) = %10.6lf\n",k,x[k]);
    }
    return 0;
}
