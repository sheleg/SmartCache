#pragma once
#include <iostream>
#include <string>

class TestData
{
public:
	static int call_amount;

	TestData(int id)
		: name("TestData object id=" + std::to_string(id))
	{
		++call_amount;
		std::cout
			<< name
			<< " created"
			<< std::endl;
	}

	~TestData()
	{
		--call_amount;
		std::cout
			<< name
			<< " destroyed"
			<< std::endl;
	}

	std::string name;
};

TestData* create_test_data(int id);

