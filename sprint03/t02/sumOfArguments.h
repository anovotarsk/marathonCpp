#ifndef SUM

template<class A>
A sumOfArguments(A a) {return a;}

template<class T, class ...Ts>
T sumOfArguments(T t, Ts... args) {
    return t + sumOfArguments(args...);
}

#endif
