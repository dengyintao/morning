// morning.cpp: 定义应用程序的入口点。
//

#include "morning.h"


std::string TestHttp( )
{
    //http://autodev.openspeech.cn/csp/api/v2.1/weather?openId=aiuicus&clientType=android&sign=android&city=郑州
	httplib::Client cli( "http://autodev.openspeech.cn" );
	httplib::Headers header;
	header.emplace( "Accept","text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9" );
	header.emplace( "Accept-Encoding", "gzip, deflate" );
	header.emplace( "Accept-Language", "zh-CN,zh;q=0.9" );
	header.emplace("User-Agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36" );
	header.emplace( "Upgrade-Insecure-Requests", "1" );
	header.emplace( "charset","utf-8" );

	auto res = cli.Get( "/csp/api/v2.1/weather?openId=aiuicus&clientType=android&sign=android&city=郑州",header );
	if (res->status)
	{
		return res->body;
	}
	return "err";
}

int main()
{
	while (true)
	{
		std::string enday = mytime::gettime( );
		int diffday = mytime::diffdays( "2021-06-01", enday );
		std::cout << "已经过去" << diffday << "天" << std::endl;
		std::cout << TestHttp( ) << std::endl;
		Sleep( 1000*10);
	}
	
	return 0;
}
