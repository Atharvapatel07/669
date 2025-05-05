#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
int input[2][10];
double output[2][10];
int temp[2][10];
int v;
int m;
int xmin,ymin,xmax,ymax;

  void Bline(int xa,int ya,int xb,int yb)
  {
   int dx=xb-xa;
   int dy=yb-ya;
   int d,c,r,f;
   if(abs(dx)>abs(dy))
   { // gental with positive
   d=2*abs(dy)-abs(dx);
   if(dx>0)
   {
   c=xa;
   r=ya;
   f=xb;
   }
   else
   {
   c=xb;
   r=yb;
   f=xa;
   
   }
   while(f>=c)
   {
     if(d<0)
     {
     d=d+2*abs(dy);
     c=c+1;
     }
     else{
     d=d+2*abs(dy)-2*abs(dx);
      if(dx*dy>0)
      {
     
      r=r+1;
      }
      else
      {
      r=r-1;
      }
     c=c+1;
     }
    glVertex2d(c,r);
   }
   }
   else
   { //  sharp
   d=2*abs(dx)-abs(dy);
   if(dy>0)
   {
   c=xa;
   r=ya;
   f=yb;
   }
   else
   {
   c=xb;
   r=yb;
   f=ya;
   
   }
   while(f>=r)
   {
     if(d<0)
     {
     d=d+2*abs(dx);
     r=r+1;
     }
     else{
      d=d+2*abs(dx)-2*abs(dy);
      if(dx*dy>0)
      {
     
      c=c+1;
      }
      else
      {
      c=c-1;
      }
     r=r+1;
     }
   glVertex2d(c,r);
   }
   }
  }
   void rightclip(int xa,int ya,int xb,int yb)
   {
    int dx=xb-xa;
  int dy=yb-ya;
  float slope;
  slope=(float)dy/dx;
   if(xa<xmax && xb<xmax)
   {
   output[0][m]=xb;
  output[1][m]=yb; 
  m++;
   }
   if(xa>xmax & xb<xmax)
   {
   output[0][m]=xmax;
  output[1][m]=ya+slope*(xmax-xa);
  output[0][m+1]=xb;
  output[1][m+1]=yb; 
  m=m+2;
   }
   if(xa<xmax && xb>xmax)
   {
   output[0][m]=xmax;
  output[1][m]=ya+slope*(xmax-xa);
   m++;
   }
   
   }
   void bottomclip(int xa,int ya,int xb,int yb){
  float slope;
  int dx=xb-xa;
  int dy=yb-ya;
  if(xa==xb)
  {
    slope=0;
  }
  else{
     slope=(float)dy/dx;
  }
  if(ya>ymin && yb>ymin){
    output[0][m]=xb;
    output[1][m]=yb;
    m=m+1;
  }
  if(ya>ymin && yb<ymin){
    if(xa==xb){
  output[0][m]=xa;
  }
  else{
  output[0][m]=xa+(ymin-ya)/slope;
  }
    output[1][m]=ymin;
    m=m+1;
  }
  if(ya<ymin && yb>ymin){
  if(xa==xb){
  output[0][m]=xa;
  }
  else{
  output[0][m]=xa+(ymin-ya)/slope;
  }
    output[1][m]=ymin;
    output[0][m+1]=xb;
    output[1][m+1]=yb;
    m=m+2;
  }
  }
  void topclip(int xa,int ya,int xb,int yb){
  float slope;
  int dx=xb-xa;
  int dy=yb-ya;
  if(xa==xb)
  {
    slope=0;
  }
  else{
     slope=(float)dy/dx;
  }
  if(ya<ymax && yb<ymax){
    output[0][m]=xb;
    output[1][m]=yb;
    m=m+1;
  }
  if(ya<ymax && yb>ymax){
    if(xa==xb){
  output[0][m]=xa;
  }
  else{
  output[0][m]=xa+(ymax-ya)/slope;
  }
    output[1][m]=ymax;
    m=m+1;
  }
  if(ya>ymax && yb<ymax){
  if(xa==xb){
  output[0][m]=xa;
  }
  else{
  output[0][m]=xa+(ymax-ya)/slope;
  }
    output[1][m]=ymax;
    output[0][m+1]=xb;
    output[1][m+1]=yb;
    m=m+2;
  }
  }
  
  void leftclip(int xa,int ya,int xb,int yb)
  {
  int dx=xb-xa;
  int dy=yb-ya;
  float slope;
  slope=(float)dy/dx;
//  printf("%f\n",slope);
  if(xa>xmin && xb>xmin)
  {
  output[0][m]=xb;
  output[1][m]=yb; 
  m++;
  }
  if(xa<xmin && xb>xmin)
  {
  output[0][m]=xmin;
  output[1][m]=ya+slope*(xmin-xa);
  output[0][m+1]=xb;
  output[1][m+1]=yb; 
  m=m+2;
  }
  if(xa>xmin && xb<xmin)
  {
  output[0][m]=xmin;
  output[1][m]=ya+slope*(xmin-xa);
  m++;
  }
  
  }
  void polyclip()
  { int t;
  m=0;
  int i;
   for(i=0;i<v-1;i++){
        leftclip(input[0][i],input[1][i],input[0][i+1],input[1][i+1]);
        }
        leftclip(input[0][i],input[1][i],input[0][0],input[1][0]);
        
       
        for(int i=0;i<m;i++)
        {
         temp[0][i]=output[0][i];
          temp[1][i]=output[1][i];
         
        }
    t=0;
t=m;
m=0;
 
        
        for(i=0;i<t-1;i++){
        rightclip(temp[0][i],temp[1][i],temp[0][i+1],temp[1][i+1]);
        }
        rightclip(temp[0][i],temp[1][i],temp[0][0],temp[1][0]);
        
        for(int i=0;i<m;i++)
        {
         temp[0][i]=output[0][i];
          temp[1][i]=output[1][i];
         
        }
    t=0;
t=m;
m=0;
          for(i=0;i<t-1;i++){
      bottomclip(temp[0][i],temp[1][i],temp[0][i+1],temp[1][i+1]);
        }
        bottomclip(temp[0][i],temp[1][i],temp[0][0],temp[1][0]);  
        
        
        
         for(int i=0;i<m;i++)
        {
         temp[0][i]=output[0][i];
          temp[1][i]=output[1][i];
         
        }
    t=0;
t=m;
m=0;
          for(i=0;i<t-1;i++){
      topclip(temp[0][i],temp[1][i],temp[0][i+1],temp[1][i+1]);
        }
        topclip(temp[0][i],temp[1][i],temp[0][0],temp[1][0]);  
        
         for(i=0;i<m-1;i++){
        Bline(output[0][i],output[1][i],output[0][i+1],output[1][i+1]);
        }
        Bline(output[0][i],output[1][i],output[0][0],output[1][0]);
  
  }
  void Draw()
  {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  glColor3f(1,1,1);
  glVertex2d(100,100);
  Bline(xmin,ymin,xmax,ymin);
  
    Bline(xmax,ymin,xmax,ymax);
      Bline(xmax,ymax,xmin,ymax);
        Bline(xmin,ymax,xmin,ymin);
        int i;
        glColor3f(1,0,0);
        for(i=0;i<v-1;i++){
        Bline(input[0][i],input[1][i],input[0][i+1],input[1][i+1]);
        }
        Bline(input[0][i],input[1][i],input[0][0],input[1][0]);
        glColor3f(0,1,0);
        polyclip();
  glEnd();
  glFlush();
  }
  
  int main(int argc,char**argv)
  {
  v=4;
  xmin=100;
  ymin=100;
  xmax=300;
  ymax=300;
  input[0][0]=50;
  input[1][0]=200;
  input[0][1]=200;
  input[1][1]=50;
input[0][2]=350;
input[1][2]=200;
input[0][3]=200;
input[1][3]=350;


  
  
  
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("Cliping");
  gluOrtho2D(0,640,0,480);
  glutDisplayFunc(Draw);
  glutMainLoop();
  }
