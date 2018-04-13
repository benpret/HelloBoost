// HelloBoost.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void check_path(const char* p)
{
	path myPath(p);

	if (exists(myPath))
	{
		if (is_regular_file(myPath))
		{
			cout << "path " <<
				myPath.filename().replace_extension()
				<< " is a regular file of size " <<
				file_size(myPath) << endl;
		}
		else if (is_directory(myPath))
		{
			cout << "path " << myPath.filename() <<
				" is a directory" << endl;

		}
	}
	else {
		cout << "path " << myPath << " does not exist"
			<< endl;
	}
}


void check_file(path p)
{
	auto s = status(p);
	auto t = s.type();

	cout << "the type is " << t << endl;

	auto ps = s.permissions();

	if ((ps & owner_write) != owner_write)
	{
		cout << "no permission to write" << endl;
	}
}

void dir_nav(path& dir)
{
	
	directory_iterator end;
	for (directory_iterator i(dir); i != end; ++i)
	{
		path p = i->path();

		//find1K(p);

		if (is_regular_file(p))
		{
			auto myExt = string{};
			
			if (p.extension() == ".jpg")
			{
				//Assigns texture filename to String
				auto texture = string{};
				texture = p.filename().string();				
				//Creates regex search pattern
				auto r = regex { R"(\_4K\_)"}; 
				//Not sure yet what this is for
				auto m = smatch{};
				//Runs the regex search and prints when a match is found
				if (regex_search(texture, m, r))
				{
					cout << p.filename() << " - " << "4K Texture found" << endl;
				}
				else {
					cout << p.filename() << endl;
				}
				
				/*
				if (CopyFile((_T("E:\\MegascansTesting\\Brickwall_New_sc1tdbip\\Poes.txt")),
					(_T("E:\\MegascansTesting\\Brickwall_New_sc1tdbip\\Poes2.txt")),
					0))
				*/				
			}
		}
		else if (is_directory(p))
		{
			cout << "=================================================================" << endl 
				<< "Directory: " << p.filename() << endl
				<<	"=================================================================" << endl;
			dir_nav(p);
		}
	}
}


void createCopy(path p)
{

}

void list_all(path& dir)
{
	cout << "List All function called for " << dir << " successfully" << endl;
}

bool find1K(path dir)
{
	return false;
}

int main(int argc, char* argv[])
{
	//directory navigation
	auto parent = path("E:\\MegascansTesting");
	auto ScansDir = path("E:\\MegascansTesting");

    dir_nav(ScansDir);
	//list_all(ScansDir);

	//exits program
	getchar();
    return 0;
}

