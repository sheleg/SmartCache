#include "TestData.h"

int TestData::call_amount = 0;

TestData* create_test_data(int id)
{
	return new TestData(id);
}
