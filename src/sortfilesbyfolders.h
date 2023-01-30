#pragma once
#include <filesystem>
#include <string_view>
#include <Windows.h>

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
    enum E_Colors
    {
        Black = 0,
        Grey = FOREGROUND_INTENSITY,
        LightGrey = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        Blue = FOREGROUND_BLUE,
        Green = FOREGROUND_GREEN,
        Cyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
        Red = FOREGROUND_RED,
        Purple = FOREGROUND_RED | FOREGROUND_BLUE,
        LightBlue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        LightGreen = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        LightCyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        LightRed = FOREGROUND_RED | FOREGROUND_INTENSITY,
        LightPurple = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        Orange = FOREGROUND_RED | FOREGROUND_GREEN,
        Yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    };
    static void unknownCommand(const char* executableName);
    static void usageCommand(const char* executableName);
    static void versionCommand(const char* executableName);
};

