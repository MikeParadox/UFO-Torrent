#include "../includes/encode.h"

#include <stdexcept>
#include <sstream>

using namespace bencode;
using std::string;

/// <summary>
/// Class Encode Visitor is a visitor for encoding objects of various types according to the BitTorrent format.
/// </summary>
class EncodeVisitor : public boost::static_visitor<std::string>
{
public:
    string operator()(int value) const
    {
        return "i" + std::to_string(value) + "e";
    }

    string operator()(const string& value) const
    {
        if (value.empty()) throw std::invalid_argument("The line is empty");
        return std::to_string(value.length()) + ":" + value;
    }

    string operator()(const ValueDictionary& dict) const
    {
        std::stringstream stream;
        stream << "d";
        for (ValueDictionary::const_iterator i = dict.begin();
            i != dict.end(); ++i) {
            stream << (*this)(i->first)
                << boost::apply_visitor(EncodeVisitor(), i->second);
        }
        stream << "e";

        return stream.str();
    }

    string operator()(const ValueVector& vec) const
    {
        std::stringstream stream;
        stream << "l";
        for (ValueVector::const_iterator i = vec.begin(); i != vec.end(); ++i)
            stream << boost::apply_visitor(EncodeVisitor(), *i);
        stream << "e";

        return stream.str();
    }
};

/// <summary>
/// Method calls apply_visitor for the specified value and returns the encoding result.
/// </summary>
/// <param name="value ->">EncodeVisitor object for the specified value.</param>
/// <returns>Result of encoding.</returns>
string Encoder::encode(const Value& value)
{
    return boost::apply_visitor(EncodeVisitor(), value);
}
