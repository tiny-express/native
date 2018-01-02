#ifndef NATIVE_EXAMPLES_APPLICATION_INHERITANCE_MAIL_SENDER_HPP
#define NATIVE_EXAMPLES_APPLICATION_INHERITANCE_MAIL_SENDER_HPP

class MailSender {
private:
	String from;
	String to;
	String subject;
	String body;
public:
	MailSender &setFrom(String from) {
		this->from = from;
		return *this;
	}
	
	String getFrom() {
		return this->from;
	}
	
	MailSender &setTo(String to) {
		this->to = to;
		return *this;
	}
	
	String getTo() {
		return this->to;
	}
	
	MailSender &setSubject(String subject) {
		this->subject = subject;
		return *this;
	}
	
	String getSubject() {
		return this->subject;
	}
	
	MailSender &setBody(String body) {
		this->body = body;
		return *this;
	}
	
	String getBody() {
		return this->body;
	}
public:
	virtual boolean send() = 0;
};


#endif //NATIVE_EXAMPLES_APPLICATION_INHERITANCE_MAIL_SENDER_HPP
