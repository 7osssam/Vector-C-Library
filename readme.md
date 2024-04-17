# Vector Library in C
*(under development)*

This project is a simple vector library implemented in C. It provides basic operations for working with dynamic arrays.

## Project Structure

The project is organized into two main directories: [`src`]( "src") and [`test`]( "test").

- [`src`]( "src"): Contains the source code for the vector library.
- [`test`]( "test"): Contains the test cases for the vector library.

## Building the Project

The project uses a Makefile for building the source code and running the tests. You can build the project using the following command:

```sh
make all # to build the source code
make run # to run the executable
```

This will compile the source code and generate an executable named `myprogram`.


## Dependencies

The project uses the [Unity Test Framework for C]( https://github.com/ThrowTheSwitch/Unity) for testing. The relevant Unity header files are included in the [`test`]( "test") directory.

## Code Overview

The vector library provides the following functions:
```c

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


```


## Contributing

Contributions are welcome. Please make sure to update the tests as appropriate when making changes.

## License

This project is licensed under the MIT License.