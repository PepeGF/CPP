/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:27:04 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/11 17:32:41 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(MateriaSource const &src);
	MateriaSource &operator=(MateriaSource const &rhs);
	virtual ~MateriaSource();
	
	virtual void learnMateria(AMateria* src);
	virtual AMateria* createMateria(std::string const & type);
private:
	AMateria *_inventory[4];
};
