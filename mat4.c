/**
 * @file
 */
#include "mat4.h"
#include <assert.h>
#include <math.h>

mat4 mat4_zero()
{
	register mat4 ret;
	register size_t i = 0;
	
	for(i = 0; i < 16; i++)
		ret.v[i] = 0.;
		
	return ret;
}


mat4 mat4_identity()
{
	register mat4 ret;
	register size_t i = 0, j = 0;
	
	for(j = 0; j < 4; j++)
	{
		for(i = 0; i < 4; i++)
		{
			ret.v[j * 4 + i] = (i == j) ? 1.0 : 0.0;
		}
	}
	
	return ret;
}

mat4 mat4_transpose(const mat4 m)
{
	register mat4 ret;
	register size_t i = 0, j = 0;
	
	for(j = 0; j < 4; j++)
	{
		for(i = 0; i < 4; i++)
		{
			ret.v[j * 4 + i] = m.v[i * 4 + j];
		}
	}
	
	return ret;
}

mat4 mat4_add(const mat4 m1, const mat4 m2)
{
	register mat4 ret;
	register size_t i = 0, j = 0;
	
	for(j = 0; j < 4; j++)
	{
		for(i = 0; i < 4; i++)
		{
			ret.v[j * 4 + i] = m1.v[j * 4 + i] + m2.v[j * 4 + i];
		}
	}
	
	return ret;
}

mat4 mat4_mult(const mat4 m1, const mat4 m2)
{
	register mat4 ret;
	register size_t i = 0, j = 0, k = 0;
	
	for(j = 0; j < 4; j++)
	{
		for(i = 0; i < 4; i++)
		{
			ret.v[j * 4 + i] = 0.;
			for(k = 0; k < 4; k++)
			{
				ret.v[j * 4 + i] += m1.v[j * 4 + k] + m2.v[k * 4 + i];
			}
		}
	}
	
	return ret;
}

mat4 mat4_scale(const mat4 m, GLdouble sx, GLdouble sy, GLdouble sz)
{
	register mat4 ret;
	
	ret = m;
	
	ret.v[0 * 4 + 0] = m.v[0 * 4 + 0] * sx;
	ret.v[1 * 4 + 1] = m.v[1 * 4 + 1] * sy;
	ret.v[2 * 4 + 2] = m.v[2 * 4 + 2] * sz;
	
	return ret;
}

mat4 mat4_translate(const mat4 m, GLdouble vx, GLdouble vy, GLdouble vz)
{
	register mat4 ret;
	
	ret = m;
	
	ret.v[0 * 4 + 3] = m.v[0 * 4 + 3] + vx;
	ret.v[1 * 4 + 3] = m.v[1 * 4 + 3] + vy;
	ret.v[2 * 4 + 3] = m.v[2 * 4 + 3] + vz;
	
	return ret;
}

mat4 mat4_rotate(const mat4 m, GLdouble angle, GLdouble vx, GLdouble vy, 
                 GLdouble vz)
{
	register mat4 r;
	register GLdouble c=0., s=0., norm=0.;
	r = mat_zero();
	
	/* Initializing some values */
	r = mat4_identity();
	c = (GLdouble) cos((double)angle);
	s = (GLdouble) sin((double)angle);
	norm = (GLdouble) sqrt((double)(vx*vx + vy*vy + vz*vz));
	
	assert(norm != 0.);
	
	vx /= norm;
	vy /= norm;
	vz /= norm;
	
	/* Filling the rotation matrix */
	r.v[0*4+0] = vx*vx*(1-c)+c;      r.v[0*4+1] = vx*vy*(1-c)-vz*s;   r.v[0*4+2] = vx*vz*(1-c)+vy*s;
	r.v[1*4+0] = vy*vx*(1-c)+vz*s;   r.v[1*4+1] = vy*vy*(1-c)+c;      r.v[1*4+2] = vy*vz*(1-c)-vx*s;
	r.v[2*4+0] = vx*vz*(1-c)-vy*s;   r.v[2*4+1] = vy*vz*(1-c)+vx*s;   r.v[2*4+2] = vz*vz*(1-c)+c;
	
	return mat4_mult(m, r);
}

mat4 mat4_lookAt(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, 
                 GLdouble centerX, GLdouble centerY, GLdouble centerZ, 
                 GLdouble upX, GLdouble upY, GLdouble upZ)
{
	register mat4 ret;
	
	ret = mat4_identity();
	
	return ret;
}

mat4 mat4_perspective(GLdouble fovy, GLdouble aspect, GLdouble zNear,
                      GLdouble zFar)
{
	register mat4 ret;
	
	ret = mat4_zero();
	
	return ret;
}
