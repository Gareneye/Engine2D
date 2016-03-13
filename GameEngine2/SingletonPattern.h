#pragma once
class SingletonPattern
{
public:
	static SingletonPattern & getSingleton()
	{
		static SingletonPattern singleton;
		return singleton;
	}
};

