#pragma once  
#include <string>  

template<typename T>
class IDataParser;
class IClientHttp;  

struct Person 
{  
    bool operator==(const Person& other) const 
    {  
       return address == other.address &&  
              age == other.age &&  
              city == other.city &&  
              firstName == other.firstName &&  
              lastName == other.lastName &&  
              personId == other.personId;  
    }
	std::string address;  
	int age;  
	std::string city;  
	std::string firstName;  
	std::string lastName;  
	int personId;  
};  

class IPersonHttpClient  
{  
public:  
   IPersonHttpClient(IClientHttp& clientHttp, IDataParser<Person>& dataParser);
   virtual ~IPersonHttpClient() = default;  
   // Pure virtual methods for HTTP operations  
   virtual Person GetPerson(int id) = 0;  
   virtual void CreatePerson(const std::string& name, int age) = 0;  
   virtual void UpdatePerson(int id, const std::string& name, int age) = 0;  
   virtual void DeletePerson(int id) = 0;  
protected:  
   IClientHttp& clientHttp_;  
   IDataParser<Person>& dataParser_;
};
