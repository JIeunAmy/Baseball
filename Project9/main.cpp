#include <iostream>
#include <stdexcept>

class HateThreeException :public std::exception
{
public:
	HateThreeException(char const* const _Message) : std::exception(_Message) {}
};

void run(int n)
{
	if (n == 33) {
		throw HateThreeException("33333�÷��÷�");
	}
	if (n == 3) {
		throw std::invalid_argument("��..�ȵ�!!!");
	}

}

int main() {
	try {
		run(33);
	}
	catch (const HateThreeException& e) {
		std::cout << "33�� �Ⱦ��\n";
		std::cout << e.what();
	}
	catch (const std::invalid_argument& e) {
		std::cout << "invalid argument\n";
	}
	catch (const std::exception& e) {
		// exception handler
		std::cout << "����ó���ڵ�~\n";
		std::cout << e.what() << "\n";
	}
}