#include<windows.h>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.141516

using namespace std;

bool land=true;
bool fire=true;

int i;
int triangle1=40;

GLfloat tp1=2.0f*PI;

GLfloat position = 0.0f;
GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.0f;
GLfloat speed1 = 0.018f;
GLfloat speed2 = 0.03f;
GLfloat speed3 = 0.0f;

GLfloat s=0.5;


void update2(int value2) {   ///landing

    if(land==false){
    if(position2 <-1.3)
        position2 = -1.3f;

    position2 -= speed2;}

glutPostRedisplay();
glutTimerFunc(100, update2, 0);
}


void display() {

   if(land==false)
   {
       glClearColor(0.0f,0.0f,0.0f,1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glPushMatrix();


   {
       glPushMatrix();

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(40, 122, 184);

   for(i=0; i<=triangle1;i++)

   glEnd();

   glPopMatrix();
   }

	glPopMatrix();



///************************rocket landing on moon

       glPushMatrix();

       glTranslatef(0.0f,position2, 0.0f);
   glTranslated(0.3,1.0,0.0);
   glScalef(0.4f,0.4f,0.0f);


   glBegin(GL_TRIANGLES); ///HEAD
   glColor3ub(238,28,37);

   glVertex2f(0.24f,0.6f);
   glVertex2f(0.14f, 0.42f);
   glVertex2f(0.34f, 0.42f);
   glEnd();


   glBegin(GL_POLYGON);///HEAD  Lower Body
   glColor3ub(230,230,230);
   glVertex2f(0.14f, 0.42f);
   glVertex2f(0.14f, 0.08f);
   glVertex2f(0.15f, 0.06f);
   glVertex2f(0.33f, 0.06f);
   glVertex2f(0.34f, 0.08f);
   glVertex2f(0.34f, 0.42f);
   glEnd();

   GLfloat pbg=0.24f; GLfloat qbg=0.25f; GLfloat rbg=-0.077f;///glass background

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(130,130,130);
   glVertex2f(pbg,qbg);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pbg+(rbg*cos(i*tp1/triangle1)), qbg+(rbg*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   GLfloat pg=0.24f; GLfloat qg=0.25f; GLfloat rg=-0.07f; ///glass

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(35,172,196);
   glVertex2f(pg,qg);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pg+(rg*cos(i*tp1/triangle1)), qg+(rg*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   glBegin(GL_QUADS); ///HEAD Lower Body shadow
   glColor3ub(187,188,192);
   glVertex2f(0.33f, 0.42f);
   glVertex2f(0.33f, 0.06f);
   glVertex2f(0.34f, 0.08f);
   glVertex2f(0.34f, 0.42f);
   glEnd();

   glBegin(GL_QUADS); ///HEAD Lower Body QUAD
   glColor3ub(187,188,192);
   glVertex2f(0.15f, 0.06f);
   glVertex2f(0.15f, 0.01f);
   glVertex2f(0.33f, 0.01f);
   glVertex2f(0.33f, 0.06f);
   glEnd();

   glBegin(GL_POLYGON); /// UNDER BODY QUAD
   glColor3ub(230,230,230);
   glVertex2f(0.15f, 0.01f);
   glVertex2f(0.14f, -0.01f);
   glVertex2f(0.14f, -0.74f);
   glVertex2f(0.34f, -0.74f);
   glVertex2f(0.34f, -0.01f);
   glVertex2f(0.33f, 0.01f);
   glEnd();

   glBegin(GL_QUADS); ///UNDER BODY QUAD shadow
   glColor3ub(187,188,192);
   glVertex2f(0.33f, -0.74f);
   glVertex2f(0.34f, -0.74f);
   glVertex2f(0.34f, -0.01f);
   glVertex2f(0.33f, 0.01f);
   glEnd();

   glBegin(GL_POLYGON); /// LEFT WING
   glColor3ub(230,230,230);


   glVertex2f(0.1f, -0.25f);
   glVertex2f(0.05f, -0.25f);
   glVertex2f(0.01f, -0.74f);
   glVertex2f(0.14f, -0.74f);
   glVertex2f(0.14f, -0.23f);


   glEnd();

   glBegin(GL_QUADS); ///lEFT WING shadow
   glColor3ub(187,188,192);
   glVertex2f(0.1f, -0.25f);
   glVertex2f(0.06f, -0.74f);
   glVertex2f(0.14f, -0.74f);
   glVertex2f(0.14f, -0.23f);
   glEnd();


   glBegin(GL_POLYGON);  ///RIGHT WING
   glColor3ub(230,230,230);


   glVertex2f(0.34f, -0.74f);
   glVertex2f(0.47f, -0.74f);
   glVertex2f(0.43f, -0.25f);
   glVertex2f(0.38f, -0.25f);
   glVertex2f(0.34f, -0.23f);

   glEnd();

   glBegin(GL_QUADS); ///RIGHT WING shadow
   glColor3ub(187,188,192);
   glVertex2f(0.38f, -0.25f);
   glVertex2f(0.43f, -0.74f);
   glVertex2f(0.47f, -0.74f);
   glVertex2f(0.43f, -0.25f);
   glEnd();

   glBegin(GL_QUADS); ///LEFT fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.05f, -0.74f);
   glVertex2f(0.04f, -0.79f);
   glVertex2f(0.11f, -0.79f);
   glVertex2f(0.1f, -0.74f);
   glEnd();

   glBegin(GL_QUADS); ///CENTER fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.215f, -0.74f);
   glVertex2f(0.205f, -0.79f);
   glVertex2f(0.275f, -0.79f);
   glVertex2f(0.265f, -0.74f);
   glEnd();

   glBegin(GL_QUADS); ///RIGHT fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.38f, -0.74f);
   glVertex2f(0.37f, -0.79f);
   glVertex2f(0.44f, -0.79f);
   glVertex2f(0.43f, -0.74f);
   glEnd();


if(fire)
{
   glBegin(GL_TRIANGLES);///left fire
   glColor3ub(240,192,11);
   glVertex2f(0.04f, -0.79f);
   glVertex2f(0.075f, -0.95f);
   glVertex2f(0.11f, -0.79f);
   glEnd();

   glBegin(GL_TRIANGLES);///center fire
   glColor3ub(240,192,11);
   glVertex2f(0.205f, -0.79f);
   glVertex2f(0.24f, -0.95f);
   glVertex2f(0.275f, -0.79f);
   glEnd();

   glBegin(GL_TRIANGLES);///right fire
   glColor3ub(240,192,11);
   glVertex2f(0.37f, -0.79f);
   glVertex2f(0.405f, -0.95f);
   glVertex2f(0.44f, -0.79f);
   glEnd();
}
glPopMatrix();

}

glFlush();
}

void handleMouse(int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON)
{
    speed1 += 0.1f;
}
if (button == GLUT_RIGHT_BUTTON)
{speed1 -= 0.1f;   }
glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y)
{
switch (key) {


case 'l':
    land=false;
    break;


glutPostRedisplay();
}
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(720,480);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Translation Animation");
   glutDisplayFunc(display);


   glutTimerFunc(100, update2, 0);


   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutMainLoop();
   return 0;
}
