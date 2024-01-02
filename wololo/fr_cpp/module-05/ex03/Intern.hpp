/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:00:24 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/14 19:09:19 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Form.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &src);
	Intern &operator=(Intern const &rhs);
	~Intern();
	
	Form *makeForm(std::string name, std::string const target);
};
