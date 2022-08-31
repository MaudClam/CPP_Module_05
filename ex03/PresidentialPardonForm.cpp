/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:51:26 by mclam             #+#    #+#             */
/*   Updated: 2022/08/15 20:51:26 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
AForm ("Presidential Pardon", 25, 5), _target( "notarget" ) {
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target) :
AForm ("Presidential Pardon", 25, 5), _target( target ) {
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &form ) : AForm(form) {
	*this = form;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const
												PresidentialPardonForm &form) {
	(void)form;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	this->beExecuted(executor);
	std::cout 	<< "[" << this->_target
				<< " has been pardoned by Zaphod Beeblebrox.]" << std::endl;
}
