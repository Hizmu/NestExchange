
#include <nestexchange/nestexchange.h>

using NestExchange::Application;

int main()
{
	Application* application = new Application;

	return 	application->exec();
}
