
#include "../include/safe_ptr.hpp"

#include <iostream>

using namespace safeptr;

struct point
{
    int x, y;
};

int main()
{
    auto ptr = make_safe<point>(1, 2);

    int x;
    safely(ptr, [&](auto p) { x = p->x + ptr->y; });

    std::cout << x;

    destroy_safe(ptr);
}