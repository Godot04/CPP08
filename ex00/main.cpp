/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:03:40 by opopov            #+#    #+#             */
/*   Updated: 2026/06/23 15:31:12 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	// Test with vector container
	std::cout << GRN << "Test with vector container" << RST << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 3; i++)
		v.push_back(i);
	std::cout << PRPL << "Right value test" << RST << std::endl;
	try
	{
		easyfind(v, 1);
		std::cout << "Value was found!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << PRPL << "Wrong value test" << RST << std::endl;
	try
	{
		easyfind(v, 123);
		std::cout << "Value was found!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;

	// Test with list container
	std::cout << GRN << "Test with list container" << RST << std::endl;
	std::list<int> l;
	for (int i = 0; i < 3; i++)
		l.push_back(i);
	std::cout << PRPL << "Right value test" << RST << std::endl;
	try
	{
		easyfind(l, 1);
		std::cout << "Value was found!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << PRPL << "Wrong value test" << RST << std::endl;
	try
	{
		easyfind(l, 123);
		std::cout << "Value was found!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
