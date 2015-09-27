#pragma once
#include "json/json.h"
#include "IJsonSerializable.hh"

class JsonSerializer
{
public:
	static bool Serialize(IJsonSerializable* pObj, std::string& output);
	static bool Deserialize(IJsonSerializable* pObj, std::string& input);
	static bool DeserializeComponent(IJsonSerializable* pObj, std::string& input, std::string& component);


private:
	JsonSerializer(void) {};
	JsonSerializer(const JsonSerializer &&) {};
	JsonSerializer(const JsonSerializer &) {};
	void operator=(const JsonSerializer &) {};
	void operator=(const JsonSerializer &&) {};
};
