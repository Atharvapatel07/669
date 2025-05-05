#include<iostream>
#include <GL/glut.h> 
#include<math.h>
using namespace std;



int input[3][10];float output[3][10];float t[3][3];
int v;
int tx,ty;
int ROUND(float a)
{
  	return (int)(a + 0.5);
}
 
void DDALine(int xa, int ya, int xb, int yb)
{
			int dx,dy,steps;
			
			dx=xb - xa;
			dy=yb - ya;
			
			if(abs(dx) > abs(dy))
			{
				steps=abs(dx);
			}
			else 
			{
			  steps=abs(dy);
			 }
			
			float xinc,yinc;
			
			xinc = (float)(dx)/steps;
			yinc=(float)(dy)/steps;
			
			float x=xa,y=ya;
			
			
			
			glVertex2d(xa,ya);
			
			for(int i = 0; i < steps; i++)
			{
				x= x + xinc;
				y = y + yinc;
				glVertex2d(ROUND(x),ROUND(y));
			} 
			
			
}

			

void  Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    
/*DDALine(320,0,-320,0);    
DDALine(0,240,0,-240); */   


int j;

for( j=0;j<v-1;j++){
	
		DDALine(input[0][j],input[1][j],input[0][j+1],input[1][j+1]);

}
DDALine(input[0][j],input[1][j],input[0][0],input[1][0]);


int i;

for( i=0;i<v-1;i++){
	
		DDALine(output[0][i],output[1][i],output[0][i+1],output[1][i+1]);

}
DDALine(output[0][i],output[1][i],output[0][0],output[1][0]);



    glEnd();
	 glFlush();
}
		

int main(int argc,char  **argv)
{





cout<<"enter number of vertices\n";
cin>>v;

for(int i=0;i<v;i++){
		
		cin>>input[0][i];
		cin>>input[1][i];
		input[2][i]=1;
		
}




cout<<"\ninput matrix is:\n";
for(int i=0;i<3;i++){
	for(int j=0;j<v;j++)
	
	{
	
		cout<<input[i][j]<<"\t";
		
	}
		
		
		cout<<"\n";
		
}
cin>>tx;
cin>>ty;

for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
if(i==j){
t[i][j]=1;
}
else{
t[i][j]=0;}
}
}
t[0][2]=tx;
t[1][2]=ty;

cout<<"\nt matrix is:\n";
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++)
	
	{
	
		cout<<t[i][j]<<"\t";
		
	}
		
		
		cout<<"\n";
		
}


for(int i=0;i<3;i++){
	for(int j=0;j<3;j++)
	
	{ 
		output[i][j]=0;
		
		for(int k=0;k<3;k++){
		
		output[i][j]+=t[i][k]*input[k][j];
		
		}
		
	}
		
}



//int p,r[3][3];
/*
cout<<"\n1.ABOUT X\n2.ABOUT Y\n3.Along x=y\n4.Z axis\n5.y=-x\n6.exit\n";
cin>>p;
switch(p){
case 1:{
glColor3f(0.0,1.0,0.0);


for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	
		if(i==j){
		r[i][j]=1;
		}
		else{
		r[i][j]=0;
		}
		
	}
	
}

r[1][1]=-1;

cout<<"\nReflection matrix is:\n";
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++)
	
	{
	
		cout<<r[i][j]<<"\t";
		
	}
		cout<<"\n";
		
		
		
}

for(int i=0;i<3;i++){
	for(int j=0;j<v;j++)
	
	{ 
		output[i][j]=0;
		
		for(int k=0;k<3;k++){
		
		output[i][j]+=r[i][k]*input[k][j];
		
		}
		
	}
		
}

break;}
case 2:{
glColor3f(0.0,1.0,0.0);


for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	
		if(i==j){
		r[i][j]=1;
		}
		else{
		r[i][j]=0;
		}
		
	}
	
}

r[0][0]=-1;

cout<<"\nReflection matrix is:\n";
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++)
	
	{
	
		cout<<r[i][j]<<"\t";
		
	}
		cout<<"\n";
		
		
		
}

for(int i=0;i<3;i++){
	for(int j=0;j<v;j++)
	
	{ 
		output[i][j]=0;
		
		for(int k=0;k<3;k++){
		
		output[i][j]+=r[i][k]*input[k][j];
		
		}
		
	}
		
}

break;
}

case 3:{
glColor3f(0.0,1.0,0.0);


for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	
		if(i==j){
		r[i][j]=1;
		}
		else{
		r[i][j]=0;
		}
		
	}
	
}

r[1][1]=0;
r[0][0]=0;
r[0][1]=1;
r[1][0]=1;

cout<<"\nReflection matrix is:\n";
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++)
	
	{
	
		cout<<r[i][j]<<"\t";
		
	}
		cout<<"\n";
		
		
		
}

for(int i=0;i<3;i++){
	for(int j=0;j<v;j++)
	
	{ 
		output[i][j]=0;
		
		for(int k=0;k<3;k++){
		
		output[i][j]+=r[i][k]*input[k][j];
		
		}
		
	}
		
}

break;
}

case 4:{


glColor3f(0.0,1.0,0.0);


for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	
		if(i==j){
		r[i][j]=1;
		}
		else{
		r[i][j]=0;
		}
		
	}
	
}

r[1][1]=-1;
r[0][0]=-1;

cout<<"\nReflection matrix is:\n";
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++)
	
	{
	
		cout<<r[i][j]<<"\t";
		
	}
		cout<<"\n";
		
		
		
}

for(int i=0;i<3;i++){
	for(int j=0;j<v;j++)
	
	{ 
		output[i][j]=0;
		
		for(int k=0;k<3;k++){
		
		output[i][j]+=r[i][k]*input[k][j];
		
		}
		
	}
		
}


break;
}




case 5:{
glColor3f(0.0,1.0,0.0);


for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	
		if(i==j){
		r[i][j]=1;
		}
		else{
		r[i][j]=0;
		}
		
	}
	
}

r[1][1]=0;
r[0][0]=0;
r[0][1]=-1;
r[1][0]=-1;

cout<<"\nReflection matrix is:\n";
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++)
	
	{
	
		cout<<r[i][j]<<"\t";
		
	}
		cout<<"\n";
		
		
		
}

for(int i=0;i<3;i++){
	for(int j=0;j<v;j++)
	
	{ 
		output[i][j]=0;
		
		for(int k=0;k<3;k++){
		
		output[i][j]+=r[i][k]*input[k][j];
		
		}
		
	}
		
}

break;
}


case 6:{cout<<"\nexiting";}}


/////multiplication:




cout<<"\nMULTIPLICATION:\n";

for(int i=0;i<v;i++){
	for(int j=0;j<3;j++)
	
	{
	
		cout<<output[i][j]<<"\t";
		
	}
		cout<<"\n";
		
		
		
}



*/




	glutInit(&argc,argv);//Initialize gult lib
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("firstProgram");
	glClearColor(0.0,0.0,0.0,0);
	glColor3f(1.0,0.0,0.0);
	gluOrtho2D(-320,320,-240,240);
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
	
}
