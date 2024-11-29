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
		// Декодирование строки
		static Value decode(const std::string& string);

	private:
		// первое число в строке
		static std::string firstDigit(const std::string& str);

		// Декодирования первого инта в строке
		static std::pair<unsigned long long, int> decodeInt(const std::string& s);

		// Декодирование первого стринга в строке
		static std::pair<std::string, int> decodestring(const std::string& s);

		// Декодирования листа
		static std::pair<ValueVector, int> decodeList(const std::string& s);

		// Декодирования словаря
		static std::pair<ValueDictionary, int> decodeDict(const std::string& s);

		// Декодирования всей строки рекурсией
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