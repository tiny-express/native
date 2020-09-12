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

int main(int argc, string *argv) {
	return Application(MainApplication::main, argc, argv);
}
