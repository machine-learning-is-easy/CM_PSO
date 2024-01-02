#include <iostream>
#include <afx.h>
#include "stdio.h"
#include <memory>
#include <stdlib.h>

using namespace std;

#include <matlib.h>
#include "Calculator.h"
#include "compute_value.h"
#include "drawpicture.h"
#include "cstdlib" 


float data;
float *production;
float **injection;
int start=10;
float **v;
int injection_number;
int production_number;
float Pwf_flag=0;
float ridge=0;
float *Q;//截取的用于计算的产液量
float lamd;
int particles_num=64;    //为每口油井的各个参数初始化粒子数;
int splitup=2;  //把搜索范围分成份数，用来对粒子进行初始化操作;
extern float**particle;
main()
{
	int nx; //数据行数
	int ny; //数据列数
	int i,j,k,m,n,mn;
	int tao_num;
	int times=0;
	float w=0.2;
	float **present;
	float **pbest;
	float *gbest;
	float *perr;

	FILE *f;
	CString data_file_directory="data";
	CString str1[20],str2[20];
	SetCurrentDirectory("D:\\C\\Matlab-c工程\\PSO");
	if((f=fopen(data_file_directory,"r"))==NULL)
		exit(0);
	
	fscanf(f,"%s %s\n",str1,str2);
	nx=atof((char*)(LPCTSTR)str2);
	fscanf(f,"%s %s\n",str1,str2);
	ny=atof((char*)(LPCTSTR)str2);
	fscanf(f,"%s\n",str1);
//matlab函数的头文件
//指定data的大小，对data进行赋值；
//读取文件的头文件，对data赋值
// nx：文件的行数
// ny：文件的列数
//<<<<<<<<<<<<<<
	data=new float*[nx];
		
	for(i=0;i<nx;i++)
	{
		data[i]=new float[ny];
	}
	//production=data(:,1);

	for(i=0;i<nx;i++)
	{
		production[i]=data[i][0];
	}
	//injection=data(:,2:end);
	for(i=0;i<nx;i++)
	{
		for(j=1;j<ny;j++)
		{
			injection[i][j-1]=data[i][j];
		}
	}

	injection_number=ny-1;
	//production_number=length(production(1,:));
	//Q=production(start:end,:);
	for(i=start-1;i<nx;i++)
	{
		Q[i-start+1]=data[i][0];
	}

	//initialization of particles;

	if(Pwf_flag==0)
    //不考虑压力项，每口油井对应的参数为6个（仅在此模拟结果为5个）；
	{	
			int ks=0;
			while(ks<particles_num)
			for (i=0;i<splitup;i++)			
				for (j=0;j<splitup;j++)				
					for (k=0;k<splitup;k++)					
						for (m=0;m<splitup;m++)						
							for (n=0;n<splitup;n++)							
								for (mn=0;mn<splitup;mn++)
								{
									particle[1][ks]=i*10;
									particle[2][ks]=j*10;
									particle[3][ks]=k*10;
									particle[4][ks]=m*10;
									particle[5][ks]=n*10;
									particle[6][ks]=mn*10;									
									ks=ks+1;        
								}
	}
else
{
}
if(Pwf_flag==0)
{
	v=new float*[injection_number+1];
		
	for(i=0;i<injection_number+1;i++)
	{
		v[i]=new float[particles_num];
	}


	for (i=0;i<injection_number+1;i++)
	{
		for(j=0;j<particles_num;j++)
		{			
			v[i][j]=rand();
		}
	}

}    
else
{
}

//begin PSO


   present=new float*[injection_number+1];
	for(i=0;i<injection_number+1;i++)
	{
		present[i]=new float[particles_num];
	}
	for (i=0;i<injection_number+1;i++)
	{
		for(j=0;j<particles_num;j++)
		{
			present[i][j]=particle[i][j];
		}
	}
	

	 pbest=new float*[injection_number+1];
		 
	for(i=0;i<injection_number+1;i++)
	{
		pbest[i]=new float[particles_num];
	}
	for (i=0;i<injection_number+1;i++)
	{
		for(j=0;j<particles_num;j++)
		{
			pbest[i][j]=particle[i][j];
		}
	}


	gbest=new float[injection_number+1];

    present=new float*[injection_number+1];	
	for(i=0;i<injection_number+1;i++)
	{
		present[i]=new float[particles_num];
	}
	for (i=0;i<injection_number+1;i++)
	{
		for(j=0;j<particles_num;j++)
		{
			present[i][j]=particle[i][j];
		}
	}

	int gerr=100000;

	perr=new float[particles_num];
	 
	
	 if (Pwf_flag==0)
	 {
		 tao_num=injection_number+1;
	 }
	 else
	 {
		 tao_num=injection_number+2;
	 }




//begin loop
	 initM(MATCOM_VERSION);
	 while(times<100)
	 {		 
    
        for(i=0;i<particles_num;i++)  
		{
            for(k=0;k<tao_num;k++)                
			{
				if(present[k][i]<1)
					present[k][i]=1;
				else if(present[k][i]>1000)
                   present[k][i]=1000;
			}
		}
 ////here;       
        for (k=1;k<particles_num;k++)
            [err(k),lamd(:,k)]=compute_value(present(:,k));//k口油井，第i个粒子的误差
        
        for (k=0;k<particles_num;k++)
            if err(k)<perr(k,P_n)
               perr(k,P_n)=err(k);
               pbest(:,k,P_n)=present(:,k,P_n);
            end
            if err(k)<gerr(P_n)
                gerr(P_n)=err(k);
                gbest(:,P_n)=present(:,k,P_n);               
            end
            v(:,k,P_n)=w*v(:,k,P_n)+2*rand(1,1)*(pbest(:,k,P_n)-present(:,k,P_n))+3*rand(1,1)*(gbest(:,P_n)-present(:,k,P_n));
            present(:,k,P_n)=present(:,k,P_n)+v(:,k,P_n);
            
        end
    end
    times=times+1;
	 }
	drawpicture();
	ExitM();

	free(data);
	free(production);
	free(injection);
	free(particle);
	free(present);
	free(pbest);
	free(gbest);
	free(perr);
}