#ifndef NATIVE_EXAMPLES_APPLICATION_INHERITANCE_SMTP_MAIL_SENDER_HPP
#define NATIVE_EXAMPLES_APPLICATION_INHERITANCE_SMTP_MAIL_SENDER_HPP

#include "MailSender.hpp"

class SMTPMailSender : public virtual MailSender {
public:
	boolean send() {
		System::out::println(String("From: ") + this->getFrom());
		System::out::println(String("To: ") + this->getTo());
		System::out::println(String("Subject: ") + this->getSubject());
		System::out::println(String("Body: ") + this->getBody());
	}
};


#endif //NATIVE_EXAMPLES_APPLICATION_INHERITANCE_SMTP_MAIL_SENDER_HPP
