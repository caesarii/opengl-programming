//
//  main.c
//  glut
//
//  Created by qinghe on 2020/5/11.
//  Copyright © 2020 qinghe. All rights reserved.
//

#include <glut/glut.h>
#define BUFFER_OFFSET(bytes) ((GLubyte*) NULL + (bytes))

void
init(void) {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}



void
drawArrayElement () {
    // interwined 数组
    GLfloat vertices[][6] = {
        {1.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0, 500.0, 0.0},
        {0.0, 0.0, 1.0, 500.0, 500.0, 0.0},
        {1.0, 1.0, 1.0, 500.0, 0.0, 0.0},
    };
    
    GLubyte indices[][4] = {{0, 1, 2, 3}};
    
    // 缓冲区对象
    GLuint buffers[2];
    // 创建
    glGenBuffers(2, buffers);
    
    
    // 激活
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    // 初始化
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), BUFFER_OFFSET(3*sizeof(GLfloat)));
    glEnableClientState(GL_VERTEX_ARRAY);
    
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), BUFFER_OFFSET(0));
    glEnableClientState(GL_COLOR_ARRAY);

    // 渲染缓冲数据
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, 0);

}

void
render(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawArrayElement();
    
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
