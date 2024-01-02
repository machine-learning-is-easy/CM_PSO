#include "Calculator.h"
#include "matlib.h"
#include "Calculator_pwf.h"

extern int start;
extern int P_row;
extern float **injection;
extern float *production;
extern int Pwf_flag;
extern float *Pwf;
//extern float *Q;
extern float ridge;
extern int injection_number;
extern int production_number;
extern int data_len;
//在production中第m口油井和所有注水井之间的参数；参数顺序为：注水井参数，衰竭参数，压力参数
double compute_value(float *tao)

{
	int i,k,Mt_colum;

	Mm M,Mt;
	Mm lamd;
	Mm ridge_m;
	Mm Q_m;
	Mm err_m;

	M=zeros(data_len-start+1,P_row);
	Mt=zeros(P_row,P_row);
	lamd=zeros(P_row,1);
	Q_m=zeros(data_len-start+1,1);	
	ridge_m=zeros(1);
	*ridge_m.addr()=ridge;
	err_m=zeros(1);



	for (i=start-1;i<data_len;i++)
	{
		for (k=0;k<injection_number;k++)  
	
			*M.addr(i-start+2,k+1)=Calculator(i,k,tao[k]); 
		*M.addr(i-start+2,injection_number+1)=production[0]*exp((-1*i)/tao[injection_number]);  

	//	display(*M.addr(i-start+2,1));
	//	display(*M.addr(i-start+2,2));
//		display(*M.addr(i-start+2,3));
	//	display(*M.addr(i-start+2,4));
	//	display(*M.addr(i-start+2,5));
	//	display(Calculator(i,1,tao[1]));

		
       if (Pwf_flag==1)
		   *M.addr(i+1,injection_number+2)=Pwf[0]*exp((0-i)/tao[k+1])-Pwf[i]+Calculator_pwf(i,tao[injection_number+1]);  
	   
	   *Q_m.addr(i-start+2)=production[i];

	}   
		

	
	//display(Q_m(1));
	
	//display(Q_m(data_len));
//	display(M);
	 
	Mt=mtimes(ctranspose(M),M);
	
	//display(Mt);
	 	 
	 
	  //Mt_colum=M.cols();	  
      lamd=mtimes(inv(mtimes(transpose(M),M))+mtimes(*ridge_m.addr()*(*Mt.addr(1,1)),eye(P_row)),transpose(M));
	  lamd=mtimes(lamd,Q_m);
	//  display(lamd);
	//  display(M);
      //Q_computation=M*lamd;
	  
      err_m=norm(mtimes(M,lamd)-Q_m);
	//  display(err_m);
	  return *err_m.addr();              
 
}