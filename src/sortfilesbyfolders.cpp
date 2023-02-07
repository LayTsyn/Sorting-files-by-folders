
#define _CRT_SECURE_NO_WARNINGS
#include "sortfilesbyfolders.h"
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

int sortfilesbyfolders::menuCallBack(int argc, char** argv)
{
	try
	{
		if (argc == 2 && (!strcmp(sortfilesbyfolders::helpOption, argv[1]) || !strcmp(sortfilesbyfolders::hOption, argv[1])))
			sortfilesbyfolders::usageCommand(argv[0]);
		else if (argc == 2 && ((!strcmp(sortfilesbyfolders::versionOption, argv[1]) || !strcmp(sortfilesbyfolders::vOption, argv[1]))))
			sortfilesbyfolders::versionCommand(argv[0]);
		else if (argc == 3 && (!strcmp(sortfilesbyfolders::extensionOption, argv[1]) || !strcmp(sortfilesbyfolders::eOption, argv[1])))
			sortfilesbyfolders::sortFilesByFolders(sortfilesbyfolders::E_CategorySort::extension, argv[2]);
		else if (argc == 3 && (!strcmp(sortfilesbyfolders::dateOption, argv[1]) || !strcmp(sortfilesbyfolders::dOption, argv[1])))
			sortfilesbyfolders::sortFilesByFolders(sortfilesbyfolders::E_CategorySort::date, argv[2]);
		else
			sortfilesbyfolders::unknownCommand(argv[0]);
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return -1;
	}
	return 0;
}

bool sortfilesbyfolders::sortFilesByFolders(E_CategorySort categorySort, std::string_view pathToDirectory)
{
	std::string typeSort, newPath;
	std::filesystem::path pthOld, pthNew;
	if (std::filesystem::exists((pathToDirectory)))
	{
		for (const auto& file : std::filesystem::directory_iterator(pathToDirectory))
		{
			if (file.status().type() == std::filesystem::file_type::regular)
			{
				switch (categorySort)
				{
				case sortfilesbyfolders::E_CategorySort::extension:
				{
					typeSort = file.path().extension().string();
					break;
				}
				case sortfilesbyfolders::E_CategorySort::date:
				{
					typeSort = sortfilesbyfolders::getDateFile(file.last_write_time());
					break;
				}
				}
				pthOld = file.path();
				pthNew = file.path().parent_path().string() + "/" + typeSort + "/";
				pthNew.make_preferred();
				std::filesystem::create_directory(pthNew);
				pthNew += file.path().filename().string();
				pthNew.make_preferred();
				std::filesystem::rename(pthOld, pthNew);
			}
		}
	}
	return false;
}

std::string_view sortfilesbyfolders::getExtensionFile(std::string_view fileName)
{
	if (std::string::npos == fileName.rfind("."))
		return "";
	return fileName.substr(fileName.rfind("."));
}

std::string sortfilesbyfolders::getDateFile(const std::filesystem::file_time_type& file_time)
{
	std::time_t tt = to_time_t(file_time);
	std::tm* gmt = std::gmtime(&tt);
	std::stringstream buffer;
	buffer << std::put_time(gmt, "%Y_%B_%d");
	std::string formattedFileTime = buffer.str();
	return formattedFileTime;
}

template<typename TP>
inline std::time_t sortfilesbyfolders::to_time_t(TP tp)
{
	auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(tp - TP::clock::now()
		+ std::chrono::system_clock::now());
	return std::chrono::system_clock::to_time_t(sctp);
};


void sortfilesbyfolders::unknownCommand(const char* executableName)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), sortfilesbyfolders::E_Colors::LightRed);
	std::cout << "Unknown command. Use ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f); 
	std::cout << "--help";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), sortfilesbyfolders::E_Colors::LightRed);
	std::cout << " for more information" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);

}

void sortfilesbyfolders::usageCommand(const char* executableName)
{
	std::streamsize oOption = 4, oneOption = 16, informationOption = 80;
	std::cout << "Usage: " << executableName << " [options] path-to-files" << std::endl
		<< "Options:" << std::endl
		<< std::setw(oOption) << std::right << sortfilesbyfolders::hOption << " | " << std::setw(oneOption) << std::left << sortfilesbyfolders::helpOption
		<< std::setw(informationOption) << std::left << "Display this information" << std::endl

		<< std::setw(oOption) << std::right << sortfilesbyfolders::eOption << " | " << std::setw(oneOption) << std::left << sortfilesbyfolders::extensionOption
		<< std::setw(informationOption) << std::left << "Sorting files by folders in the path directory by their extension." << std::endl

		<< std::setw(oOption) << std::right << sortfilesbyfolders::dOption << " | " << std::setw(oneOption) << std::left << sortfilesbyfolders::dateOption
		<< std::setw(informationOption) << std::left << "Sort files by folders in the path directory by their date(Year_Month_Day)." << std::endl
		
		<< std::endl << "For bug reporting: \n<https://github.com/LayTsyn/Sorting-files-by-folders>.\n" << std::endl;
};

void sortfilesbyfolders::versionCommand(const char* executableName)
{
	std::cout << executableName << " 30.1.23\nThis is free software. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n" << std::endl;
}

const char * sortfilesbyfolders::versionOption = "--version", * sortfilesbyfolders::vOption = "-v";
const char * sortfilesbyfolders::extensionOption = "--extension", * sortfilesbyfolders::eOption = "-e";
const char * sortfilesbyfolders::dateOption = "--date", * sortfilesbyfolders::dOption = "-d";
const char * sortfilesbyfolders::helpOption = "--help", * sortfilesbyfolders::hOption = "-h";