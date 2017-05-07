/**
 * @file
 */
#ifndef __IO_H__
#define __IO_H__

/**
 * @brief Read the whole content of a file.
 * @param filename Name of the file to read. Must be non-NULL.
 * @return A pointer to the content of the file or NULL upon failure.
 */
char* file_read(const char* filename);

#endif
