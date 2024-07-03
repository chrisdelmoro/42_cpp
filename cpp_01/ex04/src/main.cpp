/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:00:11 by ccamargo          #+#    #+#             */
/*   Updated: 2023/11/02 19:48:28 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		outFileName;
	std::string		lineRead;

	if (argc != 4)
	{
		std::cout << "Program needs 3 arguments!" << std::endl;
        std::cout << "A text file as first argument." << std::endl;
        std::cout << "A string present on the file to be replaced." << std::endl;
        std::cout << "A string to replace the original one." << std::endl;
		return 1;
	}

	inputFile.open(argv[1], std::ios::in);
	if (!inputFile)
	{
		std::cout << "Error when opening file " << argv[1] << "." << std::endl;
		return 1;
	}

	outFileName.append(argv[1]);
	outFileName.append(".replace");
	outputFile.open(outFileName.c_str(), std::ios::out);
	if (!outputFile)
	{
		std::cout << "Error when creating file " << argv[1] << "." << std::endl;
		return 1;
	}

	size_t pos;
	size_t found;
	size_t s1_len = std::string(argv[2]).length();

	while (getline(inputFile, lineRead))
	{
		pos = 0;
		found = lineRead.find(argv[2]);
		while (found != std::string::npos)
		{
			outputFile << lineRead.substr(pos, found - pos) << argv[3];
			pos = found + s1_len;
			found = lineRead.find(argv[2], pos);
		}
		outputFile << lineRead.substr(pos);
		if (inputFile.eof() == false)
			outputFile << "\n";
	}

	inputFile.close();
	outputFile.close();
	return 0;
}