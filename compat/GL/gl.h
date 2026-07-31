#ifndef _GL_GL_H_TCC_STUB
#define _GL_GL_H_TCC_STUB

// GL/gl.h minimal stub for tcc
// raylib uses glad.h for OpenGL loading; this stub provides only basic constants

#ifndef GL_TRUE
#define GL_TRUE 1
#endif

#ifndef GL_FALSE
#define GL_FALSE 0
#endif

#ifndef GLboolean
typedef unsigned char GLboolean;
#endif

#ifndef GLvoid
typedef void GLvoid;
#endif

#ifndef GLenum
typedef unsigned int GLenum;
#endif

#ifndef GLfloat
typedef float GLfloat;
#endif

#ifndef GLint
typedef int GLint;
#endif

#ifndef GLuint
typedef unsigned int GLuint;
#endif

#ifndef GLsizei
typedef int GLsizei;
#endif

#ifndef GLubyte
typedef unsigned char GLubyte;
#endif

#ifndef GL_DOUBLE
#define GL_DOUBLE 0x140A
#endif

#ifndef GL_FLOAT
#define GL_FLOAT 0x1406
#endif

#ifndef GL_INT
#define GL_INT 0x1404
#endif

#ifndef GL_UNSIGNED_BYTE
#define GL_UNSIGNED_BYTE 0x1401
#endif

#ifndef GL_UNSIGNED_INT
#define GL_UNSIGNED_INT 0x1405
#endif

#ifndef GL_RGB
#define GL_RGB 0x1907
#endif

#ifndef GL_RGBA
#define GL_RGBA 0x1908
#endif

#ifndef GL_DEPTH_TEST
#define GL_DEPTH_TEST 0x0B71
#endif

#ifndef GL_STENCIL_TEST
#define GL_STENCIL_TEST 0x0B90
#endif

#ifndef GL_TEXTURE_2D
#define GL_TEXTURE_2D 0x0DE1
#endif

#endif
