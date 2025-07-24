#pragma once
#include <string>
template<typename T>
class IDataParser
{
public:
	virtual ~IDataParser() = default;
	// Pure virtual methods for parsing operations
	virtual std::string Serialize(const T& data) const = 0;
	virtual T Deserialize(const std::string& data) const = 0;
};

