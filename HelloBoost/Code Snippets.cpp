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