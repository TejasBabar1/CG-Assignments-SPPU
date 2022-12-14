#include <windows.h>
# include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
using namespace std ;
#define H 600
#define W 600

float xc,yc,r,x,y,d,Or;
void myInit(){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-W/2,W/2,-H/2,H/2);
    glColor3f(1,0,0);
}
void setpixel(float x,float y){
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void mydisplay(){
    glPointSize(3);
    for(int i=-300;i<=300;i++){
        setpixel(i,0);
        setpixel(0,i);
    }
}

void draw(float x,float y){
    setpixel(xc+x,yc+y);
    setpixel(xc-x,yc+y);
    setpixel(xc+x,yc-y);
    setpixel(xc-x,yc-y);

    setpixel(xc+y,yc+x);
    setpixel(xc-y,yc+x);
    setpixel(xc+y,yc-x);
    setpixel(xc-y,yc-x);

}
void simple(){

    x=0;
    y=r;
    d=3-2*r;

    while(x<=y){
        if(d<=0)
       {
            d = d + 4*x + 6;
        }
        else
        {
            d = d + 4*(x-y) + 10;
            y--;
        }
        x++;
      draw(x,y);
      }


}

void concentric(){
    r=0.7*r;
    simple();
}

void olympic(){
    r=Or;
    float xinc=xc;
    float yinc=yc;

    glColor3f(0,1,0);
    simple();

    xc=xc+2*r-10;
    glColor3f(0,0,1);
    simple();

    xc=xc+2*r-10;
    glColor3f(0,1,1);
    simple();

    xc=xinc+r;
    yc=yc-2*r+10;
    glColor3f(1,1,0);
    simple();

    xc=xc+2*r;
    glColor3f(1,0,1);
    simple();

}

void change(){
    r=Or;

    glColor3f(1,0,1);
    simple();
    glColor3f(1,2,1);
    simple();
    glColor3f(0.6,0,1);
    simple();
    glColor3f(1,8,0);
    simple();
    glColor3f(0,1,1);
    simple();
    glColor3f(1,0,4);
    simple();


}

void spiral1(float r1,float h,float k){
    x=0;
    y=r1;
    d=3-2*r1;

    while(x<=y){
        if(d<=0)
       {
            d = d + 4*x + 6;
        }
        else
        {
            d = d + 4*(x-y) + 10;
            y--;
        }
        x++;
        glColor3f(1,0,1);
        setpixel(x+h,y+k);
        setpixel(y+h,x+k);
        setpixel(-x+h,y+k);
        setpixel(-y+h,x+k);
}
}
void spiral2(float r1,float h,float k){
    x=0;
    y=r1;
    d=3-2*r;

    while(x<=y){
        if(d<=0)
       {
            d = d + 4*x + 6;
        }
        else
        {
            d = d + 4*(x-y) + 10;
            y--;
        }
        x++;
        glColor3f(1,1,0);

        setpixel(-x+h,-y+k);
        setpixel(-y+h,-x+k);
        setpixel(x+h,-y+k);
        setpixel(y+h,-x+k);
}
}
void menu(int c){
    switch(c){
    case 1:
        simple();
        break;

    case 2:
        concentric();
        break;
    case 3:
        olympic();
        break;
    case 4:
        change();
        break;
    case 5:
        for(int i=1;i<=10;i++){
            if(i%2==0){
                spiral1(i*20,20,0);
            }
            else{
                spiral2(i*20,40,0);
            }
        }
        break;

    case 6:
        exit(0);
        break;
    }

}

int main(int argc,char ** argv){
    cout << "Enter XC: ";
	cin >> xc;
	cout << "Enter YC ";
	cin >>yc;
	cout<<"Enter R ";
	cin>>r;

	Or=r;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(W,H);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Circle");
    myInit();
    glutDisplayFunc(mydisplay);

    glutCreateMenu(menu);
    glutAddMenuEntry("Simple",1);
    glutAddMenuEntry("Concentric",2);
    glutAddMenuEntry("Olympic",3);
    glutAddMenuEntry("Change",4);
    glutAddMenuEntry("Spiral",5);
    glutAddMenuEntry("Exit",6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;

}
