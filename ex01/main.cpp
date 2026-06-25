/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:49:49 by opopov            #+#    #+#             */
/*   Updated: 2026/06/25 10:28:03 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

int main()
{
	// Test from exercise
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// My tests
	// Overflow exception
	std::cout << GRN << "Overflow exception" << RST << std::endl;
	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Iterator overflow exception
	std::cout << GRN << "Iterator overflow exception" << RST << std::endl;
	try
	{
		Span sp(2);
		std::vector<int> v;
		for (int i = 0; i < 10; i++)
			v.push_back(i);
		sp.add_iterators(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Not enough elements for shortestSpan exception
	std::cout << GRN << "Not enough elements for shortestSpan exception" << RST << std::endl;
	try
	{
		Span sp(3);
		sp.addNumber(2);
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Not enough elements for longestSpan exception
	std::cout << GRN << "Not enough elements for longestSpan exception" << RST << std::endl;
	try
	{
		Span sp(3);
		sp.addNumber(2);
		sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test with vector
	std::cout << GRN << "Test with vector" << RST << std::endl;
	{
		Span sp(20);
		std::vector<int> v;
		for (int i = 0; i < 20; i++)
			v.push_back(i);
		sp.add_iterators(v.begin(), v.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test with list
	std::cout << GRN << "Test with list" << RST << std::endl;
	{
		Span sp(10);
		std::list<int> l;
		for (int i = 0; i < 10; i++)
			l.push_back(i);
		sp.add_iterators(l.begin(), l.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test with large numbers
	std::cout << GRN << "Test with large numbers" << RST << std::endl;
	{
		srand(time(NULL));
		Span sp(42000);
		for (int i = 0; i < 42000; i++)
			sp.addNumber(rand());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test with duplicates
	std::cout << GRN << "Test with duplicates" << RST << std::endl;
	{
		Span sp(3);
		for (int i = 0; i < 3; i++)
			sp.addNumber(2);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test with negative numbers
	std::cout << GRN << "Test with negative numbers" << RST << std::endl;
	{
		Span sp(5);
		sp.addNumber(-5);
		sp.addNumber(-1);
		sp.addNumber(-10);
		sp.addNumber(10);
		sp.addNumber(25);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	return 0;
}
