#include "../includes/prettyPrinter.h"

#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/static_visitor.hpp>
#include <boost/variant/variant.hpp>

#include <iostream>

using namespace bencode;

/// <summary>
/// Constructor of the Pretty Printer class takes the indentation value and stores it in the indentation_ field.
/// </summary>
/// <param name="indentation ->">Private field indentation_</param>
PrettyPrinter::PrettyPrinter(int indentation) : indentation_(indentation)
{
}

/// <summary>
/// The method returns the indentation_ value.
/// </summary>
/// <returns>indentation_ value.</returns>
int PrettyPrinter::getIndentation() const
{
    return indentation_;
}

/// <summary>
/// Method creates a string with spaces in the amount equal to twice the indentation value.
/// </summary>
/// <returns>String with spaces in the amount equal to twice the indentation value.</returns>
std::string PrettyPrinter::getSpace() const
{
    return std::string(getIndentation() * 2, ' ');
}

/// <summary>
/// Method checks whether an ASCii character is a character. 
/// </summary>
/// <param name="c ->">Char.</param>
/// <returns>Returns true if the character belongs to the range 9-13 or 32-126.</returns>
bool PrettyPrinter::isAscii(int c) const
{
    return (c >= 9 && c <= 13) || (c >= 32 && c <= 126);
}

/// <summary>
/// The method checks whether all characters in the value string are ASCii characters.
/// </summary>
/// <param name="value">Value string.</param>
/// <returns>Returns true if all characters in the value string belong to the ASCii character range.</returns>
bool PrettyPrinter::isAscii(const std::string& value) const
{
    for (unsigned int i = 0; i < value.size(); i++)
        if (!isAscii(static_cast<int>(value[i])))
            return false;

    return true;
}

/// <summary>
/// Accepts an integer value and displays it on the screen with the addition of a newline character.
/// </summary>
/// <param name="t ->">Integer value.</param>
void PrettyPrinter::operator()(int t) const
{
    std::cout << t << std::endl;
}

/// <summary>
/// Accepts and processes a string for ASCII characters.
/// </summary>
/// <param name="t">String.</param>
void PrettyPrinter::operator()(const std::string& t) const
{
    if (!isAscii(t))
        std::cout << "BINARY DATA (length: " << t.size() << ")" << std::endl;
    else {
        const int MAX_string_LENGTH = 100;
        std::cout << t.substr(0, MAX_string_LENGTH) << std::endl;
    }
}

/// <summary>
/// Processes a dictionary of values and processes key values using the Pretty Printer object.
/// </summary>
/// <param name="t ->">Dictionary.</param>
void PrettyPrinter::operator()(const ValueDictionary& t) const
{
    std::cout << std::endl;
    for (ValueDictionary::const_iterator i = t.begin(); i != t.end(); ++i) {
        std::cout << getSpace() << "{" << i->first << "}: ";
        boost::apply_visitor(PrettyPrinter(getIndentation() + 1), i->second);
    }
}

/// <summary>
/// Processes a vector of values and processes index values using the Pretty Printer object.
/// </summary>
/// <param name="t">Vector of values.</param>
void PrettyPrinter::operator()(const ValueVector& t) const
{
    std::cout << std::endl;
    for (unsigned int i = 0; i != t.size(); ++i) {
        std::cout << getSpace() << "[" << i << "]: ";
        boost::apply_visitor(PrettyPrinter(getIndentation() + 1), t[i]);
    }
}
