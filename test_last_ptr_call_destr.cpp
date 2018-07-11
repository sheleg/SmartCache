#include "SmartCache.h"
#include "TestData.h"
#include <iostream>
#include <cassert>    
#include <string>

class test_last_ptr_call_destr
{
public:
	test_last_ptr_call_destr()
	{
		cache<int, TestData, TestData*(*)(int) > new_cache(create_test_data);
		int count_before = 0;
		
		{
			auto ptr1 = new_cache.get_by_id(1);
			count_before = TestData::call_amount;
		}

		auto count_after = TestData::call_amount;

		assert(count_after == count_before - 1);
	}
};

static test_last_ptr_call_destr the_test2;