#ifndef SNAKE_H
#define SNAKE_H
#include"snake.h"
#include <GL/glut.h>
#include<time.h>
#include<stdio.h>
#include <termios.h>
#include <unistd.h>
#include<iostream>
int length = 3;
int speed = 100;
int right = 0;
int score=0;

struct snake{
    int x;
    int y;
};

struct frukt{
	int x;
	int y;
};

void init();
void display();
inline void SpecialKeyboard(int key,int x, int y);
void timer(int = 0);

snake Python[100];
frukt Apple;

void init(){
	int length = 3;
	int speed = 100;
	int right = 0;

	srand(time(NULL));

	while(true)
	{
		Apple.x = rand()%400;
		Apple.y = rand()%300;
		if(Apple.x%10 == 0 && Apple.y%10 == 0 && Apple.x > 40 && Apple.x < 350 && Apple.y > 40 && Apple.y < 250) break;
	}

	Python[0].x = 200;
	Python[0].y = 150;

	for (int i = 0; i < length; ++i)
	{
		Python[i+1].x = Python[i].x;
		Python[i+1].y = Python[i].y +10;
	}
	timer();
}
void timer(int ){
	display();

	if(right == 0 && speed % 10 == 0)
	{
		for(int i = length-1; i>0; --i)
		{
			Python[i].x = Python[i-1].x;
			Python[i].y = Python[i-1].y;
		}
		Python[0].y -= 10;
		speed=1;
	}

	if(right == 1 && speed % 10 == 0)
	{
		for(int i = length-1; i>0; --i)
		{
			Python[i].x = Python[i-1].x;
			Python[i].y = Python[i-1].y;
		}
		Python[0].x += 10;
		speed=1;
	}

	if(right == 2 && speed % 10 == 0)
	{
		for(int i = length - 1; i>0; --i)
		{
			Python[i].x = Python[i-1].x;
			Python[i].y = Python[i-1].y;
		}
		Python[0].y += 10;
		speed=1;
	}

	if(right == 3 && speed % 10 == 0)
	{
		for(int i = length-1; i>0; --i)
		{
			Python[i].x = Python[i-1].x;
			Python[i].y = Python[i-1].y;
		}
		Python[0].x -= 10;
		speed=1;
	}

	if(Python[0].x <= 30 || Python[0].y <= 30 || Python[0].x >= 390 || Python[0].y >= 290 )
	{
		std::cout<<"\nGame over: BBabAX %Ъ\nScore: "<<score<<"\n";
		exit(0);
	}

 	glutSpecialFunc(SpecialKeyboard);
	
	if(Python[0].x == Apple.x && Python[0].y == Apple.y){
		while(true){
		 Apple.x = rand()%400;
		 Apple.y = rand()%300;
		 if(Apple.x%10 == 0 && Apple.y%10 == 0 && Apple.x > 40 && Apple.x < 350 && Apple.y > 40 && Apple.y < 250) break;
		}
		++length;
		score++;
		std::cout<<"\nScore: "<<score;
		Python[length].x = Python[length].x;
		Python[length].y = Python[length].y - 10;
	}

	for(int i = 1; i < length; ++i)
		if(Python[0].x == Python[i].x && Python[0].y == Python[i].y){
			std::cout<<"\nCannibalism... This is very bad!!!\n Score: "<<score<<"\n";
			exit(0);
		}

	if(length==100){
		std::cout<<"\nYou win: max lenght!\nScore: "<<score<<"\n";
		exit(0);
	}

	if(speed < 200) speed++;

	glutTimerFunc(10, timer, 0);
}

void display(){
	glPointSize(10);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);

		glColor3f(.1, .1, 0);
		for (int i = 20; i < 380; i++) glVertex2f(i, 20);
		for (int i = 20; i < 280; i++) glVertex2f(20, i);
		for (int i = 20; i < 380; i++) glVertex2f(i, 280);
		for (int i = 20; i < 280; i++) glVertex2f(380, i);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
		glColor3f(0, 1, 0);

		for (int i = 0; i < length; ++i)
		{
			glVertex2f(Python[i].x-10, Python[i].y-10);
		}

		glColor3f(1, 0.3, 0);
		glVertex2f(Apple.x-10, Apple.y-10);

	glClear(GL_COLOR_BUFFER_BIT);

	glEnd();
	glFlush();
	glutSwapBuffers();
	
}


void SpecialKeyboard(int key,int x, int y){
	if(key==GLUT_KEY_LEFT){
	  if( right != 1 )right = 3;
	}
	if(key== GLUT_KEY_RIGHT){
	   if( right != 3 )right = 1;
	}	
	if(key==GLUT_KEY_DOWN){
	  if( right != 2 )right = 0;
	}

	if (key==GLUT_KEY_UP){
 	  if( right != 0 )right = 2;
	}
}


#endif
