#include <windows.h>
#include<GL/glut.h>
#include<math.h>

#include<iostream>
using namespace std;

int w=640,h=480;
int x1,y2,choice;

  float OldCol[3] = {1.0,1.0,1.0};
  float fillCol[3] = {0.5,0.5,0.0};
  float borderCol[3] = {0.0,0.0,0.0};

  void setPixel(int x, int y, float f[3])
  {
       glBegin(GL_POINTS);
           glColor3f(f[0],f[1],f[2]);
            glVertex2i(x,y);
       glEnd();
       glFlush();
  }

void getPixel(int x,int y,float *color)
{
 glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}


void drawPolygon(int x1, int y1, int x2, int y2)
  {
       glColor3f(0.0,0.0,0.0);
       glBegin(GL_LINES);
            glVertex2i(x1, y1);
            glVertex2i(x1, y2);
       glEnd();
       glBegin(GL_LINES);
            glVertex2i(x2, y1);
            glVertex2i(x2, y2);
       glEnd();
       glBegin(GL_LINES);
            glVertex2i(x1, y1);
            glVertex2i(x2, y1);
       glEnd();
       glBegin(GL_LINES);
            glVertex2i(x1, y2);
            glVertex2i(x2, y2);
       glEnd();
       glFlush();
  }

void display()
{
 glClearColor(1.0,1.0,1.0,0.0);
 glColor3f(0.0,0.0,0.0);

 gluOrtho2D(0,640,0,480);
 glClear(GL_COLOR_BUFFER_BIT);
 drawPolygon(50,100,150,200);
 drawPolygon(150,200,250,300);



}

 //flood fill algo

void floodfill(int x,int y,float oldcolor[3],float newcolor[3])
       {
            float color[3];
            getPixel(x,y,color);
            if(color[0]==oldcolor[0] && (color[1])==oldcolor[1] && (color[2])==oldcolor[2])
            {
                     setPixel(x,y,newcolor);
                     floodfill(x+1,y,oldcolor,newcolor);
                     floodfill(x-1,y,oldcolor,newcolor);
                  floodfill(x,y+1,oldcolor,newcolor);
                  floodfill(x,y-1,oldcolor,newcolor);
             }
       }



  void boundaryFill(int x,int y,float borderColor[3],float fillColor[3])
  {
       float interiorColor[3];
       getPixel(x,y,interiorColor);
       if((interiorColor[0]!=borderColor[0] && (interiorColor[1])!=borderColor[1] && (interiorColor[2])!=borderColor[2])
           && (interiorColor[0]!=fillColor[0] && (interiorColor[1])!=fillColor[1] && (interiorColor[2])!=fillColor[2]))
       {
            setPixel(x,y,fillColor);
            boundaryFill(x+1,y,fillColor,borderColor);
            boundaryFill(x-1,y,fillColor,borderColor);
            boundaryFill(x,y+1,fillColor,borderColor);
            boundaryFill(x,y-1,fillColor,borderColor);
       }
  }
void mouse(int btn,int state,int x,int y)
{
 if((btn==GLUT_LEFT_BUTTON)&&(state==GLUT_DOWN))
 {
 x1=x;
 y2=480-y;
 if(choice==1)
    floodfill(x1,y2,OldCol,fillCol);
 else if(choice==2)
    boundaryFill(x1,y2,borderCol,fillCol);
}

}
void menu(int item)
{
 if(item==1) //Flood fill
 {
 floodfill(80,130,OldCol,fillCol);
 //drawPolygon(50,100,150,200);
 choice=1;

 }
 else if(item==2) //Boundry fill
 {
boundaryFill(180,210,borderCol,fillCol);
//drawPolygon(150,200,250,300);
 choice=2;

 }
 else if(item==3)exit(0);
}

int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(w,h);
  glutCreateWindow("Boundary and Flood Fill Algorithm");
  glutCreateMenu(menu);
  glutAddMenuEntry("Flood Fill",1);
  glutAddMenuEntry("Boundary Fill",2);
  glutAddMenuEntry("Exit",3);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
 glutDisplayFunc(display);
 //glutMouseFunc(mouse);
 glutMainLoop();
 return 0;
}
