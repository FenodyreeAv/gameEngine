#pragma once
#include <exception>
#include <string>

namespace myengine
{
	struct Exception : public std::exception //Copied from Rend Exception.h
	{
		Exception(const std::string& message);
		virtual ~Exception() throw();
		virtual const char* what() const throw();

	private:
		std::string message;

	};
}