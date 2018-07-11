#include "SmartCache.h"
#include "TestData.h"
#include <iostream>
#include <cassert>    
#include <string>

void test_print_ptr_info(std::shared_ptr<TestData> const& ptr)
{
	std::cout
		<< "Address="
		<< ptr
		<< ", value="
		<< ptr->name
		<< std::endl;
}

int main() {
	std::cout << "Hello";

	return 0;
}