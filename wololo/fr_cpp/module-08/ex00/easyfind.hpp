/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:42:39 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/18 13:47:35 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template<typename T>
bool	easyfind(T array, int nb)
{
	typename T::iterator it = find(array.begin(), array.end(), nb);
	if (it == array.end())
		return false;
	return true;
}
