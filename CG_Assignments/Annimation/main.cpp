#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
#define W 100
#define H 50

float x_pos=-10;

void myInit(){
    glClearColor(1,1,1,0);
    gluOrtho2D(0,W,0,H);
    glColor3f(1,0,0);
    glPointSize(3);
}

void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0.3,1);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,20);
    glVertex2f(100,20);
    glVertex2f(100,0);
    glEnd();
    glFlush();

    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex2i(x_pos+20,5);
    glVertex2i(x_pos+30,5);
    glVertex2i(x_pos+35,10);
    glVertex2i(x_pos+15,10);
    glEnd();
    glFlush();

    glutSwapBuffers();



}

void Timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,Timer,0);
    x_pos+=0.30;
    if(x_pos>=90){
        x_pos=-10;
    }
}

int main(int i, char ** c){
 glutInit(&i,c);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Trans");
    myInit();
    glutDisplayFunc(Draw);
    glutTimerFunc(0,Timer,0);

    glutMainLoop();
    return 0;
}
