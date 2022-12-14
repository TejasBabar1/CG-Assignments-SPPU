#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#define h 480
#define w 640
#include<math.h>

#include <iostream>
using namespace std;

int a1,b2,c1,d2;
void initGL() {

glClearColor(1.0f, 1.0f, 1.0f, 1.0f);           //  second window
glLineWidth(3.0);
glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2, w/2, -h/2, h/2);
}

void setPixel(int x, int y){
glColor3f(0,0,1);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();

}
void display(){
glClear(GL_COLOR_BUFFER_BIT);

   for (int i = -w; i < w; i++){
setPixel(i, 0);
setPixel(0, i);
    }
    glFlush();
}

 void simpleLine(){

    int dx= c1-a1;
int dy= d2-b2;
int length=dx;
if(abs(dy)>abs(dx))
{
length=dy;
}

    // first point
float x1=1.0f*a1;
float y1=1.0f*b2;

float x=(1.0f*dx)/length;
float y=(1.0f*dy)/length;

        glBegin(GL_POINTS);
   glColor3f(0.3,0.9,0.3);
   glVertex2f(x1,y1);
   int i=1;
   while(i<=length) {
    x1+=x;
    y1+=y;
    glVertex2f(round(x1),round(y1));
    i++;
}
   glEnd();
  glFlush();
 }

  void  dottedLine(){

    int dx= c1-a1;
int dy= d2-b2;
int length=dx;
if(abs(dy)>abs(dx))
{
length=dy;
}

// first point
float x1=1.0f*a1;
float y1=1.0f*b2;

float x=(1.0f*dx)/length;
float y=(1.0f*dy)/length;

        glBegin(GL_POINTS);
   glColor3f(0.5,0.5,0.3);
   glVertex2f(x1,y1);
   int i=1;
   while(i<=length) {
    x1+=x;
    y1+=y;
    if(i%4==0){
    glVertex2f(round(x1),round(y1));
   }
    i++;
}
   glEnd();
  glFlush();
 }

    void dashedLine(){

    int dx= c1-a1;
int dy= d2-b2;
int length=dx;
if(abs(dy)>abs(dx))
{
length=dy;
}

// first point
float x1=1.0f*a1;
float y1=1.0f*b2;

float x=(1.0f*dx)/length;
float y=(1.0f*dy)/length;

        glBegin(GL_POINTS);
   glColor3f(0,0,1);
   glVertex2f(x1,y1);
   int i=1;
   while(i<=length) {
    x1+=x;
    y1+=y;
    if(i%10>=4){
    glVertex2f(round(x1),round(y1));
   }
    i++;
}
   glEnd();
  glFlush();
 }

 void menu(int choice){

        if(choice==1){
                simpleLine();
        }
        else if(choice==2){
                dashedLine();
        }
        else if(choice==3){
                dottedLine();
        }
        else if(choice==4){
                exit(0);
        }
}

int main(int argc, char** argv) {
    cout<<"For First Point "<<endl;
cout<<"Enter x1 :";cin>>a1;
cout<<"Enter y1 :";cin>>b2;
cout<<endl;

cout<<"For Second Point "<<endl;
cout<<"Enter x2 :";cin>>c1;
cout<<"Enter y2 :";cin>>d2;
cout<<endl;

glutInit(&argc, argv);
glutInitWindowPosition(300,300);
glutCreateWindow(" DDA with Mouse Interfacing ");
glutInitWindowSize(640, 480);
glutDisplayFunc(display);
    glutCreateMenu(menu);
    glutAddMenuEntry(" Simple Line ",1);
    glutAddMenuEntry(" Dotted Line ",3);
    glutAddMenuEntry(" Dashed Line ",2);
    glutAddMenuEntry(" Exit ",4);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    initGL();
glutMainLoop();

return 0;
}

