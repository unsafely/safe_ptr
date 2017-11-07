
#ifndef __SAFE_PTR_HEADER_HPP
#define __SAFE_PTR_HEADER_HPP

#include <utility>

namespace safeptr
{

#ifndef CUSTOMIZED_SAFEPTR_ADAPTER
#define CUSTOMIZED_SAFEPTR_ADAPTER

template <class T>
using safe_ptr = T *;

template <class T, class... Args>
safe_ptr<T> make_safe(Args &&... args)
{
    return new T{std::forward<Args>(args)...};
}

template <class T, class... Args>
void destroy_safe(safe_ptr<T> ptr)
{
    delete ptr;
}

#endif // CUSTOMIZED_SAFEPTR_ADAPTER

template <class T, class Func>
constexpr inline void safely(safe_ptr<T> sfptr, Func &&fn) noexcept(noexcept(fn(sfptr)))
{
    if (sfptr != nullptr)
        return fn(sfptr);
}
}

#endif // __SAFE_PTR_HEADER_HPP