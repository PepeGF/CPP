/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:00:21 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/14 19:07:34 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name, std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);	
	virtual ~PresidentialPardonForm();

	void	execute(Bureaucrat const &executor) const;
	void	execAction() const;
	
	void	beSigned(Bureaucrat const &obj);
};
