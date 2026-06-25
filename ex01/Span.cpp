/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:35:06 by opopov            #+#    #+#             */
/*   Updated: 2026/06/25 10:18:59 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	if (N == 0)
		throw std::out_of_range("size of container can't be 0");
	_N = N;
}

Span::Span(const Span &other) : _N(other._N), _container(other._container) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_container = other._container;
	}
	return *this;
}

Span::~Span() { }

void Span::addNumber(int value)
{
	if (_container.size() >= _N)
		throw std::length_error("container has reached maximum size");
	_container.push_back(value);
}

int Span::shortestSpan()
{
	if (_container.size() <= 1)
		throw std::logic_error("container doesn't has enough values to find shortest span");

	std::vector<int> tmp = _container;
	std::sort(tmp.begin(), tmp.end());
	long min_span = INT_MAX;
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		long diff = tmp[i] - tmp[i - 1];
		if (diff < min_span)
			min_span = diff;
	}

	return min_span;
}

int Span::longestSpan()
{
	if (_container.size() <= 1)
		throw std::logic_error("container doesn't has enough values to find longest span");

	long min = *std::min_element(_container.begin(), _container.end());
	long max = *std::max_element(_container.begin(), _container.end());
	long res = max - min;

	return res;
}
