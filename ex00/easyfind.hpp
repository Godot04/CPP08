/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:04:04 by opopov            #+#    #+#             */
/*   Updated: 2026/06/23 15:25:23 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <algorithm>
# include <stdexcept>

# define GRN "\033[32m"
# define PRPL "\033[35m"
# define RST "\033[0m"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::out_of_range("Value is not inside of this container");
	return it;
}
