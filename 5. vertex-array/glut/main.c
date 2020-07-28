//
//  main.c
//  glut
//
//  Created by qinghe on 2020/5/11.
//  Copyright © 2020 qinghe. All rights reserved.
//

#include <glut/glut.h>
#include <OpenGL/gl3.h>

#define BUFFER_OFFSET(bytes) ((GLubyte*) NULL + (bytes))

void
init(void) {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void
drawByBufferData () {
    // 顶点数组
    GLfloat vertices[][6] = {
        {1.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0, 500.0, 0.0},
        {0.0, 0.0, 1.0, 500.0, 500.0, 0.0},
        {1.0, 1.0, 1.0, 500.0, 0.0, 0.0},
    };
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    GLubyte indices[][4] = {{0, 1, 2, 3}};
    

    
    GLuint vao[1];
    glGenVertexArrays(1, vao);
    glBindVertexArray(vao[0]);
    
    // 缓冲区对象
    // 1. 分配标识符
    int numberOfBuffer = 2;
    GLuint buffers[numberOfBuffer];
    glGenBuffers(numberOfBuffer, buffers);
   
    
    // 2. 绑定缓冲区对象
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    
    // 3. 分配内存空间
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 4. 将顶点数据存入缓冲区
    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), BUFFER_OFFSET(3*sizeof(GLfloat)));
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), BUFFER_OFFSET(0));

    
    // 5. 将用于渲染的数据存储缓冲区
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    
    // glBindVertexArrayAPPLE(vao[0]);
    
    // 6. 渲染
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, 0);

}

void
render(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawByBufferData();
    
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
