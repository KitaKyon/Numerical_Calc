/***************************************************/
/*    �g���������̍����ɂ�鐔�l��@    hadou.c    */
/*    ���Ȗʂ̐��l�f�[�^�𐔕\�Ƃ��ďo�͂���D     */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define   M     18
#define   N     10
#define  FNF(x)  0.05*x*(2.0-x)  /* ���߂̌��̈ʒu */
int main(void)
{   int     i, j, n;
    double  a, b, h, c, k, t, x, z[N+1][M+1];
    char    zz;
    /*  M:t�̃X�e�b�v��  a,b:x�̋��  h:x�̍��ݕ�  */
    /***  �����ݒ�  ***/
    a = 0.0;           b = 2.0;   h = 0.25;   
    n = (int)(b-a)/h;  c = 9.0;   k = h / sqrt(c);
    /***  Z(x,0)�̌v�Z�l ***/
    for(i=0; i<=n; i++) {
        x = a + h * i;
        z[i][0] = FNF(x);
    }
    /***  Z(0,t)=0.0  Z(8,t)=0.0  �̐ݒ�  ***/
    for(j=0; j<=M; j++) {
        z[0][j] = 0.0;
        z[n][j] = 0.0;
    }
    for(i=1; i<=n-1; i++) {
        z[i][1] = (z[i+1][0] + z[i-1][0]) / 2.0;
    }
    /***  ���l���̌v�Z  ***/ 
    for(j=1; j<=M-1; j++) {
        for(i=1; i<=n-1; i++) {
            z[i][j+1]=z[i+1][j]+z[i-1][j]-z[i][j-1];
        }
    }
    printf("�g���������̍����ɂ�鐔�l��\n");
    printf("\n�g���������FZtt��%1.0lfZxx\n",c);
    printf("\nD�@      �F");
    printf("%1.0lf��x��%1.0lf�C0��t��%3.1lf\n",a,b,k*M);
    printf("\n��������  �FZ(x,0)��0.05x(2-x)\n");
    printf("\n���̍���  �Fh��%4.2lf",h);
    printf("\n�c�̍���  �Fk��%4.2lf",k);
    printf("\n\n�G���^�[�L�[��������");
    printf("�v�Z���ʂ��o�͂��܂�\n");
    scanf("%c",&zz);
    /*  ���l���̏o�́i z(x,t)�̒l�݂̂��o�� �j*/
    for(t=0.0, j=0; j<=M; j++) {
        for(x=0.0, i=0; i<=n; i++ ) 
           {  printf("%7.4lf",z[i][j]);  }
        printf("\n");
    }                                                      
    /*  ���l���̏o�� �i x, t, z(x,t)���o�� �j */
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
