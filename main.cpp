#include <iostream>
class A {
public:
	virtual std::string getName() = 0;
};
class B : public A {
public:
	B( std::string name) : _name(name) {}
	 std::string getName() override {
  		return _name;
	}
private:
	  std::string _name;
};
int main() {
	A* b = new B("b_name");
	std::cout << b.getName() << std::endl;
}
//1. �������� ������ ���� ��� �� �������������, �� �������� ��� �������� ��������� A* b = �� ����� B  ����
//����������� ��� ��� ������ ������ �, � �� ��� ��������� �� ���� ������ B (b -> getName)
//2. ������ ������ � ���������� �� �������� ��������� (delete b;)
//3. � ������ 8 �� ������������ ���� ������ ��������� � ��������� ,const, ��� �� ����� ����������� ������� ������
//� ��������� ������������ �� ������
//4. � ������� 9 � 4 ����� ��� ������������ const  � ����� �������� ������� ���� ������ �� ������
//5. � ������� ������ �� �������� virtual ~ A(){} - ������ ������