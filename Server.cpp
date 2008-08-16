#include <iostream>
#include "Server.hpp"

Server::Server()
	: m_listener( new Listener )
	, m_sessionController( new SessionController )
{
	std::cout << "Dumb FTP server\nIP: " << m_listener->GetIPAddr() << std::endl;

	m_listener->Listen();
}

Server::~Server()
{
	std::cout << "Shutting down server\n";
}

ServerPtr Server::Create()
{
	ServerPtr ret( new Server );
	ret->m_this = ret;

	ret->InitListener();

	return ret;
}

void Server::Tick()
{
	m_listener->Tick();
	m_sessionController->Tick();
}

void Server::IncomingConnection( int sock )
{
	std::cout << "Incoming connection\n";
}

void Server::InitListener()
{
	m_listener->SetServer( m_this );
}
