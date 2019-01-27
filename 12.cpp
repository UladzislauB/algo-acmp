#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int border(double* x, double* y)
{
	for(int i=1; i<4; i++)
	{
		double temp=(x[0]-x[i])/(x[i+1]-x[i])-(y[0]-y[i])/(y[i+1]-y[i]);
		if(temp==0) return 1;
	}
	if((x[0]-x[1])/(x[4]-x[1])-(y[0]-y[1])/(y[4]-y[1])==0) return 1;
	return 0;
}

double triangle_area(double x1,double y1,double x2,double y2,double x3,double y3)
{
	double area=(x1-x3)*(y2-y3)-(y1-y3)*(x2-x3);
	return abs(area/2);
}

double rectangle_area(double x1,double y1,double x2,double y2,double x3,double y3)
{
	double a1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double a2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	return a1*a2;
	
}

int main()
{
	double x[5],y[5],n,minX,minY;
	int sum=0;
	fin>>n;
	for(int p=0; p<n; p++)
	{
		minX=0;
		minY=0;
		for(int j=0; j<5; j++)
		{
			fin>>x[j]>>y[j];
			if(x[j]<minX) minX=x[j];
			if(y[j]<minY) minY=y[j];
		}
		for(int j=0; j<5; j++)
		{
			x[j]-=minX;
			y[j]-=minY;
		}
		
		if(border(x,y)==1)
			sum++;
		else
		{
			double area1=0,area2;
			area1+=triangle_area(x[0],y[0],x[1],y[1],x[2],y[2]);
			area1+=triangle_area(x[0],y[0],x[2],y[2],x[3],y[3]);
			area1+=triangle_area(x[0],y[0],x[3],y[3],x[4],y[4]);
			area1+=triangle_area(x[0],y[0],x[1],y[1],x[4],y[4]);
			area2=rectangle_area(x[1],y[1],x[2],y[2],x[3],y[3]);
			if(abs(area2-area1)<1) sum++;
		}			
	}
	fout<<sum;
	return 0;
}
