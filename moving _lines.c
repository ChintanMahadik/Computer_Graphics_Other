/*
 * tp.c
 *
 *  Created on: Mar 28, 2014
 *      Author: chintan
 */

//line lights//
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
#include<GL/glut.h>


void Circle(float k)
{


	glTranslatef(0.02,0.02,0);

			    float p,x,y,r;
			    glBegin(GL_POLYGON);

			    r=20;
 		        x=0;
			    y=r;

			    p=1.25-r;



 do
 {


			    do
			    {



			    	printf("\n x,y is %f %f",x,y);

			    	glVertex2f(k+x,k+y);
			    	glVertex2f(k+y,k+x);
			    	glVertex2f(k+y,k-x);
			    	glVertex2f(k-y,k+x);
			    	glVertex2f(k-x,k-y);
			    	glVertex2f(k-y,k-x);
			    	glVertex2f(k+x,k-y);
			    	glVertex2f(k-x,k+y);


			    	if(p<0)
			    	{
			    		x=x+1;

			    		p=p+2*x+1;

			    	}
			    	else
			    	{
			    		x=x+1;
			    		y=y-1;
			    		p=p+2*x-2*y+1;

			    	}



			    }
			    while(x<y);




    k++;


}while(k<0);

			    glEnd();
			    glFlush();



}

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
			    glClear(GL_COLOR_BUFFER_BIT);

		float k,j,l,m,n;

	glBegin(GL_POLYGON);
	for(k=0;k<500;k+=0.2)
	{

	 glColor3f(1,1,1);
		Circle(k);

	}

	for(j=0;j<250;j+=0.2)
			{
				 glColor3f(0,0,1);
				Circle(j);
			}

	for(l=0;l<200;l+=0.2)
				{
					 glColor3f(1,1,0);
					Circle(l);
				}

	for(m=0;m<100;m+=0.2)
				{
					 glColor3f(0,1,0);
					Circle(m);
				}

	for(n=0;n<50;n+=0.2)
				{
					 glColor3f(1,0,0);
					Circle(n);
				}
glEnd();
glFlush();



}

void timer(int v)
{

    glutPostRedisplay();


  glutTimerFunc(1000,timer,v);



}



int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(720,640);
   // glutInitWindowPosition(100,100);
    glutCreateWindow("CYCLE");

    gluOrtho2D(0,300,0,300);
    glutDisplayFunc(display);

   glutTimerFunc(1000,timer,0);
    glutMainLoop();
    return 0;
}
