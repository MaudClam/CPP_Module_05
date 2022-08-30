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
	
	Form 		a("Application for Permission to Permit Permission", 10, 104);
	Bureaucrat	bob("Bob", 11);

	std::cout << a << std::endl;
	std::cout << bob << std::endl;
	bob.signForm(a);

	std::cout << std::endl;
	updownGrade(bob, 10);
	bob.signForm(a);
	std::cout << "\n" << a << std::endl;

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
	std::cout << bureaucrat << "." << std::endl;
}
