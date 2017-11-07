# safe_ptr

This is a simple utility to safely using pointer.

see `test/test_safe_ptr.cpp`.

### Customized safe pointer adapter

`safe_ptr` using plain pointer. You can also customized the adapter by provide
stuff and define `CUSTOMIZED_SAFEPTR_ADAPTER` macro.

```c++

#define CUSTOMIZED_SAFEPTR_ADAPTER

template<class T>
class safe_ptr; // or using safe_ptr = .;

template<class T, class... Args>
safe_ptr<T> make_safe(Args&&...);

template<class T>
void destroy_safe(safe_ptr<T>);

```