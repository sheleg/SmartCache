#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

template <typename ID, typename Obj, typename Creator>
class cache
{
public:
	using ptr_t = std::shared_ptr<Obj>;

private:
	std::unordered_map<ID, std::weak_ptr<Obj>> map_;
	Creator creator_;

	ptr_t get_by_id_impl(ID id)
	{
		ptr_t result = map_[id].lock();

		if (result == nullptr)
		{
			result = ptr_t(creator_(id));
			map_[id] = result;
		}

		return result;
	}

public:
	cache(Creator creator) : creator_(creator) {}

	ptr_t operator[](ID id)
	{
		return get_by_id_impl(id);
	}

	ptr_t get_by_id(ID id)
	{
		return get_by_id_impl(id);
	}
};



