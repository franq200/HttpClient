#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

struct Person {
	std::string address;
	int age;
    std::string city;
	std::string firstName;
	std::string lastName;
    int personId;
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    // userp – to wskaŸnik przekazany przez CURLOPT_WRITEDATA
    std::string* buffer = static_cast<std::string*>(userp);

    size_t totalBytes = size * nmemb;
    buffer->append(static_cast<char*>(contents), totalBytes);
    return totalBytes; // koniecznie zwróæ liczbê przetworzonych bajtów
}

void from_json(const nlohmann::json& j, Person& p) {
    p.address = j.value("Address", "");
    p.age = j.at("Age").get<int>();
    p.city = j.value("City", "");
    p.firstName = j.value("FirstName", "");
    p.lastName = j.value("LastName", "");
    p.personId = j.value("PersonID", 0);
}

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL* curl = curl_easy_init();
    std::vector<Person> people;
    if (curl) {
		std::string response;
        curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:5000/api/people");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << "\n";
        curl_easy_cleanup(curl);
        try {
            auto json = nlohmann::json::parse(response);
            people = json.get<std::vector<Person>>();
        }
        catch (const std::exception& e) {
            std::cerr << "JSON parse error: " << e.what() << "\n";
        }
    }
    curl_global_cleanup();
    return 0;
}