#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

VectorStatus Vector_init(Vector* vec)
{
	VectorStatus status = V_SUCCESS;

	if (vec == NULL)
	{
		status = V_NULL;
		return status;
	}
	else
	{
		vec->size = 0;
		vec->capacity = VECTOR_INITIAL_CAPACITY;
		vec->data = (int*)malloc(sizeof(int) * vec->capacity);

		if (vec->data == NULL)
		{
			status = V_NULL;
			return status;
		}
	}

	return status;
}

int Vector_at(Vector* vec, int index)
{
	if (index >= vec->size || index < 0)
	{
		/* Error handling for index out of bounds */
		fprintf(stderr, "Index %d out of bounds for array of size %d\n", index, vec->size);
		exit(EXIT_FAILURE);
	}

	return vec->data[index];
}

void Vector_set(Vector* vec, int index, int value)
{
	/* Resize array if necessary to guarantee space for index */
	while (index >= vec->size)
	{
		Vector_push_back(vec, 0);
	}

	/* Set value at index */
	vec->data[index] = value;
}

void Vector_push_back(Vector* vec, int value)
{
	/* Resize array if necessary */
	Vector_resize(vec);

	/* Append value to array */
	vec->data[vec->size] = value;
	vec->size++;
}

void Vector_prepend(Vector* vec, int value)
{
	/* Shift existing elements to make space for new value */
	Vector_set(vec, 0, value);
}

int Vector_pop_back(Vector* vec)
{
	/* Check if array is empty */
	if (vec->size == 0)
	{
		/* Error handling for popping from an empty array */
		fprintf(stderr, "Cannot pop from empty array\n");
		exit(EXIT_FAILURE);
	}

	/* Retrieve and remove last element */
	int data = vec->data[vec->size - 1];
	vec->size--;
	return data;
}

void Vector_erase(Vector* vec, int index)
{
	/* Check if index is out of bounds */
	if (index < 0 || index >= vec->size)
	{
		/* Error handling for index out of bounds */
		fprintf(stderr, "Index %d out of bounds for array of size %d\n", index, vec->size);
		exit(EXIT_FAILURE);
	}

	/* Shift elements after index to fill the gap */
	for (int i = index; i < vec->size - 1; i++)
	{
		vec->data[i] = vec->data[i + 1];
	}
	vec->size--;
}

void Vector_remove(Vector* vec, int value)
{
	/* Find index of value and delete it */
	int index = Vector_find(vec, value);
	if (index != -1)
	{
		Vector_erase(vec, index);
	}
}

int Vector_find(Vector* vec, int value)
{
	/* Search for value in array */
	for (int i = 0; i < vec->size; i++)
	{
		if (vec->data[i] == value)
		{
			return i;
		}
	}

	/* Value not found */
	return -1;
}

void Vector_resize(Vector* vec)
{
	/* Double the capacity if array is full */
	if (vec->size >= vec->capacity)
	{
		vec->capacity *= 2; // Double the capacity of the array when it is full
		vec->data = (int*)realloc(vec->data, sizeof(int) * vec->capacity);
		if (vec->data == NULL)
		{
			/* Error handling for memory allocation failure */
			perror("Error resizing array");
			exit(EXIT_FAILURE);
		}
	}
}

int Vector_size(Vector* vec)
{
	return vec->size;
}

int Vector_capacity(Vector* vec)
{
	return vec->capacity;
}

bool Vector_isEmpty(Vector* vec)
{
	return vec->size == 0;
}

void Vector_freeMemory(Vector* vec)
{
	/* Free memory allocated for array data */
	free(vec->data);
}
