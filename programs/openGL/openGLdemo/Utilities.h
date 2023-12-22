#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <string>
#include <fstream>
#include <ctime>

static const char* extract_version(const char* full)
{
	std::string p1 = full;
	static std::string p2;
	p2.clear();
	p2 = p1.substr(
		p1.find_last_of("/\\") + 1,
		(p1.length() - p1.find_last_of("/\\")) - (p1.length() - (p1.find_last_of(".")) + 1)
	);

	return p2.c_str();
}

#ifdef _DEBUG
static void write_log(const char* msg)
{
	std::ofstream logs;
	logs.open("our_logs.txt", std::fstream::app | std::fstream::out);
	logs << msg << std::endl;
	logs.close();
}
#else
static void write_log(const char* msg) {}
#endif

static const char* get_timestamp()
{
	std::time_t result = std::time(nullptr);
	return std::asctime(std::localtime(&result));
}
