/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:00:11 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/31 19:42:32 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replace(std::string lineRead,std::string s1, std::string s2)
{
	size_t	position;

    position = lineRead.find(s1);
    if (position == std::string::npos)
        return (lineRead);
    lineRead.erase(position, s1.length());
    lineRead.insert(position, s2);
	return (lineRead);
}

int main(int argc, char const *argv[])
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
	while (inputFile)
	{
		std::getline(inputFile, lineRead);
		outputFile << replace(lineRead, argv[2], argv[3]);
		if (lineRead != "")
			outputFile << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}