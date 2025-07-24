#pragma once
#include <string>

class IClientHttp
{
public:
	virtual ~IClientHttp() = default;
	virtual std::string sendGetRequest(const std::string& url) = 0;
	virtual std::string sendPostRequest(const std::string& url, const std::string& data) = 0;
};

