#include <exception>
#include <iostream>
#include <string>

std::string AskTimeServer() {
	//throw std::overflow_error("overall");
	throw std::system_error(std::error_code());
	return "11:22:33";
}

class TimeServer {
public:
	std::string GetCurrentTime() {
		try {
			LastFetchedTime = AskTimeServer();
		}
		catch (const std::system_error) {
		}
		return LastFetchedTime;
	}
private:
	std::string LastFetchedTime = "00:00:00";
};

int main() {
	TimeServer ts;
	try {
		std::cout << ts.GetCurrentTime() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception got: " << e.what() << std::endl;
	}
	int n;
	std::cin >> n;
	return 0;
}