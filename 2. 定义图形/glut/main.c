//
//  main.c
//  glut
//
//  Created by qinghe on 2020/5/11.
//  Copyright © 2020 qinghe. All rights reserved.
//

#include <glut/glut.h>

void
init(void) {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}


void
drawOnePoint (float x1, float y1, float size) {
    glPointSize(size);
    
    glBegin(GL_POINTS);
        glVertex2f((x1), (y1));
    glEnd();
}

void
drawOneLine (float x1, float y1, float x2, float y2, float width) {
    glLineWidth(width);
    
    glBegin(GL_LINES);
        glVertex2f((x1), (y1)); glVertex2f((x2), (y2));
    glEnd();
}

void
drawPolygon(void) {
    glColor3f(1.0, 1.0, 1.0);
    
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(100.0, 0.0);
        glVertex2f(100.0, 100.0);
        glVertex2f(0.0, 100.0);
    glEnd();
}

void
drawColorPolygon(void) {
    glColor3f(1.0, 1.0, 1.0);
    
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(200.0, 0.0);
    
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(300.0, 0.0);
    
        glColor3f(1.0, 0.0, 1.0);
        glVertex2f(300.0, 100.0);
    
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(200.0, 100.0);
    glEnd();
}

void
reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
}


void
render(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawOnePoint(200.0, 200.0, 10);
    
    drawOneLine(300.0, 300.0, 600.0, 600.0, 10);
    
    drawPolygon();
    
    drawColorPolygon();
    
    glFlush();
}

int
main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("my first opengl");
    init();
    glutDisplayFunc(render);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
