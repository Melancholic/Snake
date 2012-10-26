#include"snake.h"
#include<iostream>
#include <GL/glut.h>
int main(int argc, char **argv){
	std::cout<<"\n****SNAKE****\n";
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400,300);
	glutInitWindowPosition(80,80);
	glutCreateWindow("Snake-OpenGL");
	glClearColor(3.0, 3.0, 1.0, 1.0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glViewport(0,0,400,300);
	gluOrtho2D(0.0, 400.0, 0.0, 300.0);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	std::cout<<"\n****END****\n";
	return 0;
	
}
