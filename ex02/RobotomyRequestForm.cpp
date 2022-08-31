/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:18:51 by mclam             #+#    #+#             */
/*   Updated: 2022/08/15 21:18:51 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) :
AForm ("Robotomy Request Form", 25, 5), _target( "notarget" ) {
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target) :
AForm ("Robotomy Request Form", 25, 5), _target( target ) {
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &form ) : AForm(form) {
	*this = form;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const
													RobotomyRequestForm &form) {
	(void)form;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	int	robotomized;
	
	this->beExecuted(executor);
	std::cout << "\n[drillingdrillingdrillingdrillingdrilling]" << std::endl;
	robotomized = std::rand() % 2;
	if (robotomized)
		std::cout << this->_target << " was robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomizing failed." << std::endl;
}
