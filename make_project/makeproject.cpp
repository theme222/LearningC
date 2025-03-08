#include <iostream>
#include <filesystem> // For C++17 and above
#include <fstream>    // For file copying
#include <cstdlib>    // For system calls
#include <string>

namespace fs = std::filesystem;
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Please provide project name\n";
        return 0;
    }
    
    fs::path project_dir = argv[1];
    if (fs::create_directory(project_dir))
    {
        cout << "Directory created: " << project_dir << endl;
    }
    else
    {
        cerr << "Failed to create directory or it already exsits.\n";
    }

    // Define the source and destination paths for main.cpp and run.sh
    fs::path source_main = "main.cpp";
    fs::path source_run = "run.sh";
    fs::path dest_main = project_dir / "main.cpp";
    fs::path dest_run = project_dir / "run.sh";

    // Copy main.cpp
    if (fs::exists(source_main))
    {
        fs::copy(source_main, dest_main);
        std::cout << "Copied main.cpp to " << dest_main << std::endl;
    }
    else
    {
        std::cerr << "main.cpp does not exist." << std::endl;
    }

    // Copy run.sh
    if (fs::exists(source_run))
    {
        fs::copy(source_run, dest_run);
        std::cout << "Copied run.sh to " << dest_run << std::endl;
    }
    else
    {
        std::cerr << "run.sh does not exist." << std::endl;
    }

    return 0;
}