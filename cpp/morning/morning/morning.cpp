// morning.cpp: 定义应用程序的入口点。
//

#include "morning.h"


std::string GetWeather( )
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
		Json::Reader reader;
		Json::Value root;
    // 解析到root，root将包含Json里所有子元素
	if (!reader.parse(res->body, root, false))
	{
		goto Failed;
	}
		int code = root["code"].asInt();
		if (code!=0)
		{
			std::string err = root["msg"].asString();
			return err;
		}
		else
		{
			Json::Value data = root["data"];
			Json::Value weatherLsit = data["list"];
			unsigned int count = weatherLsit.size();
			int temp = weatherLsit[0]["temp"].asInt();
			std::string info = mytime::format("温度:%d℃",temp);
			return info;
		}
		
	}
Failed:
	return "获取天气信息失败，联系我";
}

int main()
{
	while (true)
	{
		std::string enday = mytime::gettime( );
		int diffday = mytime::diffdays( "2021-06-01", enday );
		std::cout << "已经过去" << diffday << "天" << std::endl;
		std::cout << GetWeather( ) << std::endl;
		httplib::Client cli( "http://api.day.app" );
		std::string info;
		info = mytime::format("/VNMDM5dnwHiRbxsAnruoZY/提醒/在一起%d天\n",diffday);
		auto res = cli.Get(info.c_str());
		if(res->status)
		{
			std::cout<<res->body;
		}
		else
		{
			std::cout<<res->body;
		}
		break;
	}
	
	return 0;
}
