#include "SmartCache.h"
#include "TestData.h"
#include <iostream>
#include <cassert>    
#include <string>

class test_second_ptr_not_call_constr
{
public:
	test_second_ptr_not_call_constr()
	{
		cache<int, TestData, TestData*(*)(int) > new_cache(create_test_data);

		auto ptr1 = new_cache.get_by_id(1);
		auto count_first = TestData::call_amount;

		auto ptr2 = new_cache.get_by_id(1);
		auto count_second = TestData::call_amount;

		assert(count_first == count_second);
	}
};

static test_second_ptr_not_call_constr the_test4;