#pragma once
#include "valueTypes.h"

namespace bencode {

	class Decoder
	{
	public:
		// ������������� ������
		static Value decode(const std::string& string);

	private:
		// ������ ����� � ������
		static std::string firstDigit(const std::string& str);

		// ������������� ������� ���� � ������
		static std::pair<int, int> decodeInt(const std::string& s);

		// ������������� ������� ������� � ������
		static std::pair<std::string, int> decodeString(const std::string& s);

		// ������������� �����
		static std::pair<ValueVector, int> decodeList(const std::string& s);

		// ������������� �������
		static std::pair<ValueDictionary, int> decodeDict(const std::string& s);

		// ������������� ���� ������ ���������
		static std::pair<Value, int> _decode(const std::string& s);
	};
}