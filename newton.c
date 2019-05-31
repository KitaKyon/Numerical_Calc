/***************************************************/
/*       �j���[�g���@�̃v���O����     newton.c     */
/***************************************************/
#include <stdio.h>
#include <math.h>
/***  �֐�f(x)��f'(x)�̒�` ***/
#define  FNF(x)   (x*x*x - 3*x*x + 9*x - 8)
#define  FNG(x)   (3*x*x - 6*x + 9)
int main(void) 
{   /**  x:��1���ߎ��l, xn:�Q�����ɂ��v�Z�l  **/
    double  x, xn;   
    int     k;
    char    z, zz;
    printf("�֐�FNF(x) = x^3 - 3*x^2 + 9*x - 8\n");
    printf("�̍����j���[�g���@�ŋ��߂܂��D\n\n");
    printf("��1�ߎ��l����͂��Ă������� " );
    scanf("%lf%c",&x,&zz);
    k = 1;
    printf("��     �ߎ��l  �O�̋ߎ��l�Ƃ̍�\n");
    printf("   1 %10.6lf\n",x);
    while( 1 ) {
        k = k + 1;
        /***  �Q�����ɂ��v�Z  ***/
        xn = x - FNF(x) / FNG(x);
        printf("%4d %10.6lf    %10.6lf\n",k, xn, xn-x);
        if(fabs(xn - x) < 0.000001)   break;
        x = xn;
        if(k % 10 != 0)   continue;
        printf("\n�v�Z�ߒ���\�����Ă��܂��D\n");
        printf("\n�\�����p�����܂����H (y/n): ");  
        scanf("%c%c",&z,&zz);
        if(z == 'n') {
            printf("\n�\�����I���܂��D\n");  break;
        }else  if(z == 'y')
           printf("��     �ߎ��l  �O�̋ߎ��l�Ƃ̍�\n");
               else {  z='n';  break;  }
    }
    if(z != 'n') {
        printf("\n %3d ��ڂŎ������܂����D\n",k);
        printf("\n�����l�� %10.6lf\n",xn);
    }
    return 0;
}
