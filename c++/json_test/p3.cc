#include <iostream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
int main() {
	
	//create json object
	json object = {
		{"the good", "il buono"},
		{"the bad", "il cattivo"},
		{"the ugly", "il brutto"}
	};

	//output element with key "the ugly"
	std::cout << object.at("the ugly") << std::endl;
	// change element with key "the bad"
	std::cout << object.at("the bad") << std::endl;


	std::cout << object << '\n';
	std::cout << "\n\n\n error type\n";
	//excption type_erro.304
	try {
		//use at() on non-object type
		json str = "I am a string";
		str.at("the good") = "Another string";
	} catch(json::type_error &e) {
		std::cout << e.what() << '\n';
	}
	
	std::cout << "\n\ntry to write at a nonexisting key\n";
	//exception out_of_range.401
	try {
		// try to write at a nonexisting key
		object.at("the fast") = "il rapido";
	} catch(json::out_of_range &e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}

