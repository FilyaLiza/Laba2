#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void Dump(double S, double Poxb, int n) //����� ���������� �� ������� ����� �������
{
    //S ���� ��� ����� ���������
    printf("S=%lf\n",S);
    printf("Poxb=%lf\n", Poxb);
    printf("Amount of points=%d\n", n);
}

double Funk(double x) // ������� ������� ��������� ,���������� ��������� ���������
{
    /* ������� 25
    �������� �� 0 �� 1 pow(x,3)/(pow(x,8)+1)
    */
    return(pow(x,3)/(pow(x,8)+1));
}

double Rectangles(int n,double A, double B) //����� ��������� � ������� ��������������
{
    double h, S, x;
    h=(B-A)/n;
    for(x=A; x<=B; x=x+h)
    {
        S=S+Funk(x);
    }
    S=S*h;
    return S;
}

double Trapezia(int n, double A, double B) // ����� ��������
{
    double h, S=0, x;
    h=(B-A)/n;
    S=Funk(A)+Funk(B);
    for(x=A; x<=B; x=x+h)
    {
        S=S+Funk(x);
    }
    S=S*h;
    return S;
}

double Sims(int n, double A, double B) // ������ �������
{
    // S ��� �������� SS ��� ������
    double h, S=0, SS=0;
    int i=0;
    h=(B-A)/n;
    for (i=0; i<=n; i++)
    {
        if (i%2 !=0)
        {
            S=S+Funk(A+h*i);
        }
        if (i%2 ==0)
        {
            SS=SS+Funk(A+h*i);
        }
    }
    S=((B-A)/(3*n))*(Funk(A)+4*S+2*SS+Funk(B));
    return S;
}

/* ������� 25
    �������� �� 0 �� 1 (pow(x,3)/(pow(x,8)+1))
    */
int main ()
{

int varik, n, i, j=1;
double h, d, x, S=0.0, SS=0.0, A, B;
while(1) //������������ ���� ����� � ������� 1, ���� ��� 0 �� ���� �� ����������� ������
{
  printf("Choise one method: \n");
  printf("1 - Method of rectangles\n2 - Method of trapezoidal\n3 - Simpson method\n4 - Usual method\n5 - Demo version(y = 2x)\n");
  scanf("%d",&varik);

  switch("%d",varik)
  {
  case 1: // ����� ��������������
    printf("Amount of points: \n");
    scanf("%d", &n);
    printf("Write limit: \n");
    scanf("%lf",&A);
    printf("upper border: \n");
    scanf("%lf",&B);
    for(j; j<=2; j++)
    {
        if(j==1)
        {
            S=Rectangles(n,A,B);
            n=n+2;
        }
        SS=Rectangles(n,A,B);
        if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001) //��������� �� �� ������ fabs=������
        {
            SS=fabs(S-SS);
            Dump(S, SS, n);
            break;
        }
        else
            {
                j=0; //���� ���� ����� �� �� ���������� � ������
            }
    }


  break;


  case 2: // ����� ��������
    printf("Amount of points: \n");
    scanf("%d", &n);
    printf("Write limit: \n");
    scanf("%lf",&A);
    printf("upper border: \n");
    scanf("%lf",&B);
    for(j; j<=2; j++)
    {
        if(j==1)
        {
            S=Trapezia(n,A,B);
            n=n+2;
        }
        SS=Trapezia(n,A,B);
        if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)
        {
            SS=fabs(S-SS);
            Dump(S, SS, n);
            break;
        }
        else
        {
            j=0;
        }
    }
    break;


    case 3: //����� �������
        do
        {
            printf("This method must have an even number of intervals \n");
            printf("Count of steps: \n");
            scanf("%d",&n);
        }
        while(n%2!=0);
        printf("Write limit: \n");
        scanf("%lf",&A);
        printf("upper border: \n");
        scanf("%lf",&B);

        for(j; j<=2;j++)
        {
              if(j==1)
              {
               S = Sims(n,A,B);
               n=n+2;
              }
            SS = Sims(n,A,B);
            if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)
            {
                SS = fabs(S-SS);
                Dump(S,SS,n);
                break;
            }
            else
            {
                j=0;
            }
        }
        break;

    case 4: //������� ����� ,������� �� �����������
        printf("Write limit: \n");
        scanf("%lf",&A);
        printf("upper border: \n");
        scanf("%lf",&B);
        S=(atan(pow(A,4))/4);
        SS=(atan(pow(B,4))/4);
        S=SS-S; //������� ��������
        printf("S: %lf \n\n", S);
        break;


    case 5: //Demo version(y = 2x)
        printf("My integral is (0->1)y=2x \n");
        printf("Amount of points: \n");
        scanf("%d",&n);
        printf("Write limit: \n");
        scanf("%lf",&A);
        printf("upper border: \n");
        scanf("%lf",&B);
        printf("Answer =1 if limit is 0->1\n"); // ������ ���� ������������ ������ ������������ � �������� �� ���� �������
        // 1 met
        h = ((B-A)/n);
        h=(B-A)/n;
        for(x= A; x<= B ;x=x + h)
        {
          S=S+(2*x);
        }
        S=S*h;
        printf("Method of rectangles: %lf \n",S);
        // 2 met
        h=(B-A)/n;
        S=(2*A)+(2*B);
        for(x= A; x<= B ;x=x+h)
        {
        S=S+(2*x);
        }
        S=S*h;
        printf("Method of trapezoidal: %lf \n",S);
        // 3 met
         h=((B-A)/n);
        for(i = 0; i<=n; i++)
        {
            if(i%2 !=0)
            {
              S=S+(2*(A+h*i));
            }
            if(i%2 ==0)
            {
              SS=SS+((A+h*i)*2);
            }
        }
        S=((B-A)/(3*n))*((2*A)+4*S+2*SS+(2*B));
        printf("Simpson method : %lf\n\n",S);
        break;
        default:
        printf("No of variants \n");// ������ �� ��� �� ��������
        break;
  }
}
  return 0;
}


