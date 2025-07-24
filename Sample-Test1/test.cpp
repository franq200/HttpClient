#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PersonHttpClient.h"
#include "IClientHttp.h"
#include "IDataParser.h"

// Mock class for IClientHttp
class MockClientHttp : public IClientHttp
{
public:
	MOCK_METHOD(std::string, sendGetRequest, (const std::string& url), (override));
	MOCK_METHOD(std::string, sendPostRequest, (const std::string& url, const std::string& data), (override));
};

// Mock class for IDataParser
template<typename T>
class MockDataParser : public IDataParser<T>
{
public:
	MOCK_METHOD(T, Deserialize, (const std::string& data), (const, override));
	MOCK_METHOD(std::string, Serialize, (const T& object), (const, override));
};

TEST(PersonTest, GetPerson_ReturnsExpectedPerson)  
{  
	MockClientHttp mockClientHttp;  
	MockDataParser<Person> mockDataParser;  
	
	const std::string url = "/person/1";  
	const std::string response = R"({"Address": "123 Main St", "Age": 30, "City": "New York", "FirstName": "John", "LastName": "Doe", "PersonID": 1})";  
	const Person expectedPerson{ "123 Main St", 30, "New York", "John", "Doe", 1 };  
	
	PersonHttpClient client(mockClientHttp, mockDataParser);  
	
	EXPECT_CALL(mockClientHttp, sendGetRequest(url)).WillOnce(testing::Return(response));  
	EXPECT_CALL(mockDataParser, Deserialize(response)).WillOnce(testing::Return(expectedPerson));  
	
	EXPECT_EQ(client.GetPerson(1), expectedPerson);  
}

TEST(PersonTest, GetPerson_InvalidId_ThrowsException)
{
	MockClientHttp mockClientHttp;
	MockDataParser<Person> mockDataParser;

	PersonHttpClient client(mockClientHttp, mockDataParser);

	EXPECT_THROW(client.GetPerson(0), std::invalid_argument);
	EXPECT_THROW(client.GetPerson(-1), std::invalid_argument);
}

TEST(PersonTest, GetPerson_NoDataReceived_ThrowsException)
{
	MockClientHttp mockClientHttp;
	MockDataParser<Person> mockDataParser;

	PersonHttpClient client(mockClientHttp, mockDataParser);

	const std::string url = "/person/1";

	EXPECT_CALL(mockClientHttp, sendGetRequest(url)).WillOnce(testing::Return(""));

	EXPECT_THROW(client.GetPerson(1), std::runtime_error);
}