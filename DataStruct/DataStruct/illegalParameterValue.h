#pragma once
#include <string>
#include <iostream>

class illegalParameterValue {
public:
	illegalParameterValue() : message_("IllegalParameterValue") { }
	illegalParameterValue(char* theMessage) { message_ = theMessage; }
	void output_message() { std::cout << message_ << std::endl; }
private:
	std::string message_;
};