/**
 * @file
 */
#include "shader.h"

#include "io.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void shader_set(shader* shdr)
{
	assert(shdr != NULL);
	
	shdr->sid = 0;
}

shader* shader_new(const char* filename, const GLenum type)
{
	shader* ret = NULL;
	char* content = NULL;
	GLint compileStatus = 0;
	char* compileError = NULL;
	GLint errorSize = 0;
	
	assert(filename != NULL);
	
	ret = malloc(sizeof(shader));
	
	if(ret != NULL)
	{
		shader_set(ret);
		
		/* We read the content of the file */
		content = file_read(filename);
		
		if(content != NULL)
		{
			/* We create the shader */
			ret->sid = glCreateShader(type);
			
			if(ret->sid > 0)
			{
				/* And then we compile it. */
				glShaderSource(ret, 1, &content, 0);
				glCompileShader(ret);
				
				/* We check for errors. */
				glGetShaderiv(ret, GL_COMPILE_STATUS, &compileStatus);
				
				if(compileStatus != GL_TRUE)
				{
					glGetShaderiv(ret, GL_INFO_LOG_LENGTH, &errorSize);
					
					compileError = malloc((size_t)errorSize + 1);
					
					if(compileError != NULL)
					{
						glGetShaderInfoLog(ret, errorSize, &errorSize, 
						                   compileError);
						compileError[errorSize] = '\0';
						
						/* We finally display the error message. */
						fprintf(stderr, "%s\n", compileError);
						
						free(compileError), compileError = NULL;
					}
					else
					{
						fprintf(stderr, "Error: Unable to allocate "
						                "enough memory to store the "
						                "compilation error message.\n");
					}
					
					shader_free(ret), ret = NULL;
				}
			}
			else
			{
				fprintf(stderr, "Error: Unable to create shader "
				                "unit.\n");
				                
				shader_free(ret), ret = NULL;
			}
			
			free(content), content = NULL;
		}
		else
		{
			fprintf(stderr, "Error: Unable to read file "
			                "'%s'.\n", filename);
			                
			shader_free(ret), ret = NULL;
		}
	}
	
	return ret;
}

void shader_free(shader* shdr)
{
	if(shdr != NULL)
	{
		if(shdr->sid > 0)
		{
			glDeleteShader(shdr->sid);
			shdr->sid = 0;
		}
		
		free(shdr), shdr = NULL;
	}
}
