#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#define w 640 // Width of Screen
#define h 480 // Height of Screen
using namespace std;
int x[3][3] = {{10,100,45},{10,10,50},{1,1,1}}; // Object Matrix
int c[3][3]; // Result of multiplication matrix
void myInit(void)
{
glClearColor(0.6,0.6,0.6,0.0);
glColor3f(0.0,1.0,0.0);
//glLineWidth(5.0);
glPointSize(5.0);
//glMatrixMode(GL_PROJECTION);
//glLoadIdentity();
gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

void setpixel(void){ // Function to plot axis
for(int i=-w;i<=w;i++){
glBegin(GL_POINTS);
glVertex2i(i,0);
glVertex2i(0,i);
glEnd();
}
glFlush();
}
void myDisplay(void)
{
setpixel();
glFlush();
}
void drawPixel(int x,int y){ // Pixel Plotting Function
glPointSize(5);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}

void myObject(void){ // Drawing Object
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.2,0.0);
setpixel();
glBegin(GL_POLYGON);
glVertex2i(10,10);
glVertex2i(100,10);
glVertex2i(45,50);
glEnd();
glFlush();
}
void multMatrix(int a[][3],int b[][3]){ // Perform multiplication of two matrices
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
c[i][j]=0;
for(int k=0;k<3;k++){
c[i][j] += a[i][k]*b[k][j];
}
}
}
}
void draw(){ // Draw function using result matrix
glColor3f(0.0,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2i(c[0][0],c[1][0]);
glVertex2i(c[0][1],c[1][1]);
glVertex2i(c[0][2],c[1][2]);
glEnd();
glFlush();
}
void translate(){ // Translate Object
int y[3][3] = {{1,0,50},{0,1,50},{0,0,1}};
int z[3][3];
multMatrix(y,x);
draw();
}
void scaleMyObject(){ // Scaling function
int y[3][3] = {{2,0,0},{0,2,0},{0,0,1}};
multMatrix(y,x);
glColor3f(0.0,0.2,0.0);

glBegin(GL_POLYGON);
glVertex2i(10,10);
glVertex2i(c[0][1],c[1][1]);
glVertex2i(c[0][2],c[1][2]);
glEnd();
glFlush();
}
void rotateObject(){ // Rotation of Object
int y[3][3] = {{0,-1,0},{1,0,0},{0,0,1}};
multMatrix(y,x);
draw();
}
void rotateAboutPivot(){ // Rotation about Pivot Point
int y[3][3] = {{1,0,-50},{0,1,-50},{0,0,1}};
int z[3][3] = {{0,-1,0},{1,0,0},{0,0,1}};
int a[3][3],b[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
a[i][j]=0;
for(int k=0;k<3;k++){
a[i][j] += y[i][k]*z[k][j];
}
}
}
int p[3][3] = {{1,0,50},{0,1,50},{0,0,1}};
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
b[i][j]=0;
for(int k=0;k<3;k++){
b[i][j] += a[i][k]*p[k][j];
}
}
}
multMatrix(b,x);
draw();
}
void reflection(){ // Reflection about X-axis
int y[3][3] = {{1,0,0},{0,-1,0},{0,0,1}};
multMatrix(y,x);
draw();
}

void reflectionAboutY(){ // Reflection about X-axis
int y[3][3] = {{-1,0,0},{0,1,0},{0,0,1}};
multMatrix(y,x);
draw();
}
void reflectionAboutOrigin(){
int y[3][3] = {{-1,0,0},{0,-1,0},{0,0,1}};
multMatrix(y,x);
draw();
}
void reflectionAboutXY(){
int y[3][3] = {{0,1,0},{1,0,0},{0,0,1}};
multMatrix(y,x);
draw();
}
void shearAboutX(){
int y[3][3] = {{1,2,0},{0,1,0},{0,0,1}};
multMatrix(y,x);
glColor3f(0.0,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2i(10,10);
glVertex2i(c[0][1],c[1][1]);
glVertex2i(c[0][2],c[1][2]);
glEnd();
glFlush();
}
void shearAboutY(){
int y[3][3] = {{1,0,0},{2,1,0},{0,0,1}};
multMatrix(y,x);
glColor3f(0.0,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2i(10,10);
glVertex2i(c[0][1],c[1][1]);
glVertex2i(c[0][2],c[1][2]);
glEnd();
glFlush();
}

void createMenu(void){
glutAddMenuEntry("1.Draw Object",1);//
glutAddMenuEntry("2.Translate Object",2);//
glutAddMenuEntry("3.Scale Object",3);//
glutAddMenuEntry("4.Rotate about origin",4);//
glutAddMenuEntry("5.Rotate about Pivot point: ",5);
glutAddMenuEntry("6.Reflection about X-axis",6);//
glutAddMenuEntry("7.Reflection about Y-axis",7);//
glutAddMenuEntry("8.Reflection about Origin",8);//
glutAddMenuEntry("9.Reflection about X-Y line",9);
glutAddMenuEntry("10.Shearing about X",10);//
glutAddMenuEntry("11.Shearing about Y",11);//
glutAddMenuEntry("13.Exit",0);
glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void Menu(int choice){
if(choice==1){
myObject();
}
else if(choice==2){
translate();
}
else if(choice==3){
scaleMyObject();
}
else if(choice==4){
rotateObject();
}
else if(choice==5){
rotateAboutPivot();
}
else if(choice==6){
reflection();
}
else if(choice==7){
reflectionAboutY();
}
else if(choice==8){
reflectionAboutOrigin();
}
else if(choice==9){
reflectionAboutXY();
}

else if(choice==10){
shearAboutX();
}
else if(choice==11){
shearAboutY();
}
else if(choice==13){
exit(0);
}
}
int main(int argc, char **argv) // main function
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(300,150);
glutCreateWindow("Transformation");
glutDisplayFunc(myDisplay);
myInit();
glutCreateMenu(Menu);
createMenu();
glutMainLoop();
return 0;
}
