// HelloBoost.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Global Variablesve
vector<bool> texSizes = { false, false, false, false, false };
vector<string> texNames = {};


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

bool check512(path p)
{
	//Assigns texture filename to String
	auto texture = string{};
	texture = p.filename().string();
	//Creates regex search pattern
	auto r = regex{ R"(\_512\_)" };
	//Not sure yet what this is for
	auto m = smatch{};
	//Runs the regex search and prints when a match is found
	if (regex_search(texture, m, r))
	{
		texSizes[0] = true;
		cout << p.filename() << " - " << "512px Texture found" << endl;
		return true;
	} else {
		return false;
	}

}

bool check1K(path p)
{
	//Assigns texture filename to String
	auto texture = string{};
	texture = p.filename().string();
	//Creates regex search pattern
	auto r = regex{ R"(\_1K\_)" };
	//Not sure yet what this is for
	auto m = smatch{};
	//Runs the regex search and prints when a match is found
	if (regex_search(texture, m, r))
	{
		texSizes[1] = true;
		cout << p.filename() << " - " << "1K Texture found" << endl;
		return true;
	}
	else {
		return false;
	}
}

bool check2K(path p)
{
	//Assigns texture filename to String
	auto texture = string{};
	texture = p.filename().string();
	//Creates regex search pattern
	auto r = regex{ R"(\_2K\_)" };
	//Not sure yet what this is for
	auto m = smatch{};
	//Runs the regex search and prints when a match is found
	if (regex_search(texture, m, r))
	{
		texSizes[2] = true;
		cout << p.filename() << " - " << "2K Texture found" << endl;
		return true;
	}
	else {
		return false;
	}
}

bool check4K(path p)
{
	//Assigns texture filename to String
	auto texture = string{};
	texture = p.filename().string();
	//Creates regex search pattern
	auto r = regex{ R"(\_4K\_)" };
	//Not sure yet what this is for
	auto m = smatch{};
	//Runs the regex search and prints when a match is found
	if (regex_search(texture, m, r))
	{
		texSizes[3] = true;
		cout << p.filename() << " - " << "4K Texture found" << endl;
		return true;
	}
	else {
		return false;
	}
}

bool check8K(path p)
{
	//Assigns texture filename to String
	auto texture = string{};
	texture = p.filename().string();
	//Creates regex search pattern
	auto r = regex{ R"(\_8K\_)" };
	//Not sure yet what this is for
	auto m = smatch{};
	//Runs the regex search and prints when a match is found
	if (regex_search(texture, m, r))
	{
		texSizes[4] = true;
		cout << p.filename() << " - " << "8K Texture found" << endl;
		return true;
	}
	else {
		return false;
	}
}

void createMissingTextures() {
	//Get highest texture resolution and assign the index to an int
	int highres = 0;
	for (int x = 0; x < texSizes.size(); x++) {
		if (texSizes[x] == true) {
			highres = x;
		}
	}

	//Search through all the texture names in the current directory 
	//look for the highest resolution and create copies of ONLY the missing resolutions.
	for (int i = 0; i < texNames.size(); i++)	{
		auto newTexName = string{};
		//Not sure yet what this is for
		auto m = smatch{};

		//Creates an initial regex search pattern
		auto r = regex{};
		switch (highres) {			
		case 1: r = regex{ R"(\_1K\_)" };
				// create 512 res if it does not exist yet.
				if (texSizes[0] = false) {
					//Runs the regex search and copies
					if (regex_search(texNames[i], m, r))
					{
						auto x = texNames[i].find("_1K_");						
						newTexName.replace(x, 4, "_512_");
						cout << "I am going to create " << newTexName << endl;
					}
				}
				break;
		case 2: r = regex{ R"(\_2K\_)" };
				// create 512 res
				if (texSizes[0] == false) {

					//Runs the regex search and copies
					if (regex_search(texNames[i], m, r))
					{
						auto x = texNames[i].find("_2K_");
						newTexName.replace(x, 4, "_512_");
						cout << "I am going to create " << newTexName << endl;
					}
				}
				// create 1K res
				if (texSizes[1] == false) {
					//Runs the regex search and copies
					if (regex_search(texNames[i], m, r))
					{
						auto x = texNames[i].find("_2K_");
						newTexName.replace(x, 4, "_1K_");
						cout << "I am going to create " << newTexName << endl;
					}
				}
				break;
		case 3: r = regex{ R"(\_4K\_)" };
				// create 512 res
				if (texSizes[0] == false) {

				}
				// create 1K res
				if (texSizes[1] == false) {

				}
				// create 2K res
				if (texSizes[2] == false) {

				}
				break;
		case 4: r = regex{ R"(\_8K\_)" };
				// create 512 res
				if (texSizes[0] == false) {

				}
				// create 1K res
				if (texSizes[1] == false) {

				}
				// create 2K res
				if (texSizes[2] == false) {

				}
				// create 4K res
				if (texSizes[3] == false) {

				}
				break;
		}	
		
		/*
		if (CopyFile((_T("E:\\MegascansTesting\\Brickwall_New_sc1tdbip\\Poes.txt")),
		(_T("E:\\MegascansTesting\\Brickwall_New_sc1tdbip\\Poes2.txt")),
		0))
		*/
	}
}

void dir_nav(path& dir)
{
	directory_iterator end;
	for (directory_iterator i(dir); i != end; ++i)
	{
		path p = i->path();

		if (is_regular_file(p))
		{			
			if (p.extension() == ".jpg")
			{
				if (check512(p)){}
				else if (check1K(p)) {}
				else if (check2K(p)) {}
				else if (check4K(p)) {}
				else if (check8K(p)) {}
				else {
					cout << p.filename() << endl;
				}
				
				texNames.push_back(p.string());
							
			}
		}
		else if (is_directory(p))
		{
			//If this is the first iteration through a folder? If yes then don't print anything else print all the resolutions find in previous folder.
			if (texSizes[0] == false and texSizes[1] == false and texSizes[2] == false and texSizes[3] == false and texSizes[4] == false)
			{

			}
			else {
				cout << endl << "Found 512px Textures -- Found 1K Textures -- Found 2K Textures -- Found 4K Textures -- Found 8K Textures" << endl
					<< "          " << texSizes[0] <<
					"                     " << texSizes[1] <<
					"                    " << texSizes[2] <<
					"                    " << texSizes[3] <<
					"                    " << texSizes[4] <<
					"                    " << endl;

				createMissingTextures();
			}

			cout << "========================================================================================================" << endl
				<< "Directory: " << p.filename() << endl
				<< "=========================================================================================================" << endl;

			texSizes = { false, false, false, false, false };
			texNames.clear();
			dir_nav(p);
		}		
	}
}



int main(int argc, char* argv[])
{
	//directory navigation
	try {
		auto ScansDir = path("D:\\MegascansTesting");
		dir_nav(ScansDir);
	}
	catch (const std::exception& e) {
		cout << e.what();
	}

	//exits program
	getchar();
    return 0;
}

