#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

//Program to create an empty Widdow
void myInit(void){
glClearColor(0,0,0,1);
glColor3f(1,0,0);

/*glPointSize(7.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,480.0);*/

}

/*void init(){
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Line C
 glutInitWindowSize(640,480);
 glutInitWindowPosition(1000,200);
 glutCreateWindow("Simple Window");
}*/

void disp()
{
 /*glClearColor(1.0,1.0,1.0,0.0);
 glColor3f(0.7f,0.7f,0.7f);*/
 glClear(GL_COLOR_BUFFER_BIT);
 glPointSize(10.0);
 glColor3f(50,50,0);
 glBegin(GL_POLYGON);
 glVertex2f(0,0);
 glVertex2f(0,1);
 glVertex2f(1,1);
 glVertex2f(1,0);

 glEnd();
 glFlush();
  glPointSize(10.0);
 glColor3f(1,1,1);
 glBegin(GL_POLYGON);
 glVertex2f(0.4,0);
 glVertex2f(0.6,0);
 glVertex2f(0.6,0.5);
 glVertex2f(0.4,0.5);
 glEnd();
 glFlush();

 glPointSize(10.0);
 glColor3f(0,1,0);
 glBegin(GL_POLYGON);
 glVertex2f(0,0.4);
 glVertex2f(0.2,0.4);
 glVertex2f(0.2,0.6);
 glVertex2f(0,0.6);
 glEnd();
 glFlush();


}

int main(int argc,char **argv)
{
 glutInit(&argc,argv); //Line A
 glutInitWindowPosition(150,150);
 glutInitWindowSize(600,600); //Line B
 glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
 glutCreateWindow("Laal Laal");
 myInit();
 //glutMainLoop();
    glutDisplayFunc(disp);
   // glutDisplayFunc(disp2);
    glutMainLoop();
 return 0;
}
