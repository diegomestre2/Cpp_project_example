#include <fstream>
#include <iostream>
#include <string>

size_t get_file_size(std::ifstream &file) {
	file.seekg(0, std::ios::end); // places the cursor at the ending of the file
	auto length = file.tellg();   // stores the position at the ending of the file
	file.seekg(0, std::ios::beg); // places the cursos at the beggining of the file
	return length;                // return the size in bytes until the cursor position
}

void append_files(std::string &file1_name, std::string &file2_name) {
	std::ifstream file1{file1_name};
	std::ifstream file2{file2_name};

	auto f1_size = get_file_size(file1);
	auto f2_size = get_file_size(file2);

	auto buffer = std::unique_ptr<char[]>(new char[12]);
	std::ofstream file3{file1_name + file2_name};

	file1.read((char *)buffer.get(), f1_size);
	file2.read((char *)buffer.get() + f1_size, f2_size);
	file3.write((char *)buffer.get(), (f1_size + f2_size));
}

void test_file_append() {
	auto f1 = std::string("f1.txt");
	auto f2 = std::string("f2.txt");
	{
		std::ofstream output1{f1};
		std::ofstream output2{f2};
		auto list = {1, 2, 3, 4, 5};
		for (auto value : list) {
			output1 << value;
			output2 << (value + 5);
		}
	}
	append_files(f1, f2);
}