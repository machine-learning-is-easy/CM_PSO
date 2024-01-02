#include "Calculator.h"
#include "Calculator_pwf.h"
#include "matlib.h"
extern int start;
extern float **injection;
extern float *production;
extern int Pwf_flag;
extern float *Pwf;
extern int P_row;
extern float ridge;
extern int injection_number;
extern int production_number;
extern int data_len;


void drawpicture(float* tao)
{	

    int i,k,Mt_colum;
	Mm M,Mt;
	Mm lamd;
	Mm ridge_m;
	Mm Q_m;
	Mm err_m;
	Mm Q_c;
	Mm x;
	Mm axisxy;


	M=zeros(data_len-start+1,P_row);
	Mt=zeros(P_row,P_row);
	lamd=zeros(P_row,1);
	Q_m=zeros(data_len-start+1,1);	
	ridge_m=zeros(1);
	*ridge_m.addr()=ridge;
	err_m=zeros(1);
	Q_c=zeros(data_len-start+1,1);
	x=zeros(data_len-start+1,1);
	
	axisxy=zeros(1,4);

	*axisxy.addr(1,1)=1;
	*axisxy.addr(1,2)=data_len-start+1;
	*axisxy.addr(1,3)=0;
	*axisxy.addr(1,4)=800;







	for (i=start-1;i<data_len;i++)
	{
		for (k=0;k<injection_number;k++)  
	
			*M.addr(i-start+2,k+1)=Calculator(i,k,tao[k]); 
		*M.addr(i-start+2,injection_number+1)=production[0]*exp((-1*i)/tao[injection_number]);  

		
       if (Pwf_flag==1)
		   *M.addr(i+1,injection_number+2)=Pwf[0]*exp((0-i)/tao[k+1])-Pwf[i]+Calculator_pwf(i,tao[injection_number+1]);  
	   
	   *Q_m.addr(i-start+2)=production[i];
	   *x.addr(i-start+2)=i-start+2;

	}   
		
	 
	Mt=mtimes(ctranspose(M),M);
	  
      lamd=mtimes(mtimes(inv(mtimes(transpose(M),M))+mtimes(*ridge_m.addr()*(*Mt.addr(1,1)),eye(P_row)),transpose(M)),Q_m);
	  Q_c=mtimes(M,lamd);
	  	  
      err_m=norm(mtimes(M,lamd)-Q_m);
	 
//	  display(Q_c);
//	  display(err_m);
//	  display(lamd);

//	  display(Q_c.rows());
//	  display(linspace(1,data_len-start+1));
      //plot(linspace(1,data_len-start+1));
	  plot((CL(x),Q_c,TM("r"),Q_m,TM("b")));
	  axis(axisxy);
      //»­Í¼
      
     // plotyy(linspace(1,data_len-start+1),mtimes(M,lamd),linspace(1,data_len-start+1),Q_m);
      
      
}

 