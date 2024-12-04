#include "fileUtils.h"

/// <summary>
/// The method outputs the file size at the specified path to it.
/// </summary>
/// <param name="filePath">Path to the desired file.</param>
/// <returns>The size of the found file in bytes</returns>
unsigned long long File::getFileSize(const std::string& filePath) {
	std::ifstream file(filePath, std::ios::binary | std::ios::ate);
	if (!file.is_open())
		throw std::runtime_error("Не удалось открыть файл: " + filePath);

	return file.tellg(); 
}

/// <summary>
/// The method opens the file at the specified path in binary mode and writes binaryContent to it.
/// </summary>
/// <param name="filePath">Path to the desired file.</param>
/// <param name="binaryContent">Desired content.</param>
void File::createFile(const std::string& filePath, const std::string& binaryContent) {
	std::ofstream outFile(filePath, std::ios::binary);

	if (!outFile)
		throw std::runtime_error("Failed to open file: " + filePath);

	outFile.write(binaryContent.c_str(), binaryContent.size());

	if (!outFile)
		throw std::runtime_error("Failed to write data to file: " + filePath);

	outFile.close();
}

/// <summary>
/// The method opens a file with the specified path and reads its content as a string.
/// </summary>
/// <param name="filePath">Path to the desired file.</param>
/// <returns>Content given file.</returns>
string File::read(const std::string& filePath) {
	std::ifstream inputFile(filePath);
	if (!inputFile.is_open())
		throw std::runtime_error("Failed to open file: " + filePath);


	std::string content((std::istreambuf_iterator<char>(inputFile)),
		std::istreambuf_iterator<char>());

	inputFile.close();


	return content;
}
