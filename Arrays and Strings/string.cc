#include <cinttypes>
#include <cstring>
#include <iostream>
#include <string>

template <typename T>
void __LOG(const T& t) {
  std::cout << t << std::endl;
}

template <typename H, typename... T>
void __LOG(const H& h, const T&... t) {
  std::cout << h << " ";
  __LOG(t...);
}

#define ALG_DEBUG true

#if ALG_DEBUG

#define LOG(x...) __LOG(x)
#else
#define LOG(x) 0
#endif

template <typename CharT>
class String {
 public:
  using char_t = CharT;

 private:
  char_t* buff_{nullptr};
  size_t size_{};

 public:
  explicit String() {}
  explicit String(const char* str) {
    LOG("Raw string copy constructor called");
    size_t size = strlen(str);
    buff_ = new char[size];
    memcpy(buff_, str, size * sizeof(char_t));
    size_ = size;
  }
  String(const String& str) {
    LOG("Copy constructor called");
    size_ = str.size_;
    buff_ = new char_t[size_];
    memcpy(buff_, str.buff_, str.size_ * sizeof(char_t));
  }
  String(String&& str) {
    LOG("Move constructor called");
    buff_ = str.buff_;
    size_ = str.size_;
    str.buff_ = nullptr;
    str.size_ = 0;
  }
  String& operator=(const String& str) {
    LOG("Copy Assignment called");
    String tmp{str};
    std::swap(tmp, *this);
    return *this;
  };
  String& operator=(String&& str) {
    LOG("Move Assignment Called");
    LOG("DEL MA", reinterpret_cast<void*>(buff_));
    delete[] buff_;
    size_ = str.size_;
    buff_ = str.buff_;
    str.size_ = 0;
    str.buff_ = nullptr;
    return *this;
  };
  ~String() {
    LOG("Destructor called");
    LOG("DES", reinterpret_cast<void*>(buff_));
    delete[] buff_;
    size_ = 0;
  }
  inline char_t& operator[](size_t pos) {
    if (pos >= size_) {
      throw std::out_of_range{"index out of range"};
    }
    return buff_[pos];
  }
  inline const char_t& operator[](size_t pos) const { return (*this)[pos]; }

  constexpr inline size_t size() const noexcept { return size_; }

  inline char_t* begin() noexcept { return buff_; }
  inline char_t* end() noexcept { return buff_ + size_; }

  inline const char_t* cbegin() const noexcept { return buff_; }
  inline const char_t* cend() const noexcept { return buff_ + size_; }

  inline const char_t* rbegin() { return end() - 1; }
  inline const char_t* rend() { return begin() - 1; }
};

template <typename CharT>
std::basic_ostream<CharT>& operator<<(std::basic_ostream<CharT>& stream,
                                      const String<CharT>& str) {
  stream.write(str.cbegin(), str.size());
  return stream;
}

int main(int argc, char** argv) {
  String<char> U{"Hello, World!"};
  U = String<char>{"No Damn Way!"};
  auto Q = String<char>{"uNI"};
  Q = U;
  std::cout << Q << std::endl;
  std::cout << Q[11] << std::endl;
}