/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:24:58 by mclam             #+#    #+#             */
/*   Updated: 2022/08/15 13:24:58 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
AForm ("Shrubbery Creation", 145, 137), _target( "notarget" ) {
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target) :
AForm ("Shrubbery Creation", 145, 137), _target( target ) {
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &form ) : AForm(form) {
	*this = form;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const
												ShrubberyCreationForm &form) {
	(void)form;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::ofstream	file;
	
	this->beExecuted(executor);
	file.open((_target + ".shrubbery").c_str(),
				std::ofstream::out | std::ofstream::app);
	if (file.good() == false)
		throw FailedToOpenFileException();
	file << "          &&& &&  & &&\n\
      && &\\/&\\|& ()|/ @, &&\n\
      &\\/(/&/&||/& /_/)_&/_&\n\
   &() &\\/&|()|/&\\/ \'%\" & ()\n\
  &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
 ()&_---()&\\&\\|&&-&&--%---()~\n\
     &&     \\|||\n\
             |||\n\
             |||\n\
             |||\n\
       , -=-~  .-^- _\n\n" << std::endl;
	file.close();
}

