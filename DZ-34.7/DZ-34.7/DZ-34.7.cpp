//Подсказка 4 "Для проверки отсутствия у типа виртуального деструктора воспользуетесь трейтом std::has_virtual_destructor"

///Поэтому полный вариант концепта выглядит так :
/*template <class T>
concept ComplexConcept =
!std::has_virtual_destructor<T>::value && requires(T v) {
	{ v.hash() } -> std::convertible_to<long>;
	{ v.toString() } -> std::same_as<std::string>;
};
*/

#include <string>
#include <concepts>

template<typename T>
concept ComplexConcept = requires(T a)
{
	{ std::hash<T>{}(a) } -> std::convertible_to<long>;
	{ a.toString() } -> std::same_as<std::string>;
	!std::has_virtual_destructor<T>::value;
};

int main()
{
	return 0;
}