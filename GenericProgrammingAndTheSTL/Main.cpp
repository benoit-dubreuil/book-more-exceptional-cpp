#include <iostream>
#include <iterator>
#include <vector>

#include "RemoveNth.h"
#include "IsDerivedFrom.h"

struct Parent {};
struct Child : public Parent {};
struct Orphan {};

int main()
{
	using ContainerType = std::vector<int>;
	ContainerType data = { 1, 2, 3, 2, 3, 1, 1, 3, 3, 2, 1, 1 };

	std::copy(data.begin(), data.end(), std::ostream_iterator<ContainerType::value_type>(std::cout, " "));
	std::cout << std::endl;

	ContainerType::iterator removedBegin = removeNth(data.begin(), data.end(), 3);
	data.resize(std::distance(data.begin(), removedBegin));

	std::copy(data.begin(), data.end(), std::ostream_iterator<ContainerType::value_type>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "Is Child derived from Parent : " << std::boolalpha << static_cast<bool>(IsDerivedFrom<Child, Parent>::Is) << std::endl;
	std::cout << "Is Orphan derived from Parent : " << static_cast<bool>(IsDerivedFrom<Orphan, Parent>::Is) << std::noboolalpha << std::endl;

	return 0;
}