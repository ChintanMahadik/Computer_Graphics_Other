/*
 * 2d_transform.c
 *
 *  Created on: May 2, 2014
 *      Author: chintan
 */


/*
 * 2d_transform.c
 *
 *  Created on: 2 May 2014
 *      Author: chintan-s-mahadik
 */
#include<GL/glut.h>
#include<GL/glu.h>
#include<Gl/gl.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void reflection()//reflection about x
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glColor3f(0,0,1);
			int x1,y1,x2,y2,x[3][2],i,j,k;
			float xi[3][2],t[3][3];
			glBegin(GL_LINES);
		    x1=0;
		    y1=0;
		    x2=100;
		    y2=100;




			glVertex2f(x1,y1);
			glVertex2f(x2,y2);


		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(i==j)
					t[i][j]=1;
				else
					t[i][j]=0;
			}
		}

		//t[0][0]=-1;
		t[1][1]=-1;
		x[0][0]=x1;
		x[0][1]=x2;
		x[1][0]=y1;
		x[1][1]=y2;
		x[2][0]=1;
		x[2][1]=1;


		for(i=0;i<3;i++)
		{
			for(j=0;j<2;j++)
			{
				xi[i][j]=0;
				for(k=0;k<3;k++)
				{
					xi[i][j]+=t[i][k]*x[k][j];

				}

			}
		}


		x1=xi[0][0];
		x2=xi[0][1];
		y1=xi[1][0];
		y2=xi[1][1];


		glColor3f(1,0,0);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);

		glEnd();
		glFlush();
}
void scale()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(0,0,1);
		int x1,y1,x2,y2,sx,sy,x[3][2],i,j,k;
		float xi[3][2],t[3][3];
		glBegin(GL_LINES);
	    x1=0;
	    y1=0;
	    x2=100;
	    y2=100;

		sx=2;
		sy=2;


		glVertex2f(x1,y1);
		glVertex2f(x2,y2);


	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				t[i][j]=1;
			else
				t[i][j]=0;
		}
	}

	t[0][0]=sx;
	t[1][1]=sy;
	x[0][0]=x1;
	x[0][1]=x2;
	x[1][0]=y1;
	x[1][1]=y2;
	x[2][0]=1;
	x[2][1]=1;


	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			xi[i][j]=0;
			for(k=0;k<3;k++)
			{
				xi[i][j]+=t[i][k]*x[k][j];

			}

		}
	}


	x1=xi[0][0];
	x2=xi[0][1];
	y1=xi[1][0];
	y2=xi[1][1];


	glColor3f(1,0,0);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);

	glEnd();
	glFlush();

}
void rotate()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(0,0,1);
		int x1,y1,x2,y2,x[3][2],i,j,k;
		float xi[3][2],t[3][3];
		double angle;
		glBegin(GL_LINES);
	    x1=0;
	    y1=0;
	    x2=100;
	    y2=100;
       angle=1.57;

		glVertex2f(x1,y1);
		glVertex2f(x2,y2);


	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				t[i][j]=1;
			else
				t[i][j]=0;
		}
	}

	t[0][0]=cos(angle);
	t[0][1]=-sin(angle);
	t[1][0]=sin(angle);
	t[1][1]=cos(angle);
	x[0][0]=x1;
	x[0][1]=x2;
	x[1][0]=y1;
	x[1][1]=y2;
	x[2][0]=1;
	x[2][1]=1;



	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			xi[i][j]=0;
			for(k=0;k<3;k++)
			{
				xi[i][j]+=t[i][k]*x[k][j];

			}

		}
	}


	x1=xi[0][0];
	x2=xi[0][1];
	y1=xi[1][0];
	y2=xi[1][1];


	glColor3f(1,0,0);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);

	glEnd();
	glFlush();


}


void translate()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0,0,1);
	int x1,y1,x2,y2,tx,ty,t[3][3],x[3][2],i,j,k;
	int xi[3][2];
	glBegin(GL_LINES);
    x1=0;
    y1=0;
    x2=100;
    y2=100;

	tx=100;
	ty=10;


	glVertex2f(x1,y1);
	glVertex2f(x2,y2);




for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
		if(i==j)
			t[i][j]=1;
		else
			t[i][j]=0;
	}
}

t[0][2]=tx;
t[1][2]=ty;
x[0][0]=x1;
x[0][1]=x2;
x[1][0]=y1;
x[1][1]=y2;
x[2][0]=1;
x[2][1]=1;


for(i=0;i<3;i++)
{
	for(j=0;j<2;j++)
	{
		xi[i][j]=0;
		for(k=0;k<3;k++)
		{
			xi[i][j]+=t[i][k]*x[k][j];

		}

	}
}


x1=xi[0][0];
x2=xi[0][1];
y1=xi[1][0];
y2=xi[1][1];


glColor3f(1,0,0);
glVertex2f(x1,y1);
glVertex2f(x2,y2);

glEnd();
glFlush();


}
void display()
{
int n;
printf("1.translate\n");
printf("2.rotate\n");
printf("3.scale\n");
printf("enter option\n");
scanf("%d",&n);
switch(n)
{
case 1:translate();
		break;
case 2: rotate();
		break;
case 3: scale();
		break;
default:printf("invalid choice\n");
}



}
int main(int argv,char** argc)
{
	glutInit(&argv,argc);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(350,40);
	glutCreateWindow("2d transform");
	glutDisplayFunc(reflection);
	gluOrtho2D(-300,300,-300,300);
	glutMainLoop();
	return 0;

}
