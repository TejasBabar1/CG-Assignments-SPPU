#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
//#include <GL/glut.h>
#include <iostream>
#define w 600
#define h 600
using namespace std;

int x1,y1,x2,y2;

void myInit(void)
{
	glClearColor(0,0,0,0);
	glColor3f(1,0,0);

	glPointSize(3.0);

	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

void draw(int x,int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
	glEnd();
	glFlush();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i=-300;i<300;i++){
        draw(i,0);
        draw(0,i);
    }
}

void Simple(){

    int dx,dy,p0,x,y;
	double  m;

	int sx,sy;
	if((x2-x1)>0){
       sx=1;
    }
    else{
        sx=-1;
    }
    if((y2-y1)>0){
       sy=1;
    }
    else{
        sy=-1;
    }
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	m=dy/dx;



	p0=2*dy-dx;
	x=x1;
	y=y1;
	draw(x,y);
	if(m<1){
        for(int i=0;i<dx;i++){
            if(p0<0){
               x=x+sx;
               y=y;
               p0=p0+2*dy;
            }
            else{
               x=x+sx;
               y=y+sy;
               p0=p0+2*dy-2*dx;
            }
            draw(x,y);
        }
	}
	else{
        for(int i=0;i<dy;i++){
            if(p0<0){
               x=x;
               y=y+sy;
               p0=p0+2*dx;
            }
            else{
               x=x+sx;
               y=y+sy;
               p0=p0+2*dx-2*dy;
            }
            draw(x,y);
        }
	}

	glEnd();
	glFlush();
}

void Dotted(){

    int dx,dy,p0,x,y;
	double  m;

	int sx,sy;
	if((x2-x1)>0){
       sx=1;
    }
    else{
        sx=-1;
    }
    if((y2-y1)>0){
       sy=1;
    }
    else{
        sy=-1;
    }
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	m=dy/dx;



	p0=2*dy-dx;
	x=x1;
	y=y1;
	draw(x,y);
	if(m<1){
        for(int i=0;i<dx;i++){
            if(p0<0){
               x=x+sx;
               y=y;
               p0=p0+2*dy;
            }
            else{
               x=x+sx;
               y=y+sy;
               p0=p0+2*dy-2*dx;
            }
            draw(x,y);
        }
	}
	else{
        for(int i=0;i<dy;i++){
            if(p0<0){
               x=x;
               y=y+sy;
               p0=p0+2*dx;
            }
            else{
               x=x+sx;
               y=y+sy;
               p0=p0+2*dx-2*dy;
            }
            if(i%10<=2){
            draw(x,y);
            }
        }
	}

	glEnd();
	glFlush();
}

void Dashed(){

    int dx,dy,p0,x,y;
	double  m;

	int sx,sy;
	if((x2-x1)>0){
       sx=1;
    }
    else{
        sx=-1;
    }
    if((y2-y1)>0){
       sy=1;
    }
    else{
        sy=-1;
    }
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	m=dy/dx;



	p0=2*dy-dx;
	x=x1;
	y=y1;
	draw(x,y);
	if(m<1){
        for(int i=0;i<dx;i++){
            if(p0<0){
               x=x+sx;
               y=y;
               p0=p0+2*dy;
            }
            else{
               x=x+sx;
               y=y+sy;
               p0=p0+2*dy-2*dx;
            }
            draw(x,y);
        }
	}
	else{
        for(int i=0;i<dy;i++){
            if(p0<0){
               x=x;
               y=y+sy;
               p0=p0+2*dx;
            }
            else{
               x=x+sx;
               y=y+sy;
               p0=p0+2*dx-2*dy;
            }
            if(i%10>=4){
            draw(x,y);
            }
        }
	}

	glEnd();
	glFlush();
}

void menu(int c)
{
    if(c==1){
        Simple();
    }
    else if(c==2){
        Dotted();
    }
    else if(c==3){
        Dashed();
    }

    else if(c==4){

    exit(0);
    }
}


int main(int argc, char **argv)
{
    cout << "Enter x1 and y1: ";
	cin >> x1 >> y1;
	cout << "Enter x2 and y2: ";
	cin >> x2 >> y2;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w,h);
	glutInitWindowPosition(300,150);
	glutCreateWindow("Bresenham's Line");
	glutDisplayFunc(myDisplay);
	myInit();
	glutCreateMenu(menu);
	glutAddMenuEntry("1 Simple",1);
	glutAddMenuEntry("2 Dotted",2);
	glutAddMenuEntry("3 Dashed",3);
	glutAddMenuEntry("0 Exit",0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

