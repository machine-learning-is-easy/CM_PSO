//#include <string.h>
#include <afx.h>
#include "stdio.h"
#include <memory>
//#include <stdlib.h>
#include "matlib.h"
#include "Calculator.h"
#include "compute_value.h"
#include "drawpicture.h"
#include "cstdlib" 
float ** data;
float *production;
float **injection;
int start=10;//从start开始计算
float **v;
int injection_number;
int production_number;
int Pwf_flag=0;
float ridge=0;
//float *Q;//截取的用于计算的产液量
float lamd;
int particles_num=64;    //为每口油井的各个参数初始化粒子数;
int splitup=2;  //把搜索范围分成份数，用来对粒子进行初始化操作;
int data_len;
float *Pwf;
int P_row;
float a;
double gerr=100000;

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
	float**particle;
	float *buffer;
	char str1[20],str2[20],str3[20],str4[20],str5[20],str6[20];
	float *err;
	FILE *f;	
	char  data_file_directory[20]="data.txt";

	initM(MATCOM_VERSION);

	
	SetCurrentDirectory("D:\\C\\Matlab-c工程\\PSO");
	if((f=fopen(data_file_directory,"r"))==NULL)
		exit(0);
	
	fscanf(f,"%s %s\n",str1,str2);
	nx=atof(str2);
	data_len=nx;
	fscanf(f,"%s %s\n",str1,str2);
	ny=atof(str2);
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
	i=0;
	while((fscanf(f,"%s %s %s %s %s %s\n",str1,str2,str3,str4,str5,str6)!=NULL)&&i<nx)
	{
		data[i][0]=atof(str1);
		data[i][1]=atof(str2);
		data[i][2]=atof(str3);
		data[i][3]=atof(str4);
		data[i][4]=atof(str5);
		data[i][5]=atof(str6);
		i++;
	}


	fclose(f);
	production=new float[nx];
	injection=new float*[nx];
	for(i=0;i<nx;i++)
	{
		injection[i]=new float[ny-1];
	}

	for(i=0;i<nx;i++)
	{
		production[i]=data[i][0];
	}
	//injection=data(:,2:end);
	for(i=0;i<nx;i++)
	{
		for(j=1;j<ny;j++)
		{
			a=data[i][j];
			injection[i][j-1]=data[i][j];
		}
	}

	injection_number=ny-1;
	if(Pwf_flag==0)
	{
		P_row=injection_number+1;
	}
	else
		P_row=injection_number+2;
	//production_number=length(production(1,:));

	//initialization of particles;


	particle=new float*[P_row];		
	for(i=0;i<P_row;i++)
	{
		particle[i]=new float[particles_num];
	}
	if(Pwf_flag==0)
    //不考虑压力项，每口油井对应的参数为6个（仅在此模拟结果为5个）;
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
									particle[0][ks]=(i+1)*10;
									particle[1][ks]=(j+1)*10;
									particle[2][ks]=(k+1)*10;
									particle[3][ks]=(m+1)*10;
									particle[4][ks]=(n+1)*10;
									particle[5][ks]=(mn+1)*10;									
									ks=ks+1;        
								}
	}
else
{
}

	v=new float*[P_row];		
	for(i=0;i<P_row;i++)
	{
		v[i]=new float[particles_num];
	}

	for (i=0;i<P_row;i++)
	{
		for(j=0;j<particles_num;j++)
		{			
			v[i][j]=rand();
		}
	}

	present=new float*[P_row];
	for(i=0;i<P_row;i++)
	{
		present[i]=new float[particles_num];
	}

	pbest=new float*[P_row]; 
	for(i=0;i<P_row;i++)
	{
		pbest[i]=new float[particles_num];
	}

	gbest=new float[P_row];

	err=new float[particles_num];

	perr=new float[P_row];

	buffer=new float[P_row];


//begin PSO


   
	for (i=0;i<injection_number+1;i++)
	{
		for(j=0;j<particles_num;j++)
		{
			present[i][j]=particle[i][j];
		}
	}	

		for (i=0;i<injection_number+1;i++)
	{
		for(j=0;j<particles_num;j++)
		{
			pbest[i][j]=particle[i][j];
		}
	}
    
	for (i=0;i<injection_number+1;i++)
	{
		for(j=0;j<particles_num;j++)
		{
			present[i][j]=particle[i][j];
		}
	}	
	 if (Pwf_flag==0)
	 {
		 tao_num=injection_number+1;
	 }
	 else
	 {
		 tao_num=injection_number+2;
	 }

//begin loop


	 while(times<50)
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
        for (k=0;k<particles_num;k++)
		{
			for(i=0;i<P_row;i++)
				buffer[i]=present[i][k];

            err[k]=compute_value(buffer);//k口油井，第i个粒子的误差
		}

		for (k=0;k<particles_num;k++)
        {
			if (err[k]<perr[k])
            {
			   perr[k]=err[k];
			   for(i=0;i<P_row;i++)
			   {
				   pbest[i][k]=present[i][k];
			   }
			}            
            if (err[k]<gerr)
			{
                gerr=err[k];
				for (i=0;i<P_row;i++)
				{
					gbest[i]=present[i][k];               
				}
			} 
			
			for (i=0;i<P_row;i++)
			{
				
				v[i][k]=w*v[i][k]+2*rand()*(pbest[i][k]-present[i][k])+3*rand()*(gbest[i]-present[i][k]);
				present[i][k]=present[i][k]+v[i][k];
			}       
		}


		display(gerr);
    
    times=times+1;
	 }
	drawpicture(gbest);

	exitM();

	free(data);
	free(production);
	free(injection);
	free(particle);
	free(present);
	free(pbest);
	free(gbest);
	free(perr);
	free(buffer);
	free(v);
	free(err);
	if(Pwf_flag==0)
	  free(Pwf);
	
}