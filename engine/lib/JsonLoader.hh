#pragma once

#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include "JsonSerializer.hh"

class JsonLoader
{
public:
	std::string filedata;
	std::string ifilename;
	std::string ofilename;

	JsonLoader(const std::string& file){
		filedata = "";
		ifilename = file;
		ofilename = file;
	};

	/* supposed to be the more efficient (speed wise)than iostream or assign*/
	bool LoadFileFrom(const std::string& file)
	{

		std::ifstream filestream(file);
		if (filestream)
		{
			filedata = "";
			ifilename = file;
			filestream.seekg(0, std::ios::end);
			filedata.resize(filestream.tellg());
			filestream.seekg(0, std::ios::beg);
			filestream.read(&filedata[0], filedata.size());
			filestream.close();
			return (true);
		}
		return (false);
	};

	bool LoadFile()
	{
		std::ifstream filestream(ifilename);
		if (filestream)
		{
			filedata = "";
			filestream.seekg(0, std::ios::end);
			filedata.resize(filestream.tellg());
			filestream.seekg(0, std::ios::beg);
			filestream.read(&filedata[0], filedata.size());
			filestream.close();
			return (true);
		}
		return (false);
	};

	void showContent() { std::cout << filedata << std::endl; };
	/* set & get the content of the file loaded*/
	std::string & getContent() { return (filedata); };
	void  setContent(const std::string & data) { filedata = data; };
	/* set input output file name*/
	void setOutput(const std::string & file) { ofilename = file; }; //by default the one from the creation
	void setInput(const std::string & file) { ifilename = file; }; //by default the one from the creation

	bool loadObject(IJsonSerializable* pObj)
	{
		return JsonSerializer::Deserialize(pObj, filedata);
	};

	bool loadComponent(IJsonSerializable* pObj, std::string& component)
	{
		return JsonSerializer::DeserializeComponent(pObj, filedata, component);
	};

	bool saveObject(IJsonSerializable* pObj, bool append)
	{
		std::string output;
		if (!JsonSerializer::Serialize(pObj, output))
			return (false);
		std::ofstream filestream;
		if (append)
			filestream.open(ofilename, std::ios::out | std::ios::app);
		else
			filestream.open(ofilename, std::ios::out);
		if (!filestream.is_open())
			return (false);
		filestream.write(&output[0], output.size());
		filestream.close();
		return (true);
	};

	bool saveObjectTo(IJsonSerializable* pObj, std::string & file , bool append)
	{
		std::string output;
		if (!JsonSerializer::Serialize(pObj, output))
			return (false);
		std::ofstream filestream;
		if (append)
			filestream.open(file, std::ios::out | std::ios::app);
		else
			filestream.open(file, std::ios::out);
		if (!filestream.is_open())
			return (false);
		ofilename = file;
		filestream.write(&output[0], output.size());
		filestream.close();
		return (true);
	};

private:
	JsonLoader(void) {};
	JsonLoader(const JsonLoader &&) {};
	JsonLoader(const JsonLoader &) {};
	void operator=(const JsonLoader &) {};
	void operator=(const JsonLoader &&) {};
};
