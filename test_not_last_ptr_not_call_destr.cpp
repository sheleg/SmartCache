#include "SmartCache.h"
#include "TestData.h"
#include <iostream>
#include <cassert>    
#include <string>

class test_not_last_ptr_not_call_destr
{
public:
	test_not_last_ptr_not_call_destr()
	{
		cache<int, TestData, TestData*(*)(int)> new_cache(create_test_data);

		auto ptr1 = new_cache.get_by_id(1);
		int count_after = TestData::call_amount;

		{
			auto ptr2 = new_cache.get_by_id(1);
		}

		auto count_before = TestData::call_amount;

		assert(count_after == count_before);
	}
};

static test_not_last_ptr_not_call_destr the_test3;