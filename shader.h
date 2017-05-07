/**
 * @file
 */
#ifndef __SHADER_H__
#define __SHADER_H__

/**
 * @brief Data structure representing an OpenGL shader.
 */
struct shader
{
	GLuint sid; /*!< OpenGL Id. */
};
typedef struct shader shader;

/**
 * @brief Set a shader structure to default setting.
 * @param shdr Pointer to the shader structure. Must be non-NULL.
 */
void shader_set(shader* shdr);

/**
 * @brief Instantiates a shader structure.
 * @param filename Name of the file containing the shader. Must be 
 *        non-NULL.
 * @param type Shader type.
 * @return A pointer to the shader structure upon success and NULL 
 *         otherwise. In such case, an appropriate error message is 
 *         displayed in stderr.
 */
shader* shader_new(const char* filename, const GLenum type);

/**
 * @brief Releases a shader structure.
 * @param shdr Pointer to the shader to free. If NULL, this function 
 *             does nothing.
 */
void shader_free(shader* shdr);

#endif
