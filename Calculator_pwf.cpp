#include <math.h>
extern float *Pwf;
  
  float Calculator_pwf(int i,float tao_p)//���;�ѹ�����ݼ����Һ���õ��Ļ�����
  
  {
	  float cal=0;
	  int k;
	  cal=cal+exp((0-i)/tao_p)*Pwf[0]/tao_p/2;
	  for(k=1;k<=i-1;k++)
		  cal=cal+exp((k-i+1)/tao_p)*Pwf[k]/tao_p;
	  cal=cal+Pwf[i]/tao_p/2;
	  return cal;

	  //cal=0;
	  //j=length(vector);
	  //cal=cal+exp((1-j)/tao_p)*vector(1)/tao_p/2;
	  //for k=2:j-1
	//	  cal=cal+exp((k-j)/tao_p)*vector(k)/tao_p;
	 // end
	//	  cal=cal+vector(j)/tao_p/2;
  }
