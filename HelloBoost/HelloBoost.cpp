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

		if (is_regular_file(p))
			cout << p.filename() << endl;
		else if (is_directory(p))
		{
			cout << "================================" << endl 
				<< "Directory: " << p.filename() << endl
				<<	"================================" << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	//Check Paths
	check_path("foo");
	check_path(argv[0]);

	auto dir = path(argv[0]).parent_path();
	check_path(dir.string().c_str());


	// decomposition (Break file names down to individual elements
	for (auto& child : dir)
	{
		cout << child << endl;
	}

	// check if if a file exists
	try {
		path p("E:\\Test\\Bricks_Debris_rieq0\\Aset_bricks_debris_S_rieq0_2K_Displacement.jpg");
		cout << p.filename() << " is " << file_size(p) << "kb" << endl;
	}
	catch (const filesystem_error& e)
	{
		cout << e.what() << endl;
	}

	//check status of a file
	check_file(path(argv[0]));

	//directory navigation
	auto parent = path("E:\\Test\\Bricks_Debris_rieq0\\");

	dir_nav(parent);

	//exits program
	getchar();
    return 0;
}

