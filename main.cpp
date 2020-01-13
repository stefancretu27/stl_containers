#include "sequence_containers.hpp"

int main()
{
	//sequence containers
	std::cout<<"----------------------------Array operations----------------------------"<<std::endl;
	array_operations();
	std::cout<<std::endl<<"----------------------------Vector operations----------------------------"<<std::endl;
	vector_operations();
	std::cout<<std::endl<<"----------------------------Double ended queue operations----------------------------"<<std::endl;
	deque_operations();
	std::cout<<std::endl<<"----------------------------Forward list operations----------------------------"<<std::endl;
	fwd_list_operations();
	std::cout<<std::endl<<"----------------------------List operations----------------------------"<<std::endl;
	list_operations();
	
	return 0;
}
