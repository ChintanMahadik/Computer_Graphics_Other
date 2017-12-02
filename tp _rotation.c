/*
 * tp _rotation.c
 *
 *  Created on: Apr 16, 2014
 *      Author: chintan
 */
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.142


float i=0,j;
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)//direct circle
{

	int i;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glFlush();
}


void display()
		{

	 	 	 	 glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
		 	    glClear(GL_COLOR_BUFFER_BIT);
		 	   glColor3f(1,1,1);

    ////////tp thing////////////////////
	 						  	 glMatrixMode(GL_MODELVIEW);

	 						  	 glPushMatrix();
	 						  	 glRotatef(i,0,0,0);
	 						  //	glTranslatef(i,j,0);
	 						    glBegin(GL_POLYGON);

	 						   drawCircle(100,40,20);
	 						   glEnd();
	 						  glPopMatrix();
	 						  	    ////////////end///////////

	 						  glFlush();
	 						 glutSwapBuffers();

		}


void timer(int v)
{
	i+=1;
	j+=1;
	  glutPostRedisplay();

	  glutTimerFunc(10,timer,v);

}
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
   gluOrtho2D(-300,300,-300,300);
    glutDisplayFunc(display);
   glutTimerFunc(10,timer,0);
   // glutMouseFunc(mouse);
   // glutSpecialFunc(Special);

    glutMainLoop();
    return 0;
}
