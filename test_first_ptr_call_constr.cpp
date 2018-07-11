#include "SmartCache.h"
#include "TestData.h"
#include <iostream>
#include <cassert>    
#include <string>

class test_first_ptr_call_constr
{
public:
	test_first_ptr_call_constr()
	{
		cache<int, TestData, TestData*(*)(int)> new_cache(create_test_data);
		auto count_before = TestData::call_amount;
		auto ptr1 = new_cache.get_by_id(1);
		auto count_after = TestData::call_amount;

		assert(count_after == count_before + 1);
	}
};

static test_first_ptr_call_constr the_test;