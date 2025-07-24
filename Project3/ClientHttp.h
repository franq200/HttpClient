#pragma once
#include "IClientHttp.h"

class ClientHttp : public IClientHttp
{
public:
	ClientHttp() = default;
	~ClientHttp() = default;
	std::string sendGetRequest(const std::string& url) override;
	std::string sendPostRequest(const std::string& url, const std::string& data) override;
};

