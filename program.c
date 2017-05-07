/**
 * @file
 */
#include "program.h"
#include <assert.h>

void program_set(program* prgm)
{
	assert(prgm != NULL);
	
	prgm->pid = 0;
	prgm->vs = NULL;
	prgm->fs = NULL;
}

program* program_new(const char* vfile, const char* ffile)
{
	program* ret = NULL;
	
	assert(vfile != NULL);
	assert(ffile != NULL);
	
	ret = malloc(sizeof(program));
	
	if(ret != NULL)
	{
		program_set(ret);
	
		ret->pid = glCreateProgram();
		
		if(ret->pid > 0)
		{
			ret->vs = shader_new(vfile, GL_VERTEX_SHADER);
			
			if(ret->vs != NULL)
			{
				ret->fs = shader_new(ffile, GL_FRAGMENT_SHADER);
			}
			
			/* 
			 * If one of the shader failed to load, we release the 
			 * entire structure. 
			 */
			if(ret->vs == NULL || ret->fs == NULL)
			{
				program_free(ret), ret = NULL;
			}
			else
			{
				/* If everything is fine... */
				
				glAttachShader(ret->pid, ret->vs);
				glAttachShader(ret->pid, ret->fs);
			}
		}
		else
		{
			fprintf(stderr, "Error: Unable to create program "
							"unit.\n");
							
			program_free(ret), ret = NULL;
		}
	}
	
	return ret;
}

int program_link(program* prgm)
{
	int ret = 0;
	GLint errorLink = 0;
	GLint errorSize = 0;
	char* linkingError = NULL;
	
	assert(prgm != NULL);
	
	glLinkProgram(prgm->pid);
    glGetProgramiv(prgm->pid, GL_LINK_STATUS, &errorLink);

	if(errorLink != GL_TRUE)
    {
        ret = 0;
        
        glGetProgramiv(prgm->pid, GL_INFO_LOG_LENGTH, &errorSize);
        linkingError = malloc(sizeof(char)*(errorSize + 1));
        
        if(linkingError != NULL)
        {
			glGetShaderInfoLog(prgm->pid, errorSize, &errorSize, 
			                   linkingError);
			linkingError[errorSize] = '\0';

			/* We finally display the error message. */
			fprintf(stderr, "%s\n", linkingError);

			free(linkingError), linkingError = NULL;
		}
		else
		{
			fprintf(stderr, "Error: Unable to allocate "
							"enough memory to store the "
							"linking error message.\n");
		}
    }
	
	assert(ret == 0 || ret == 1);
	return ret;
}

void program_use(program* prgm)
{
	if(prgm != NULL)
	{
		glUseProgram(prgm->pid);
	}
	else
	{
		glUseProgram(0);
	}
}

void program_free(program* prgm)
{
	if(prgm != NULL)
	{
		shader_free(prgm->vs);
		shader_free(prgm->fs);
		
		if(prgm->pid > 0)
		{
			glDeleteProgram(prgm->pid);
			prgm->pid = 0;
		}
		
		free(prgm), prgm = NULL;
	}
}
