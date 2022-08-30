/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:52:10 by mclam             #+#    #+#             */
/*   Updated: 2022/08/11 12:52:10 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void	updownGrade( Bureaucrat &bureaucrat, int vol);

int	main()
{
	Bureaucrat				bob("Bob", 150);
	Bureaucrat				bella("Bella", 1);
	ShrubberyCreationForm	form("Home Garden");
	PresidentialPardonForm	form_a("Napoleon Bonaparte");
	RobotomyRequestForm		form_b("Handmade Sunset");

	std::cout << "\n======Testing ShrubberyCreationForm=======\n" << std::endl;
	std::cout << bob << std::endl;
	std::cout << bella << std::endl;
	std::cout << std::endl;
	std::cout << form << std::endl;
	bob.signForm(form);
	bella.signForm(form);
	bob.executeForm(form);
	bella.executeForm(form);

	std::cout << "\n======Testing PresidentialPardonForm=======\n" << std::endl;
	std::cout << bob << std::endl;
	std::cout << bella << std::endl;
	std::cout << std::endl;
	std::cout << form_a << std::endl;
	bob.signForm(form_a);
	bella.signForm(form_a);
	bob.executeForm(form_a);
	bella.executeForm(form_a);
	
	std::cout << "\n======Testing RobotomyRequestForm=======\n" << std::endl;
	std::cout << bob << std::endl;
	std::cout << bella << std::endl;
	std::cout << std::endl;
	std::cout << form_b << std::endl;
	bob.signForm(form_b);
	bella.signForm(form_b);
	bob.executeForm(form_b);
	for (int i = 0; i < 10; i++)
		bella.executeForm(form_b);

	std::cout << "\n======End of tests=======\n" << std::endl;
	return 0;
}
