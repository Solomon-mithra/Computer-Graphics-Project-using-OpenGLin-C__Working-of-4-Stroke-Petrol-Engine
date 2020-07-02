
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

GLint x0,y00,xEnd,yEnd,dx,dy;
GLfloat  width=10.0;
GLint n=50;
GLint m=115, s= 50;
float x=100,y=100;
float radius = 0.5f, PI=3.14f;
float theta, t=0;
float cya=0,cxa=0,flag=0;
int ci,i=0,screenflag=0;
float csx=2; //crankshaft connecting rod animation variable
float csflag=0, csval=0; //rod connecting crankshaft flag and value for if condition
float inout=0, inout_flag=0, inoutval=0;
float p=0,py=0,pflag=0;


void spark()
{
    if(p>150 && p<400)
 {glColor3ub(255,140,0);
     glBegin(GL_LINE);
     {
         glVertex2f(648,748);
         glVertex2f(638,738);
     }
     glEnd();
 }
}
void petrol()
{
 p+=1;
 if(pflag==0)
 {
     glColor3ub(255,220,0);
 }

 if(p==400)
 {
     pflag=1;
 }
 if(pflag==1)
 {
     glColor3ub(255,140,0);
 }
 if(p==420)
 {
     pflag=2;
 }
 if(pflag==2)
 {
     glColor3ub(80,80,80);
 }
 if(p==1017)
 {
     pflag=0;
     p=-65;
 }

 glBegin(GL_POLYGON);
 {
     glVertex2f(550,510 );
     glVertex2f(750,510 );
     glVertex2f(750,650 );
     glVertex2f(550, 650);
 }
 glEnd();
}

void inout_animation()
{
    inoutval+=1;
//animation of input and output
if(inout_flag==0)
//intake & outlet
 { inout-=0.5;
     glPushMatrix();
     glTranslatef(0,inout,0);
     inlet();
     glPopMatrix();
     outlet();
 }
 if(inoutval==50)
    inout_flag=1;
if(inout_flag==1)
//intake & outlet
 {      inout=0;
     glPushMatrix();
     glTranslatef(0,-25,0);
     inlet();
     glPopMatrix();
     outlet();
 }
 if(inoutval==150)
    inout_flag=2;
 if(inout_flag==2)
 {
     inout+=0.5;
     glPushMatrix();
     glTranslatef(0,inout-25,0);
     inlet();
     glPopMatrix();
     outlet();
 }
 if(inoutval==200)
    inout_flag=3;
if(inout_flag==3)
{
    inlet();
    outlet();
    inout=0;
}

if(inoutval==600)
    inout_flag=4;
if(inout_flag==4)
//intake & outlet
 {
     inout-=0.5;
     glPushMatrix();
     glTranslatef(0,inout,0);
     outlet();
     glPopMatrix();
     inlet();
 }
 if(inoutval==650)
    inout_flag=5;
if(inout_flag==5)
//intake & outlet
 {      inout=0;
     glPushMatrix();
     glTranslatef(0,-25,0);
     outlet();
     glPopMatrix();
     inlet();
 }
 if(inoutval==900)
    inout_flag=6;
 if(inout_flag==6)
 {
     inout+=0.5;
     glPushMatrix();
     glTranslatef(0,inout-25,0);
     outlet();
     glPopMatrix();
     inlet();
 }
 if(inoutval==950)
    inout_flag=7;
if(inout_flag==7)
{
    inlet();
    outlet();
    inout=0;

}
if(inoutval==1070)
    inout_flag=8;
if(inout_flag==8)
{
     inout_flag=0;
    inoutval=-10;
}
}


void inlet()
{
    glBegin(GL_POLYGON);
    glVertex2f(570, 650);
    glVertex2f(570,640);
    glVertex2f(620, 640);
    glVertex2f(620, 650);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(590, 750);
    glVertex2f(590,640);
    glVertex2f(600, 640);
    glVertex2f(600, 750);
    glEnd();
}
void outlet()
{
     glBegin(GL_POLYGON);
    glVertex2f(570+m, 650);
    glVertex2f(570+m,640);
    glVertex2f(620+m, 640);
    glVertex2f(620+m, 650);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(590+m, 750);
    glVertex2f(590+m,640);
    glVertex2f(600+m, 640);
    glVertex2f(600+m, 750);
    glEnd();
}

void rod()
{
    csval+=1;
if(csval==300)
{
    csflag=1;
}
if(csval==570)
{
    csflag=2;
}
if(csval==840)
{
    csflag=1;
    csval=300;
}
if(csflag==0)
{
   csx += 0.5;
}
if(csflag==1)
{
    csx -= 0.5;
}
if(csflag==2)
{
    csx += 0.5;
}

    glBegin(GL_POLYGON);
glColor3f(0.6,0.6,0.6);
glVertex2f(542+csx, 250);
glColor3f(0.9,0.9,0.9);
glVertex2f(606+csx, 250);
glColor3f(0.9,0.9,0.9);
glVertex2f(672, 520);
glColor3f(0.6,0.6,0.6);
glVertex2f(628,520);
glEnd();


    //circle in the cylinder
   glColor3f( 0.0,  0.0,  0.0);
    glBegin(GL_POLYGON);

        for(int i=0;i<360;i++)
        {
            theta=i*3.142/180;
            glVertex2f(650+22*cos(theta),520+22*sin(theta));
        }
    glEnd();
    glColor3f( 0.5,  0.5,  0.5);
    glBegin(GL_POLYGON);

        for(int i=0;i<360;i++)
        {
            theta=i*3.142/180;
            glVertex2f(650+20*cos(theta),520+20*sin(theta));
        }
    glEnd();
}

void cylinder()
{

    glBegin(GL_POLYGON);
 glColor3f(1.0, 1.0, 1.0);
  glVertex3f(550, 450, 0.0);
  glColor3f( 0.40,  0.40,  0.40);
  glVertex3f(750, 450, 0.0);
  glColor3f(0.40,0.4,0.4);
glVertex3f(750, 600, 0.0);
  glColor3f(1.0, 1.0, 1.0);
 glVertex3f(550, 600, 0.0);
 glEnd();

 glBegin(GL_POLYGON);
 glColor3f(0, 0, 0);
  glVertex3f(550, 450, 0.0);
  glColor3f( 0.40,  0.40,  0.40);
  glVertex3f(750, 450, 0.0);
  glColor3f(0.40,0.4,0.4);
glVertex3f(750, 570, 0.0);
  glColor3f(0, 0, 0);
 glVertex3f(550, 570, 0.0);
 glEnd();

 glBegin(GL_POLYGON);
 glColor3f(1.0, 1.0, 1.0);
  glVertex3f(550, 450, 0.0);
  glColor3f( 0.40,  0.40,  0.40);
  glVertex3f(750, 450, 0.0);
  glColor3f(0.40,0.4,0.4);
glVertex3f(750, 560, 0.0);
  glColor3f(1.0, 1.0, 1.0);
 glVertex3f(550, 560, 0.0);
 glEnd();
}

void inner_circle_connect_crankshaft()
{
    glBegin(GL_POLYGON);
glColor3f( 0.0,  0.0,  0.0);
        for(int i=0;i<360;i++)
        {
            theta=i*3.142/180;
            glVertex2f(574+32*cos(theta),250+32*sin(theta));
        }
    glEnd();
     glBegin(GL_POLYGON);
glColor3f( 0.40,  0.40,  0.40);
        for(int i=0;i<360;i++)
        {
            theta=i*3.142/180;
            glVertex2f(574+30*cos(theta),250+30*sin(theta));
        }
    glEnd();
}

void in_out()
{
    glBegin(GL_POLYGON);
    {   glColor3ub(255,220,0);
        glVertex2f(570,650);
        glVertex2f(620,650);
        glVertex2f(620,700);
        glVertex2f(570,700);
    }
    glEnd();
    glBegin(GL_POLYGON);
    {   glColor3ub(255,220,0);
        glVertex2f(500,700);
        glVertex2f(620,700);
        glVertex2f(620,730);
        glVertex2f(500,730);
    }
    glEnd();

    if(p>720 && p<1010)
    {py+=0.25;
    glBegin(GL_POLYGON);
    {   glColor3ub(90,90,90);
        glVertex2f(570+m,650);
        glVertex2f(620+m,650);
        glVertex2f(620+m,650+py);
        glVertex2f(570+m,650+py);
    }
    glEnd();
    }
    else
    {
        py=0;
    }
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);

spark();
petrol();
glPushMatrix();
glTranslatef(0.0,cya,0.0);

 cylinder();
glPopMatrix();
if(flag==0)
{
cya-=0.5;
}
if(cya==-90)
{
    flag = 1;
}
if(cya==45)
{
    flag = 2;

}
if(flag==1)
{
    cya+=0.5;
}
if(flag==2)
{
    cya-=0.5;
}
in_out();




  glColor3ub( 255, 255, 255 );


    glBegin(GL_LINE_STRIP);
     glEnable(GL_LINE_WIDTH);

     glVertex2f(495+n, 350);
      glVertex2f(495+n, 650);
       glVertex2f(705+n, 650);
        glVertex2f(705+n, 350);

    glEnd();

     glBegin(GL_LINE_STRIP);
     glEnable(GL_LINE_WIDTH);

     glVertex2f(495+n, 350);
      glVertex2f(495, 300);
      glVertex2f(495, 100);
      glVertex2f(805, 100);
      glVertex2f(805,300);
        glVertex2f(705+n, 350);

    glEnd();
    //input pipe
    glBegin(GL_LINE_STRIP);
    glVertex2f(500,700);
    glVertex2f(570,700);
    glVertex2f(570, 650);
    glVertex2f(620, 650);
    glVertex2f(620,730);
    glVertex2f(500, 730);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(800,730);
    glVertex2f(570+m,730);
    glVertex2f(570+m, 650);
    glVertex2f(620+m, 650);
    glVertex2f(620+m,700);
    glVertex2f(800, 700);
    glEnd();





    //spark plug

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(630, 670);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(630, 650);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(680, 650);
    glColor3f(1,1,1);
    glVertex2f(680,670);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(640, 700);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(640, 670);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(670, 670);
    glColor3f(1,1,1);
    glVertex2f(670,700);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(640, 720);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(640, 700);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(670, 700);
    glColor3f(1,1,1);
    glVertex2f(670,720);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(650,650);
    glVertex2f(655,640);
    glVertex2f(660,650);
    glEnd();


inout_animation();


     //connecting rod
glPushMatrix();
glTranslatef(0.0,cya,0.0);
rod();
glPopMatrix();

//crankshaft
glBegin(GL_POLYGON);
glColor3f( 0.80,  0.80,  0.80);
        for(int i=0;i<360;i++)
        {
            theta=i*3.142/180;
            glVertex2f(650+120*cos(theta),250+120*sin(theta));
        }
    glEnd();

    glBegin(GL_POLYGON);
glColor3f( 0.40,  0.40,  0.40);
        for(int i=0;i<360;i++)
        {
            theta=i*3.142/180;
            glVertex2f(650+40*cos(theta),250+40*sin(theta));
        }
    glEnd();

    glBegin(GL_POLYGON);
glColor3f( 0.0,  0.0,  0.0);
        for(int i=0;i<360;i++)
        {
            theta=i*3.142/180;
            glVertex2f(650+20*cos(theta),250+20*sin(theta));
        }
    glEnd();




if(flag==0)
{
 t += 0.5;
}
if(flag==1)
{

 t += 0.67;
}
if(flag==2)
{
 t += 0.67;
}
//circles connecting the crankshaft
glPushMatrix();

	glTranslatef(650, 250, 0);
	glRotatef(t,0,0,1);
	glTranslatef(-650,-250,0);
	    inner_circle_connect_crankshaft();

	glPopMatrix();



glPushMatrix();



 glFlush();


}

void myInit()
{
	glClearColor(0.0,0.0,0.0,1.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1380,0,800);
}
void mytimer(int n)
{

glutPostRedisplay();
glutTimerFunc(7,mytimer,0);
}

void frontscreen(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.7,0,1);
glRasterPos2f(500,600);
char msg1[]= "COMPUTER GRAPHICS MINI PROJECT";
for(int i=0;i<strlen(msg1);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);
//glutSwapBuffers();

 glColor3f(0.5,0,1);
glRasterPos2f(690,500);
char msg2[]= "ON";
for(int i=0;i<strlen(msg2);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg2[i]);
//glutSwapBuffers();

 glColor3ub(255,220,0);
glRasterPos2f(600,400);
char msg3[]= "SIMULATION ON WORKING OF ENGINES";
for(int i=0;i<strlen(msg3);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg3[i]);
//glutSwapBuffers();

 glColor3ub(255,255,255);
glRasterPos2f(650,300);
char msg4[]= "Press key for";
for(int i=0;i<strlen(msg4);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg4[i]);
//glutSwapBuffers();

 glColor3ub(255,255,255);
glRasterPos2f(520,250);
char msg5[]= "( X )key - 4-STROKE PETROL ENGINE";
for(int i=0;i<strlen(msg5);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg5[i]);
//glutSwapBuffers();
glRasterPos2f(520,220);
char msg6[]= ".";
for(int i=0;i<strlen(msg5);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg6[i]);
    //
    glRasterPos2f(520,190);
char msg7[]= ".";
for(int i=0;i<strlen(msg5);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg7[i]);

glColor3ub(255,255,255);
glRasterPos2f(610,160);
char msg70[]= ".......................................";
for(int i=0;i<strlen(msg6);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg70[i]);
glutSwapBuffers();
glFlush();
}

void myKeyboardFunc( unsigned char key, int x,int y)
{
    if(key== 'x')
    {
        glutDisplayFunc(display);
    }
    glutPostRedisplay();
}



void main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1380,800);
	glutCreateWindow("4so17cs103-Line Draw");
	myInit();
	glutKeyboardFunc(myKeyboardFunc);
	glutDisplayFunc(frontscreen);

	glutTimerFunc(200,mytimer,0);

	glutMainLoop();
}
