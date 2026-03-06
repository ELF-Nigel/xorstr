#include <cassert>
#include <cstddef>
#include <cstring>
#include <cwchar>

#include "xorstr.hpp"

int main()
{
    auto s = xorstr("hello xorstr");
    assert(s.size() == std::strlen("hello xorstr"));

    const auto* plain = s.crypt_get();
    assert(std::strcmp(plain, "hello xorstr") == 0);

    s.crypt();
    const auto* encrypted = s.get();
    assert(std::strcmp(encrypted, "hello xorstr") != 0);

    s.crypt();
    const auto* roundtrip = s.get();
    assert(std::strcmp(roundtrip, "hello xorstr") == 0);

    auto wide = xorstr(L"wide string");
    const auto* wide_plain = wide.crypt_get();
    assert(std::wcscmp(wide_plain, L"wide string") == 0);

    return 0;
}
