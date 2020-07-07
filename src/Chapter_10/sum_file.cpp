
void test_sum_num() {
	auto file_name = std::string("sum.txt");
	{
		std::ofstream file(file_name);
		auto num_list = {1, 3, 5, 7, 9};
		for (auto num : num_list) {
			file << num << " ";
		}
	}
	std::ifstream file_in(file_name);
	char ch{'\0'};
	size_t sum{0};
	while (true) {
		if (!(file_in >> ch))
			break;
		if (ch == ' ')
			continue;
		sum += static_cast<int>(ch - '0');
	}
	std::cout << sum << std::endl;
}