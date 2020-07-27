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
}


void
drawArrayElement () {
    
    GLfloat vertices[] = {
        0.0, 0.0, 0.0,
        0.0, 500.0, 0.0,
        500.0, 500.0, 0.0,
        500.0, 0.0, 0.0,
    };
    
    // 需要显示指定
    glShadeModel(GL_SMOOTH);

    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertices[0]);
    
   
    glBegin(GL_QUADS);
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(3);
    glEnd();
    
}

void
drawArrayElementBatch () {
    
    GLfloat vertices[] = {
        0.0, 0.0, 0.0,
        0.0, 500.0, 0.0,
        500.0, 500.0, 0.0,
        500.0, 0.0, 0.0,
    };
    
    // 需要显示指定
    glShadeModel(GL_SMOOTH);

    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertices[0]);
    
    GLubyte indices[] = {0, 1, 2, 3};
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, indices);
}

void
drawColorArrayElement () {
    
    GLfloat vertices[] = {
        0.0, 0.0, 0.0,
        0.0, 500.0, 0.0,
        500.0, 500.0, 0.0,
        500.0, 0.0, 0.0,
    };
    
    GLfloat colors[] = {
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 1.0, 1.0,
    };
    
    // 需要显示指定
    glShadeModel(GL_SMOOTH);
        
    // 激活
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    // 指定数组数据
    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertices[0]);
    glColorPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &colors[0]);
    

    // 索引数组列表, glArrayElement 一次使用一个元素, glDrawElements 根据索引数组使用多个元素
    // 与上面多次调用 glArrayElement 是等价的
    GLubyte indices[] = {0, 1, 2, 3};
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, indices);
}

void
drawInterwineArrayElement () {
    // interwined 数组
    GLfloat vertices[] = {
        1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 500.0, 0.0,
        0.0, 0.0, 1.0, 500.0, 500.0, 0.0,
        1.0, 1.0, 1.0, 500.0, 0.0, 0.0,
    };
    
    // 需要显示指定
    glShadeModel(GL_SMOOTH);
        
    // 激活
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    // 指定数组数据
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertices[0]);
    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertices[3]);
    
   
    GLubyte indices[] = {0, 1, 2, 3};
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, indices);
}

void
render(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // drawArrayElement();
    
    // drawArrayElementBatch();
    
    // drawColorArrayElement();
    
    drawInterwineArrayElement();
    
    glFlush();
}

void
reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
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
