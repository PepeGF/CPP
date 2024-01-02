/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:44:18 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/10 12:46:30 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain
{
public:
	Brain();
	Brain(Brain const &src);
	Brain &operator=(Brain const &rhs);
	~Brain();
private:
	std::string ideas[100];
};
