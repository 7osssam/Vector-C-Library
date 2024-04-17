#include "unity.h"
#include "../src/Vector.h"

// Declare the vec as a global variable
Vector vec;

void setUp(void)
{
	// This is run before EACH test
	Vector_init(&vec);
}

void tearDown(void)
{
	// This is run after EACH test
	Vector_freeMemory(&vec);
}

void test_Vector_init(void)
{
	Vector		 locat_vec;
	VectorStatus status = Vector_init(&locat_vec);

	TEST_ASSERT_EQUAL_INT(VECTOR_INITIAL_CAPACITY, locat_vec.capacity);
	TEST_ASSERT_EQUAL_INT(0, locat_vec.size);
	TEST_ASSERT_EQUAL_INT(V_SUCCESS, status);
}

void test_Vector_push_back(void)
{
	Vector_push_back(&vec, 123);

	TEST_ASSERT_EQUAL_INT(123, vec.data[0]);
	TEST_ASSERT_EQUAL_INT(1, vec.size);
}

void test_Vector_prepend(void)
{
	Vector_prepend(&vec, 123);

	TEST_ASSERT_EQUAL_INT(123, vec.data[0]);
	TEST_ASSERT_EQUAL_INT(1, vec.size);
}

void test_Vector_delete(void)
{
	Vector_push_back(&vec, 123);
	Vector_erase(&vec, 0);

	TEST_ASSERT_EQUAL_INT(0, vec.size);
}

void test_Vector_deleteValue(void)
{
	Vector_push_back(&vec, 123);
	Vector_remove(&vec, 123);

	TEST_ASSERT_EQUAL_INT(0, vec.size);
}

void test_Vector_set(void)
{
	Vector_push_back(&vec, 123);
	Vector_set(&vec, 0, 456);

	TEST_ASSERT_EQUAL_INT(456, vec.data[0]);
}

void test_Vector_at(void)
{
	Vector_push_back(&vec, 123);

	TEST_ASSERT_EQUAL_INT(123, Vector_at(&vec, 0));
}

void test_Vector_pop_back(void)
{
	Vector_push_back(&vec, 123);

	TEST_ASSERT_EQUAL_INT(123, Vector_pop_back(&vec));
	TEST_ASSERT_EQUAL_INT(0, vec.size);
}

void test_Vector_findValue(void)
{
	Vector_push_back(&vec, 123);

	TEST_ASSERT_EQUAL_INT(0, Vector_find(&vec, 123));
}

void test_Vector_size(void)
{
	Vector_push_back(&vec, 123);

	TEST_ASSERT_EQUAL_INT(1, Vector_size(&vec));
}

void test_Vector_capacity(void)
{
	TEST_ASSERT_EQUAL_INT(VECTOR_INITIAL_CAPACITY, Vector_capacity(&vec));
}

void test_Vector_isEmpty(void)
{
	TEST_ASSERT_TRUE(Vector_isEmpty(&vec));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_Vector_init);
	RUN_TEST(test_Vector_push_back);
	RUN_TEST(test_Vector_prepend);
	RUN_TEST(test_Vector_delete);
	RUN_TEST(test_Vector_deleteValue);
	RUN_TEST(test_Vector_set);
	RUN_TEST(test_Vector_at);
	RUN_TEST(test_Vector_pop_back);
	RUN_TEST(test_Vector_findValue);
	RUN_TEST(test_Vector_size);
	RUN_TEST(test_Vector_capacity);
	RUN_TEST(test_Vector_isEmpty);
	return UNITY_END();
}