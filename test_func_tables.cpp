#include <iostream>
#include <stdio.h>

class A {
 public:
  virtual void func_a() = 0;
};

class B {
 public:
  virtual void func_b() = 0;
};

class A_impl : public A {
 public:
  void func_a() final {
    fprintf(stderr, "%s\n", __func__);
  }
};

class B_impl : public B {
 public:
  void func_b() final {
    fprintf(stderr, "%s\n", __func__);
  }
};

class C_impl : public A, public B {
  void func_a() final {
    fprintf(stderr, "c: %s\n", __func__);
  }

  void func_b() final {
    fprintf(stderr, "c: %s\n", __func__);
  }
};

int main() {
  C_impl* c = new C_impl;
  A* a = c;
  B* b = c;

  fprintf(stderr, "%p, %p , %p\n", c, a, b);

  a->func_a();
  b->func_b();

}
