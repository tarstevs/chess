#include "../include/game_loop.h"

#include <iostream>
#include <codecvt>

class pieces {
public:
  pieces() {
    init_();
  }
  char32_t black_king;
private:
  std::string cpp20_codepoint_to_utf8(char32_t cp) // C++20 Standard
  {
    using codecvt_32_8_type = std::codecvt<char32_t, char8_t, std::mbstate_t>;

    struct codecvt_utf8
        : public codecvt_32_8_type {
      explicit codecvt_utf8(std::size_t refs = 0) : codecvt_32_8_type(refs) {}
    };

    char8_t utf8[4];
    char8_t *end_of_utf8;

    char32_t const *from = &cp;

    std::mbstate_t mbs;
    codecvt_utf8 ccv;

    if (ccv.out(mbs, from, from + 1, from, utf8, utf8 + 4, end_of_utf8))
      throw std::runtime_error("bad conversion");

    return {reinterpret_cast<char *>(utf8), reinterpret_cast<char *>(end_of_utf8)};
  }

  void init_() {
    black_king = std::stoul("265A", 0, 16);
//    char32_t u32 = std::stoul(black_king, 0, 16);
//    black_king = cpp20_codepoint_to_utf8(u32);

  }
};