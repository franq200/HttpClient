#pragma once
#include "IDataParser.h"
#include <nlohmann/json.hpp>
template<typename T>
class JsonDataParser : public IDataParser<T>
{
public:
	std::string Serialize(const T& data) const override 
	{
		nlohmann::json j = data;
		return j.dump();
	}
	T Deserialize(const std::string& data) const override 
	{
		nlohmann::json j = nlohmann::json::parse(data);
		return j.get<T>();
	}
};

