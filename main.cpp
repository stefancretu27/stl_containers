#include "sequence_containers.hpp"
#include "associative_containers.hpp"

//#define SEQUENCE_CONTAINERS
#define ASSOCIATIVE_CONTAINERS

int main()
{
#ifdef SEQUENCE_CONTAINERS
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
#endif

#ifdef ASSOCIATIVE_CONTAINERS
	std::cout<<"----------------------------Set operations----------------------------"<<std::endl;
	set_operations();
#endif	
	return 0;
}
