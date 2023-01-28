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
//1. Основное почему этот код не компилируется, мы пытаемся при создании указателя A* b = на класс B  куче
//реализовать его как обьект класса А, а не как указатель на поле класса B (b -> getName)
//2. Утечка памяти в результате не удаления указателя (delete b;)
//3. в строке 8 не соответсвеие типа данных параметра и аргумента ,const, так же можно осуществить пердачу данных
//в параметры конструктора по ссылке
//4. в строках 9 и 4 также нет модификатора const  и также возможна пердача типа данных по ссылке
//5. в базовом классе не обьявлен virtual ~ A(){} - утечка памяти