/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:34:59 by opopov            #+#    #+#             */
/*   Updated: 2026/06/24 13:49:23 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <vector>
# include <stdexcept>
# include <cstdlib>
# include <ctime>
# include <algorithm>
# include <climits>

# define GRN "\033[32m"
# define PRPL "\033[35m"
# define RST "\033[0m"

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _container;

	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int value);
		int shortestSpan();
		int longestSpan();

		template <typename it>
		void add_iterators(it begin, it end)
		{
			if ((std::distance(begin, end) + _container.size()) > _N)
				throw std::out_of_range("Too many elements for container");

			for (it i = begin; i != end; i++)
				_container.push_back(*i);
		}
};
