#pragma once

#include <map>
#include <iostream>
#include <memory>
#include "ResourceTemplate.h"
#include <time.h>

using namespace std;

template <typename T>
class ResourceManager
{
public:
	ResourceManager<T>() {};
	~ResourceManager<T>() { data.clear(); };

	T & get(string name, string path = "")
	{
		if (isIn(name))
			return find(name);

		return create(name, path);
	}

private:
	std::map<std::string, std::shared_ptr<ResourceTemplate<T>>> data;

protected:
	T& find(string name)
	{
		return data.at(name)->get();
	}

	bool isIn(string name) 
	{
		return data.count(name) > 0;
	}

	T& create(string name, string path)
	{
		auto res = std::make_shared<ResourceTemplate<T>>(name, path);
		data[name] = res;
		return res->get();
	}
};
