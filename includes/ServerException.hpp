#ifndef SERVER_EXCEPTION_HPP
#define SERVER_EXCEPTION_HPP

#include <exception>
#include <string>

class ServerException : public std::exception
{
	private:
		std::string message;
	public:
		ServerException(const std::string& message) : message(message){}
		virtual ~ServerException() throw(){}
		virtual const char* what() const throw() {return message.c_str();}
};

#endif
