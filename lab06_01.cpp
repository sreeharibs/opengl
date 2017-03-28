#include <stdio.h>
#include<iostream>
#include <GL/glut.h>

int cost[10][10],n,mouseCount=0;




class Points{

public:
    float x;
    float y;

    void setPoints(float xa , float ya){

        x=xa;
        y=ya;

    }

};

Points XY[10];

void init(){

    glClearColor(0.0,0.0,0.0,1.0);
    gluOrtho2D(0,500,0,500);

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10);
    glEnable(GL_POINT_SMOOTH);

    glColor3f(1.0,1.0,1.0);

    glBegin(GL_POINTS);

            for(int i=0;i<n;i++)
                glVertex2f(XY[i].x,XY[i].y);


    glEnd();

    glBegin(GL_LINES);

            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(cost[i][j]!=0){

                        glVertex2f(XY[i].x,XY[i].y);
                        glVertex2f(XY[j].x,XY[j].y);

                    }

    glEnd();

    glutSwapBuffers();

}


void mouse(int btn, int state, int x , int y){


    if(mouseCount<n && state==GLUT_DOWN && btn==GLUT_LEFT_BUTTON){

        XY[mouseCount].setPoints(x,500-y);
        mouseCount++;

        display();
    }

}


int main(int argc,char** argv){


    printf("\n Enter the no: of vertices : ");
    std::cin>>n;

    printf("\n Enter the cost adjacency matrix \n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            std::cin>>cost[i][j];

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Graph");

    init();

    //callback functions
    glutDisplayFunc(display);
    glutIdleFunc(display);
    //glutKeyboardFunc(keyPressed);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;

}
