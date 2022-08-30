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

void	updownGrade( Bureaucrat &bureaucrat, int vol);

int	main()
{
	std::cout << "\n======Testing=======\n" << std::endl;
	
	try {
		Bureaucrat	bob("Bob", 21);
		updownGrade(bob, 12);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << "\n" << std::endl;
	}
	
	try {
		Bureaucrat	bill("Bill", 0);
		updownGrade(bill, -100);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << "\n" << std::endl;
	}
	
	try {
		Bureaucrat	bella("Bella",  75);
		updownGrade(bella, 100);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << "\n" << std::endl;
	}
	
	try {
		Bureaucrat	bianka("Bianka",  75);
		updownGrade(bianka, -100);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << "\n" << std::endl;
	}
	
	std::cout << "\n======End of tests=======\n" << std::endl;
	return 0;
}

void	updownGrade( Bureaucrat &bureaucrat, int vol) {
	bool	upgrade;
	
	if (vol < 0) {
		vol = -vol;
		upgrade = false;
		std::cout 	<< bureaucrat << ", will decrease by " << vol
					<< " points" << std::endl;
	}
	else {
		upgrade = true;
		std::cout 	<< bureaucrat << ", will increase by " << vol
					<< " points" << std::endl;
	}
	while (vol--) {
		try {
			if (upgrade == true)
				bureaucrat.incrementGrade();
			else
				bureaucrat.decrementGrade();
		}
		catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
			break ;
		}
	}
	std::cout << bureaucrat << ".\n" << std::endl;
}
