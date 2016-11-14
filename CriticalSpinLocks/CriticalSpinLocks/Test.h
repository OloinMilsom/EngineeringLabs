#pragma once
#include <thread>
#include <list>
#include <iostream>
#include <string>

class Test {
private:
	static std::list<std::string> s_strings;
	std::string m_string;
	std::thread m_mainThread;

	static void process()
	{
		while (true) {
			for (std::list<std::string>::iterator iter = s_strings.begin(); iter != s_strings.end(); iter++)
			{
				std::cout << *iter << ", ";
			}
			std::cout << std::endl;
		}
	}
public:
	Test(std::string string = "a") : m_string(string) { s_strings.push_back(string); };
	
	void startProcess()
	{
		m_mainThread = std::thread(&process);
		m_mainThread.detach();
	}

};

std::list<std::string> Test::s_strings = std::list<std::string>();