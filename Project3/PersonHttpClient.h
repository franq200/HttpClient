#pragma once
#include "IPersonHttpClient.h"

class PersonHttpClient : public IPersonHttpClient
{
public:
	PersonHttpClient(IClientHttp& clientHttp, IDataParser<Person>& dataParser);
	// Implement the pure virtual methods for HTTP operations
	Person GetPerson(int id) override;
	void CreatePerson(const std::string& name, int age) override;
	void UpdatePerson(int id, const std::string& name, int age) override;
	void DeletePerson(int id) override;
private:
};

