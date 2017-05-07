/**
 * @file
 */
#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#include "shader.h"

/**
 * @brief Data structure representing an OpenGL program.
 */
struct program
{
	GLuint pid; /*!< OpenGL Id. */
	shader* vs; /*!< Vertex shader. */
	shader* fs; /*!< Fragment shader. */
};
typedef struct program program;

/**
 * @brief Set a program structure to default setting.
 * @param prgm Pointer to the program structure. Must be non-NULL.
 */
void program_set(program* prgm);

/**
 * @brief Instantiates a program structure.
 * @param vfile Name of the file containing the vertex shader. Must be 
 *        non-NULL.
 * @param ffile Name of the file containing the fragment shader. Must be 
 *        non-NULL.
 * @return A pointer to the program structure upon success and NULL 
 *         otherwise. In such case, an appropriate error message is 
 *         displayed in stderr.
 */
program* program_new(const char* vfile, const char* ffile);

/**
 * @brief Link an OpenGL program.
 * @param prgm Pointer to the program structure. Must be non-NULL.
 * @param ffile Name of the file containing the fragment shader. Must be 
 *        non-NULL.
 * @return A boolean (0 for false, 1 for true) that indicates if the 
 *         program has been successfully linked. Upon error, an 
 *         appropriate error message is displayed in stderr.
 */
int program_link(program* prgm);

/**
 * @brief Use an OpenGL program.
 * @param prgm Pointer to the program structure. If NULL, no program is 
 *             used.
 */
void program_use(program* prgm);

/**
 * @brief Releases a program structure.
 * @param prgm Pointer to the program to free. If NULL, this function 
 *             does nothing.
 */
void program_free(program* prgm);

#endif
