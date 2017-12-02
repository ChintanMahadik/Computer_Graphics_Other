

//fast motion lights(RAINBOW)//
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
#include<GL/glut.h>


void Circle(float k)
{


	glClearColor(0.5, 0.5, 0.5, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	// glTranslatef(0.1,0.0f,0.0f);
			    float p,x,y,r;
			    glBegin(GL_POLYGON);

			    r=40;
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


	float k,j,l,m,n,q,p,w;
	glBegin(GL_POLYGON);

	for(k=0;k<400;k+=10)
	{

	 glColor3f(1,0,0);
		Circle(k);

	}

	for(j=0;j<400;j+=10)
			{
				 glColor3f(0,1,0);
				Circle(j);
			}

	for(l=0;l<400;l+=10)
				{
					 glColor3f(0,0,1);
					Circle(l);
				}

	for(m=0;m<400;m+=10)
				{
					 glColor3f(1,1,0);
					Circle(m);
				}

	for(n=0;n<400;n+=10)
				{
					 glColor3f(1,0,1);
					Circle(n);
				}
	for(q=0;q<400;q+=10)
					{
						 glColor3f(0,1,1);
						Circle(q);
					}
	for(p=0;p<400;p+=10)
					{
						 glColor3f(1,1,1);
						Circle(p);
					}
	for(w=0;w<400;w+=10)
					{
						 glColor3f(1,0,1);
						Circle(w);
					}
	glEnd();
glFlush();



}

void timer(int v)
{

    glutPostRedisplay();


  glutTimerFunc(0.1,timer,v);



}



int main(int argc, char ** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(720,640);

    glutCreateWindow("CYCLE");

    gluOrtho2D(0,300,0,300);
    glutDisplayFunc(display);

   glutTimerFunc(0.1,timer,0);
    glutMainLoop();
    return 0;
}
