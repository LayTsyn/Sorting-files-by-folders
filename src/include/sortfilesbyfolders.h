#pragma once
#include <filesystem>
#include <string_view> 

class sortfilesbyfolders
{
public:
	static int menuCallBack(int argc, char** argv);
	enum E_CategorySort { extension, date };
	static bool sortFilesByFolders(E_CategorySort categorySort, std::string_view pathToDirectory);
private:
	static std::string_view getExtensionFile(std::string_view pathToDirectory);
	static std::string getDateFile(const std::filesystem::file_time_type& file_time);
	template <typename TP>static std::time_t to_time_t(TP tp);
    static const char * helpOption, * hOption;
    static const char * versionOption, * vOption;
    static const char * extensionOption, * eOption;
    static const char * dateOption, * dOption; 
    static void unknownCommand(const char* executableName);
    static void usageCommand(const char* executableName);
    static void versionCommand(const char* executableName);
};

