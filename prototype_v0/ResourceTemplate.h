#pragma once

#include <string>

using namespace std;

template <class resourceType>
class ResourceTemplate
{
public:
	ResourceTemplate(string name, string path) : name(name), path(path) {};
	
	resourceType& get() {
		return data;
	};

protected:
	resourceType data;
	string name;
	string path;
};
