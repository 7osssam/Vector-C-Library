/**
 * @file Vector.h
 * @brief File containing the definition of the Vector library.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

#define VECTOR_INITIAL_CAPACITY 16

/**
 * @brief Struct representing a dynamic array.
 */
typedef struct
{
	int	 size;	   /**< The current number of elements in the vector. */
	int	 capacity; /**< The current capacity of the vector. */
	int* data;	   /**< Pointer to the array of elements. */
} Vector;

/**
 * @brief Enum representing the status of a vector operation.
 * @note Under development.
 */
typedef enum
{
	V_SUCCESS = 0,	 /**< Operation was successful. */
	V_NULL,			 /**< Vector pointer is NULL. */
	V_NOT_FOUND,	 /**< Element was not found. */
	V_OUT_OF_BOUNDS, /**< Index is out of bounds. */
	V_EMPTY,		 /**< Vector is empty. */
	V_FULL			 /**< Vector is full. */
} VectorStatus;

/**
 * @brief Initializes a Vector structure.
 * @param arr A pointer to the Vector structure to be initialized.
 * @return A VectorStatus indicating the status of the operation.
 */
VectorStatus Vector_init(Vector* arr);

/**
 * @brief Adds an element to the end of the vector.
 * @param arr A pointer to the Vector.
 * @param value The value to be added.
 */
void Vector_push_back(Vector* arr, int value);

/**
 * @brief Adds an element to the beginning of the vector.
 * @param arr A pointer to the Vector.
 * @param value The value to be added.
 */
void Vector_prepend(Vector* arr, int value);

/**
 * @brief Removes an element at a specific index in the vector.
 * @param arr A pointer to the Vector.
 * @param index The index of the element to be removed.
 */
void Vector_erase(Vector* arr, int index);

/**
 * @brief Removes a specific value from the vector.
 * @param arr A pointer to the Vector.
 * @param value The value to be removed.
 */
void Vector_remove(Vector* arr, int value);

/**
 * @brief Sets the value at a specific index in the vector.
 * @param arr A pointer to the Vector.
 * @param index The index of the element to be set.
 * @param value The new value.
 */
void Vector_set(Vector* arr, int index, int value);

/**
 * @brief Resizes the vector.
 * @param arr A pointer to the Vector.
 */
void Vector_resize(Vector* arr);

/**
 * @brief Frees the memory allocated to the vector.
 * @param arr A pointer to the Vector.
 */
void Vector_freeMemory(Vector* arr);

/**
 * @brief Retrieves the value at a specific index in the vector.
 * @param arr A pointer to the Vector.
 * @param value The index of the element to be retrieved.
 * @return The value at the specified index.
 */
int Vector_at(Vector* arr, int value);

/**
 * @brief Removes and returns the last element in the vector.
 * @param arr A pointer to the Vector.
 * @return The last element in the vector.
 */
int Vector_pop_back(Vector* arr);

/**
 * @brief Finds a specific value in the vector.
 * @param arr A pointer to the Vector.
 * @param value The value to be found.
 * @return The index of the value in the vector, or -1 if the value was not found.
 */
int Vector_find(Vector* arr, int value);

/**
 * @brief Returns the size of the vector.
 * @param arr A pointer to the Vector.
 * @return The size of the vector.
 */
int Vector_size(Vector* arr);

/**
 * @brief Returns the capacity of the vector.
 * @param arr A pointer to the Vector.
 * @return The capacity of the vector.
 */
int Vector_capacity(Vector* arr);

/**
 * @brief Checks if the vector is empty.
 * @param arr A pointer to the Vector.
 * @return true if the vector is empty, false otherwise.
 */
bool Vector_isEmpty(Vector* arr);

#endif /* VECTOR_H */