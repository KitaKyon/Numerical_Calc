/***************************************************/
/*        2���@�̃v���O����           nibun.c      */
/***************************************************/
#include <stdio.h>
/***  �֐��̒�`  ***/
#define  FNF(x)   (x*x*x - 3*x*x + 9*x - 8)
int main(void) 
{   double  a, b, c;
    int     k;
    char    z, zz;
    while( 1 ) {
        printf("f(a)*f(b)<0�ƂȂ� a , b ��");
        printf("���͂��Ă��������D\n\n");
        printf("��1��� [a,b] �� a="); 
        scanf("%lf%c",&a,&zz);
        printf("��1��� [a,b] �� b="); 
        scanf("%lf%c",&b,&zz);
        printf("\n���������͂��܂������H(y/n)"); 
        scanf("%c%c",&z,&zz);
        if(z == 'n')   continue;  
        if((z == 'y')&&(a < b)&&(FNF(a) * FNF(b) < 0))  
                                           break;
        else {
            printf("\na>b �� f(a)*f(b)>=0 �ɂȂ�܂��D\n");
            printf("�f�[�^����꒼���Ă��������D\n");
            printf("�G���^�[�L�[�������Ă��������D\n");
            scanf("%c",&z);  continue;
        }
    }
    k = 0;  
    printf("��    ���[A    �E�[B ��ԕ�B-A\n");
    /*** ��������܂ŌJ��Ԃ� ***/      
    while( b - a >= 0.000001) {
        k = k + 1;
        printf("%4d %8.5lf %8.5lf %8.5lf\n",k,a,b,b-a);
        /* �_ a,b �̒��_�����߁Ca,b �̍��W���X�V���� */
        c = ( a + b ) / 2.0;
        if( FNF(a) * FNF(c) > 0 )   a = c;
        else                b = c;
        if((k % 10) == 0) {
            printf("\n�v�Z�ߒ���\�����Ă��܂��D\n");
            printf("�\�����p�����܂����H (y/n): "); 
            scanf("%c%c",&z,&zz);
            if(z == 'n') {
                printf("\n�\�����I���܂��D\n");  break;
            } else  if(z == 'y')
              printf("��    ���[A    �E�[B ��ԕ�B-A\n");
                    else   { z = 'n';  break; }
        }
    }
    if(z != 'n') {
        printf("\n %3d ��ڂŎ������܂����D\n",k);
        printf("\n�����l = %10.6lf\n", (a+b)/2.0);
    }
    return 0;
}
