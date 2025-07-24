#include "PersonHttpClient.h"
#include "IClientHttp.h"
#include "IDataParser.h"
#include <stdexcept>

PersonHttpClient::PersonHttpClient(IClientHttp& clientHttp, IDataParser<Person>& dataParser) : IPersonHttpClient(clientHttp, dataParser)
{
}

Person PersonHttpClient::GetPerson(int id)
{
    if (id <= 0) 
    {
        throw std::invalid_argument("ID must be greater than 0");
    }

    // Przyk³ad u¿ycia klienta HTTP do wykonania ¿¹dania GET
    std::string url = "/person/" + std::to_string(id);
	std::string response = clientHttp_.sendGetRequest(url);

    // Mo¿esz dodaæ dodatkow¹ walidacjê odpowiedzi
    if (response.empty()) 
    {
        throw std::runtime_error("No data received from server");
    }
	Person person = dataParser_.Deserialize(response);

    return person;
}

void PersonHttpClient::CreatePerson(const std::string& name, int age)
{
}

void PersonHttpClient::UpdatePerson(int id, const std::string& name, int age)
{
}

void PersonHttpClient::DeletePerson(int id)
{
}
