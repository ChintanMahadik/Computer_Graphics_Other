/*
 * dda.c
 *
 *  Created on: Mar 25, 2014
 *      Author: chintan
 */


/*
 * chintu.c
 *
 *  Created on: Mar 22, 2014
 *      Author: chintan
 */
//this is my project!
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>


	float i=0;
float k;


void translate(int x1,int x2)
{

	// glMatrixMode(GL_MODELVIEW);
	  //  glPushMatrix()
        glTranslatef(i,0,0);
	    glBegin(GL_LINES);
	    glVertex2f(0,x1);
	    glVertex2f(0,x2);

		glEnd();


		// glPopMatrix();
				glFlush();



	//glutSwapBuffers();

}
void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);

//while(i<300)
//{
glColor3f(1,0.2,0);
translate(300,200);
//}

while(i<300)
{
glColor3f(1,1,1);
translate(200,100);
}
while(i<300)
{
glColor3f(0,1,0);
translate(200,100);
}

}

void timer(int v)
{
i+=0.1;
    glutPostRedisplay();

  glutTimerFunc(100,timer,v);



}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    gluOrtho2D(0,300,0,300);
    glutDisplayFunc(display);
    glutTimerFunc(100,timer,0);
 //glutMouseFunc(mouse);
    //glutSpecialFunc(special);

    glutMainLoop();
    return 0;
}
