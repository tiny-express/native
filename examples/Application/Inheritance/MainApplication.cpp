#include "../../../library.hpp"
#include "SMTPMailSender.hpp"

class MainApplication {
public:
	static void main(Array<String> arguments) {
		SMTPMailSender mailSender;
		mailSender
			.setFrom("root@localhost")
			.setTo("loint@localhost")
			.setSubject("Hello from Food Tiny")
			.setBody("This is a sample email");
		mailSender.send();
	}
};

long int main(long int argc, char **argv) {
	return Application(MainApplication::main, argc, argv);
}
