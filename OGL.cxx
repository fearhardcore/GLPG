#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535897932
void affichage ()
{
	GLbitfield masque = GL_COLOR_BUFFER_BIT;
	glClear(masque);

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.5, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
	glFlush();
}

GLfloat * CreateMatEch (GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat M[] =
{ x,   0.0, 0.0, 0.0,
  0.0, y,   0.0, 0.0,
  0.0, 0.0, z,   0.0,
  0.0, 0.0, 0.0, 1.0};
	return M;
}

GLfloat* CreateMatRotx (GLfloat angle)
{
	GLfloat M[] =
{ 1.0,  0.0,         0.0,          0.0,
  0.0,  cosf(angle), sinf(angle),  0.0,
  0.0,  -sinf(angle),cosf(angle),  0.0,
  0.0,  0.0,         0.0,          1.0};
	return M;
};

GLfloat* CreateMatRotz (GLfloat angle)
{
	GLfloat M[] =
{ cosf(angle),  sinf(angle),  0.0, 0.0,
  -sinf(angle), cosf(angle),  0.0, 0.0,
  0.0,          0.0,          1.0, 0.0,
  0.0,          0.0,          0.0, 1.0};
	return M;
};

GLfloat* CreateMatRoty (GLfloat angle)
{
	GLfloat M[] =
{ cosf(angle),  0.0, -sinf(angle), 0.0,
  0.0,          1.0, 0.0,          0.0,
  sinf(angle),  0.0, cosf(angle),  0.0,
  0.0,          0.0, 0.0,          1.0};
	return M;
};

GLfloat* CreateMatTransVec (GLfloat Tx, GLfloat Ty, GLfloat Tz)
{
	GLfloat M[] =
{ 1.0, 0.0, 0.0, 0,
  0.0, 1.0, 0.0, 0,
  0.0, 0.0, 1.0, 0,
  Tx, Ty, Tz, 1.0};
	return M;
}

/*GLfloat* CreateMatTransAngz (GLfloat angle, )
{
	GLfloat M[] =
{ 1.0, 0.0, 0.0, Tx,
  0.0, 1.0, 0.0, Ty,
  0.0, 0.0, 1.0, 0.0,
  0.0, 0.0, 0.0, 1.0};
}*/

void idle ()
{
	static float i;
	glLoadIdentity();

	glMultMatrixf(CreateMatEch(0.4,0.4,0));
	glLoadMatrixf(CreateMatTransVec(0.433,0.25,0));
	glMultMatrixf(CreateMatRotz(i-=0.001));
	//glMultMatrixf();
	glutPostRedisplay();

}

int main (int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(250,250);
	glutCreateWindow("ogl1");

	glClearColor(0.8,0.8,0.8,0.8);
	glPointSize(2.0);

	glutDisplayFunc(affichage);
	glutIdleFunc(idle);
	//glutKeyboardFunc(clavier);

	glutMainLoop();


}
