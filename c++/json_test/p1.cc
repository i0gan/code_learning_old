#include <iostream>
#include "nlohmann/json.hpp"
#include <iomanip>
using json = nlohmann::json;

int main(void) {
	json j = {
		{"pi", 3.141},
		{"happy", true},
		{"name", "I0gan"},
		{"nothing", nullptr},

		{
			"answer", {
				{"everything", 42}
			}
		},

		{"list", {1, 0, 2}},

		{
			"object", {
				{"currentcy", "USD"},
				{"value", 42.99}
			}
		}

	};
		
	//add new values
	j["new"]["key"]["value"] = {"another", "list"};
	//count elements
	auto s = j.size();
	j["size"] = s;

	//pretty print with indent of 4 spaces
	std::cout << std::setw(4) << j << "\n";

	return 0;
}
