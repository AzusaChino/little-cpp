#include <iostream>
#include <typeinfo>

int main() {
	int i = 5, j = 10;
	int* p = &i;

	std::cout << p << " " << *p << std::endl; // ��ַ1 5
	p = &j;
	std::cout << p << " " << *p << std::endl; // ��ַ2 10
	*p = 20;
	std::cout << p << " " << *p << std::endl; // ��ַ2 20
	j = 30;
	std::cout << p << " " << *p << std::endl; // ��ַ2 30
	return 0;
}

void auto_test() {
	int i = 0, & r = i;
	auto a = r;
	const int ci = i, & cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto& g = ci;
	std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;

	a = 1;
	b = 1;
	c = 1;
	// d = 1; d��һ��ָ��
	// e = 1; e��һ��ָ��
	// g = 1; // g��һ���������ã���ֵ�Ƿ�

	std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;
}

void type_info() {
	const int i = 42; // ���ͳ���
	auto j = i; // ����
	const auto& k = i; // ���ͳ���
	auto* p = &i; // ָ�����ͳ�����ָ��
	const auto j2 = i, & k2 = i; // j2������k2����

	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(j).name() << std::endl;
	std::cout << typeid(k).name() << std::endl;
	std::cout << typeid(p).name() << std::endl;
	std::cout << typeid(j2).name() << std::endl;
	std::cout << typeid(k2).name() << std::endl;
}