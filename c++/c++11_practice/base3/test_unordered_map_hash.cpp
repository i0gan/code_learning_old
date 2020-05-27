#include <algorithm>
#include <iostream>
#include <unordered_map>

class Position {
	public:
		int x() const { return m_x; };
		int y() const { return m_y; };
		Position(int _x, int _y) : m_x(_x) , m_y(_y) { }
	private:
		int m_x = 0;
		int m_y = 0;
};

class Person {
	public:
		Person(int a, std::string n) : m_age{a}, m_name{std::move(n)} {}
		int age() const {return m_age; }
		const std::string &name() const { return m_name; }
		void print() const { std::cout << m_age << " : " << m_name << std::endl; }
		void changeAge(int newAge) { m_age = newAge; }
		bool operator == (Person const &rhs) const {
			return m_age == rhs.m_age && m_name == rhs.m_name;	
		}
	private:
		int m_age;
		std::string m_name;
};
void testUnoderedMap() {
	using Group = std::unordered_map<Position, Persion>;
	Group g;
}

int main(int, char**) {
	testUnoderedMap();
}
