#ifndef PF_MATH_H
#define PF_MATH_H

#include <GL/glew.h> /* GLfloat definition */
#include <stdio.h>   /* FILE definition    */
#define __USE_MISC
#include <math.h>    /* M_PI definition    */

#define DEG_TO_RAD(_deg) ((_deg)*(M_PI/180.0f))
#define RAD_TO_DEG(_rad) ((_rad)*(180.0f/M_PI))

typedef union vec2{
    GLfloat raw[2];
    struct{
        GLfloat x, y; 
    };
}vec2_t;

typedef union vec3{
    GLfloat raw[3];
    struct{
        GLfloat x, y, z; 
    };
}vec3_t;

typedef union vec4{
    GLfloat raw[4];
    struct{
        GLfloat x, y, z, w; 
    };
}vec4_t;

typedef vec4_t quat_t;

typedef union mat3x3{
    GLfloat raw[9];
    GLfloat cols[3][3];
    struct{
        GLfloat m0, m1, m2,
                m3, m4, m5,
                m6, m7, m8;
    };
}mat3x3_t;

typedef union mat4x4{
    GLfloat raw[16];
    GLfloat cols[4][4];
    struct{
        GLfloat m0, m1, m2, m3,
                m4, m5, m6, m7,
                m8, m9, m10,m11,
                m12,m13,m14,m15;
    };
}mat4x4_t;


/*****************************************************************************/
/* vec2                                                                      */
/*****************************************************************************/

int     PFM_Vec2_Dot       (vec2_t *op1, vec2_t *op2);
void    PFM_Vec2_Add       (vec2_t *op1, vec2_t *op2, vec2_t *out);
void    PFM_Vec2_Sub       (vec2_t *op1, vec2_t *op2, vec2_t *out);
void    PFM_Vec2_Scale     (vec2_t *op1, GLfloat scale, vec2_t *out);
GLfloat PFM_Vec2_Len       (vec2_t *op1);
void    PFM_Vec2_Normal    (vec2_t *op1,  vec2_t *out);

/*****************************************************************************/
/* vec3                                                                      */
/*****************************************************************************/

void    PFM_Vec3_Cross     (vec3_t *a,   vec3_t *b,   vec3_t *out);
GLfloat PFM_Vec3_Dot       (vec3_t *op1, vec3_t *op2);
void    PFM_Vec3_Add       (vec3_t *op1, vec3_t *op2, vec3_t *out);
void    PFM_Vec3_Sub       (vec3_t *op1, vec3_t *op2, vec3_t *out);
void    PFM_Vec3_Scale     (vec3_t *op1, GLfloat scale, vec3_t *out);
GLfloat PFM_Vec3_Len       (vec3_t *op1);
void    PFM_Vec3_Normal    (vec3_t *op1, vec3_t *out);
void    PFM_Vec3_Dump      (vec3_t *vec, FILE *dumpfile);

/*****************************************************************************/
/* vec4                                                                      */
/*****************************************************************************/

GLfloat PFM_Vec4_Dot       (vec4_t *op1, vec4_t *op2, vec4_t *out);
void    PFM_Vec4_Add       (vec4_t *op1, vec4_t *op2, vec4_t *out);
void    PFM_Vec4_Sub       (vec4_t *op1, vec4_t *op2, vec4_t *out);
void    PFM_Vec4_Scale     (vec4_t *op1, GLfloat scale, vec4_t *out);
GLfloat PFM_Vec4_Len       (vec4_t *op1);
void    PFM_Vec4_Normal    (vec4_t *op1, vec4_t *out);
void 	PFM_Vec4_Dump	   (vec4_t *vec, FILE *dumpfile);

/*****************************************************************************/
/* mat3x3                                                                    */
/*****************************************************************************/

void    PFM_Mat3x3_Scale   (mat3x3_t *op1,  GLfloat scale, mat3x3_t *out);
void    PFM_Mat3x3_Mult3x3 (mat3x3_t *op1,  mat3x3_t *op2, mat3x3_t *out);
void    PFM_Mat3x3_Mult3x1 (mat3x3_t *op1,  vec3_t *op2,   vec3_t *out);
void    PFM_Mat3x3_Identity(mat3x3_t *out);

/*****************************************************************************/
/* mat4x4                                                                    */
/*****************************************************************************/

void    PFM_Mat4x4_Scale   (mat4x4_t *op1, GLfloat scale, mat4x4_t *out);
void    PFM_Mat4x4_Mult4x4 (mat4x4_t *op1, mat4x4_t *op2, mat4x4_t *out);
void    PFM_Mat4x4_Mult4x1 (mat4x4_t *op1, vec4_t   *op2, vec4_t   *out);
void    PFM_Mat4x4_Identity(mat4x4_t *out);

void    PFM_Mat4x4_MakeScale   (GLfloat s1, GLfloat s2, GLfloat s3, mat4x4_t *out);
void    PFM_Mat4x4_MakeTrans   (GLfloat tx, GLfloat ty, GLfloat tz, mat4x4_t *out);
void    PFM_Mat4x4_MakeRotX    (GLfloat radians, mat4x4_t *out);
void    PFM_Mat4x4_MakeRotY    (GLfloat radians, mat4x4_t *out);
void    PFM_Mat4x4_MakeRotZ    (GLfloat radians, mat4x4_t *out);
void    PFM_Mat4x4_RotFromQuat (const quat_t *quat, mat4x4_t *out);
void    PFM_Mat4x4_RotFromEuler(GLfloat deg_x, GLfloat deg_y, GLfloat deg_z, mat4x4_t *out);
void    PFM_Mat4x4_Inverse     (mat4x4_t *in, mat4x4_t *out);

void    PFM_Mat4x4_MakePerspective(GLfloat fov_radians, GLfloat aspect_ratio, 
                                   GLfloat z_near, GLfloat z_far, mat4x4_t *out);
void    PFM_Mat4x4_MakeLookAt     (vec3_t *camera_pos, vec3_t *target_pos, 
                                   vec3_t *up_dir, mat4x4_t *out);

/*****************************************************************************/
/* quat                                                                      */
/*****************************************************************************/

void    PFM_Quat_FromRotMat(mat4x4_t *mat, quat_t *out);
void    PFM_Quat_ToEuler   (quat_t *q, float *out_roll, float *out_pitch, float *out_yaw);

#endif
