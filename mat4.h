/**
 * @file
 */
#ifndef __MAT4_H__
#define __MAT4_H__

typedef struct { register GLdouble v[16]; } mat4;

/**
 * @brief Returns a zero-filled matrix.
 * @return The zero-filled matrix.
 */
mat4 mat4_zero();

/**
 * @brief Returns the identity matrix.
 * @return The identity matrix.
 */
mat4 mat4_identity();

/**
 * @brief Returns the transpose matrix of a given matrix.
 * @param m The matrix to transpose.
 * @return The transpose matrix.
 */
mat4 mat4_transpose(const mat4 m);

/**
 * @brief Adds two matrixes.
 * @param m1 First operand.
 * @param m2 Second operand.
 * @return The result of the addition.
 */
mat4 mat4_add(const mat4 m1, const mat4 m2);

/**
 * @brief Multiplies two matrixes.
 * @param m1 First operand.
 * @param m2 Second operand.
 * @return The result of the multiplication.
 */
mat4 mat4_mult(const mat4 m1, const mat4 m2);

/**
 * @brief Multiplies m by a scaling matrix.
 * @param m Matrix to 'scale'.
 * @param sx Scale factor along the x axis.
 * @param sy Scale factor along the y axis.
 * @param sz Scale factor along the z axis.
 * @return The result of the scaling.
 */
mat4 mat4_scale(const mat4 m, GLdouble sx, GLdouble sy, GLdouble sz);

/**
 * @brief Multiplies m by a translation matrix.
 * @param m Matrix to 'translate'.
 * @param vx x coordinate of the translation vector.
 * @param vy y coordinate of the translation vector.
 * @param vz z coordinate of the translation vector.
 * @return The result of the translation.
 */
mat4 mat4_translate(const mat4 m, GLdouble vx, GLdouble vy, GLdouble vz);

/**
 * @brief Multiplies m by a rotation matrix.
 * @param m Matrix to 'rotate'.
 * @param angle Angle of rotation, in degrees.
 * @param vx x coordinate of the axis vector.
 * @param vy y coordinate of the axis vector.
 * @param vz z coordinate of the axis vector.
 * @return The result of the rotation.
 */
mat4 mat4_rotate(const mat4 m, GLdouble angle, GLdouble vx, GLdouble vy, 
                 GLdouble vz);

/**
 * @brief Returns a viewing transformation matrix.
 * @param eyeX x coordinate of the eye point.
 * @param eyeY y coordinate of the eye point.
 * @param eyeZ z coordinate of the eye point.
 * @param centerX x coordinate of the reference point.
 * @param centerY y coordinate of the reference point.
 * @param centerZ z coordinate of the reference point.
 * @param upX x coordinate of the up vector.
 * @param upY y coordinate of the up vector.
 * @param upZ z coordinate of the up vector.
 * @return The viewing transformation matrix.
 */
mat4 mat4_lookAt(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, 
                 GLdouble centerX, GLdouble centerY, GLdouble centerZ, 
                 GLdouble upX, GLdouble upY, GLdouble upZ);

/**
 * @brief Returns a perspective projection matrix.
 * @param fovy Field of view angle, in degrees, in the y direction.
 * @param aspect Aspect ratio that determines the field of view in the x 
 *               direction. The aspect ratio is the ratio of x (width) 
 *               to y (height).
 * @param zNear Distance from the viewer to the near clipping plane 
 *              (always positive).
 * @param zFar Distance from the viewer to the far clipping plane 
 *             (always positive).
 * @return The perspective projection matrix.
 */
mat4 mat4_perspective(GLdouble fovy, GLdouble aspect, GLdouble zNear,
                      GLdouble zFar);

#endif
