#ifndef DECODE_H
#define DECODE_H

#include "valueTypes.h"



namespace bencode 
{

	class Decoder
	{

	public:

		friend struct Dr;

		friend struct Str;
		// ������������� ������
		static Value decode(const std::string& string);

	private:
		// ������ ����� � ������
		static std::string firstDigit(const std::string& str);

		// ������������� ������� ���� � ������
		static std::pair<unsigned long long, int> decodeInt(const std::string& s);

		// ������������� ������� ������� � ������
		static std::pair<std::string, int> decodestring(const std::string& s);

		// ������������� �����
		static std::pair<ValueVector, int> decodeList(const std::string& s);

		// ������������� �������
		static std::pair<ValueDictionary, int> decodeDict(const std::string& s);

		// ������������� ���� ������ ���������
		static std::pair<Value, int> _decode(const std::string& s);
	};
	struct Dr
	{
		std::pair<ValueVector, int> decodeLst(const std::string& s);
		Decoder decoder;
	};


	struct Str {
		std::pair<std::string, int> decodeStr(const std::string& s);
		Decoder decoder;
	};


}

#endif