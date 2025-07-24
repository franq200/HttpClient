#include "IPersonHttpClient.h"

IPersonHttpClient::IPersonHttpClient(IClientHttp& clientHttp, IDataParser<Person>& dataParser)
	: clientHttp_(clientHttp), dataParser_(dataParser)
{
}
