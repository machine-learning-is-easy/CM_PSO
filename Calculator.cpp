#include <math.h>
extern float **injection;  
extern int start;
float Calculator(int i,int m,float tao_p)//由注水量和油井压力数据计算产液量用到的积分项
  {
	  float cal=0;
	  int k;

	  cal=exp((0-i)/tao_p)*injection[0][m]/tao_p/2;

	  for(k=1;k<i;k++)
		  cal=cal+exp((k-i)/tao_p)*injection[k][m]/tao_p;
	  cal=cal+injection[i][m]/tao_p/2;
	  
	  return cal;

	  	  //cal=0;
	  //j=length(vector);
	  //cal=cal+exp((1-j)/tao_p)*vector(1)/tao_p/2;
	  //for k=2:j-1
	//	  cal=cal+exp((k-j)/tao_p)*vector(k)/tao_p;
	 // end
	//	  cal=cal+vector(j)/tao_p/2;
  }