#pragma once
#include <cstdlib>
#include <functional>
#include <string>

struct IntStr {
  int value;
};

class Parser {
public:
  using Callback = std::function<void(int)>;
  using StrCallback = std::function<void(IntStr)>;
  //   Parser(Callback cb)
  //   {
  //     cb_ = cb;
  //   }

  void set_callback(Callback cb)
  {
    cb_ = cb;
  }

  void set_strcallback(StrCallback scb)
  {
    scb_ = scb;
  }

  void parse(const char *msg)
  {
    switch (msg[0]) {
    case 'i': {
      if (scb_) {
        const int n = std::atoi(msg + 1);
        scb_({n});
      }
    } break;
    default: {
      if (cb_) {
        const int n = std::atoi(msg);
        cb_(n);
      }
    } break;
    }
  }

private:
  Callback cb_;
  StrCallback scb_;
};
