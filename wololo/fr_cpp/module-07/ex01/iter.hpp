/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:03:28 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/17 16:18:08 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T, typename S, typename F>
void	iter(T *addr, S size, F (*func)(T&))
{
	for (int i = 0; i < size; i++)
		func(addr[i]);
}
