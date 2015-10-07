#pragma once

class IJsonSerializable
{
public:
	virtual ~IJsonSerializable(void) {};
	virtual void Serialize(Json::Value& root) {};
	virtual void Deserialize(Json::Value& root) {};
};