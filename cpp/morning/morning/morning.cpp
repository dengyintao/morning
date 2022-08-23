// morning.cpp: 定义应用程序的入口点。
//

#include "morning.h"
#include "./3rdparty/httplib/httplib.h"
#include "../../../../usr/local/include/json/json.h"

std::string TestHttp( )
{
	httplib::Client cli( "http://autodev.openspeech.cn" );
	auto res = cli.Get( "/csp/api/v2.1/weather?openId=aiuicus&clientType=android&sign=android&city=郑州" );
	if (res->status)
	{
		//Json::Reader reader;
		//Json::Value obj;
		//reader.parse( ifs, obj ); // reader can also read strings
		return res->body;
	}
	return "err";
}

int main()
{
	std::cout << TestHttp( ) << std::endl;
	return 0;
}
