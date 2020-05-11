#include <iostream>

#include <boost/utility/enable_if.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/at.hpp>
#include <boost/type_traits/is_same.hpp>

///Calculate Fibonacci
template<size_t N>
struct is_fibo0 : boost::mpl::if_c<N != 0 && N != 1, boost::mpl::plus<is_fibo0<N - 1>, is_fibo0<N - 2>>, is_fibo0<N>>::type {};

template <>
struct is_fibo0<1> : boost::mpl::int_<1> {};

template <>
struct is_fibo0<0> : boost::mpl::int_<0> {};

template <size_t N>
struct is_fibo : is_fibo0<N> {};

///OUT vector
template<size_t... I> struct int_vector {};
template<typename IntVector, size_t At> struct push_back;

template<size_t... I, size_t At>
struct push_back<int_vector<I...>, At> {
    using type = int_vector<I..., At>;
};

template<typename IntVector, size_t At> struct at;

template<size_t At, size_t... I, size_t N>
struct at<int_vector<At, I...>, N> : at<int_vector<I...>, N - 1> {};

template<size_t At, size_t... I>
struct at<int_vector<At, I...>, 0> : boost::integral_constant<size_t, At> {};

///search Fibonacci
template<size_t N>
struct fibonaches
{
    using type = typename push_back<typename fibonaches<N - 1>::type, is_fibo<N - 1>::value>::type;
};
template<>
struct fibonaches<0> {
    using type = int_vector<>;
};

int main()
{
    using fib20 = fibonaches<20>::type;
    std::cout << "Fibo is: " << at<fib20, 19>::value << std::endl;
    fib20 fibo;
    fibo = 5;
    return 0;
}
