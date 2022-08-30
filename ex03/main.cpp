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
#include "Intern.hpp"

void	updownGrade( Bureaucrat &bureaucrat, int vol);

int	main()
{
	Bureaucrat	bob("Bob", 150);
	Bureaucrat	bella("Bella", 1);
	Intern		hardwoker;
	AForm 		*form = NULL;
	AForm 		*form_a = NULL;
	AForm 		*form_b = NULL;
	AForm 		*form_c = NULL;

	std::cout << "\n======Intern tries to create forms=======\n" << std::endl;
	try {
		form = hardwoker.makeForm("Shrubbery Creation", "Home Garden");
		if (form != NULL) std::cout << *form << std::endl;
		form_a = hardwoker.makeForm("Presidential Pardon", "Napoleon Bonaparte");
		if (form_a) std::cout << *form_a << std::endl;
		form_b = hardwoker.makeForm("Robotomy Request", "Handmade Sunset");
		if (form_b) std::cout << *form_b << std::endl;
		form_c = hardwoker.makeForm("Application for Permission to Permit Permission", "Handmade Sunset");
		if (form_c) std::cout << *form_c << std::endl;
	}
	catch (std::bad_alloc& ba) {
		std::cerr << "Bad_alloc caught: " << ba.what() << std::endl;
		exit(-1);
	}

	std::cout << "\n======Testing ShrubberyCreationForm=======\n" << std::endl;
	std::cout << bob << std::endl;
	std::cout << bella << std::endl;
	std::cout << std::endl;
	std::cout << *form << std::endl;
	bob.signForm(*form);
	bella.signForm(*form);
	bob.executeForm(*form);
	bella.executeForm(*form);

	std::cout << "\n======Testing PresidentialPardonForm=======\n" << std::endl;
	std::cout << bob << std::endl;
	std::cout << bella << std::endl;
	std::cout << std::endl;
	std::cout << *form_a << std::endl;
	bob.signForm(*form_a);
	bella.signForm(*form_a);
	bob.executeForm(*form_a);
	bella.executeForm(*form_a);
	
	std::cout << "\n======Testing RobotomyRequestForm=======\n" << std::endl;
	std::cout << bob << std::endl;
	std::cout << bella << std::endl;
	std::cout << std::endl;
	std::cout << *form_b << std::endl;
	bob.signForm(*form_b);
	bella.signForm(*form_b);
	bob.executeForm(*form_b);
	for (int i = 0; i < 10; i++)
		bella.executeForm(*form_b);

	delete form;
	delete form_a;
	delete form_b;
	delete form_c;
	
	std::cout << "\n======End of tests=======\n" << std::endl;
	return 0;
}
