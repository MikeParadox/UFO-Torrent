#ifndef DECODE_H
#define DECODE_H

#include "valueTypes.h"

<<<<<<< HEAD


namespace bencode 
{

	class Decoder
	{

	public:

		friend struct Dr;
=======
namespace bencode {

	class Decoder
	{
	public:
>>>>>>> parent of f88e419 (Tests, implementation of decoding the first element in a string of type string)
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
<<<<<<< HEAD
	struct Dr
	{
		std::pair<ValueVector, int> decodeLst(const std::string& s);
		Decoder decoder;
	};


=======
>>>>>>> parent of f88e419 (Tests, implementation of decoding the first element in a string of type string)
}

#endif