/**
 * @file
 */
#include "io.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

char* file_read(const char* filename)
{
	char* ret = NULL;
	FILE* f = NULL;
	long length = 0;
	
	assert(filename != NULL);
	
	file = fopen(filename, "r");
	
	if(file != NULL)
	{		
		if(fseek(file, 0, SEEK_END) == 0)
		{
			length = ftell(file);
			
			if(length != -1 && fseek(file, 0, SEEK_SET) == 0)
			{
				ret = malloc((size_t)length + 1);
				
				if(ret != NULL)
				{
					if(fread(ret, (size_t)length, 1, file) != 0)
					{
						ret[length] = '\0';
					}
					else
					{
						free(ret), ret = NULL;
					}
				}
			}
		}
		
		(void)fclose(file), file = NULL;
	}
	
	return ret;
}
