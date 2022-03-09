# ThreadSanitizer

* ThreadSanitizer is a tool that detects data races. It consists of a compiler instrumentation module and a run-time library.
* Typical slowdown introduced by ThreadSanitizer is about 5x-15x.
* Typical memory overhead introduced by ThreadSanitizer is about 5x-10x

</br>

## Supported Platforms
ThreadSanitizer is supported on the following OS:

* Android aarch64, x86_64
* Darwin arm64, x86_64
* FreeBSD
* Linux aarch64, x86_64, powerpc64, powerpc64le
* NetBSD

</br>

## Usage
* Simply compile and link your program with -fsanitize=thread.
* To get a reasonable performance add `-01` or higher.
* Use `-g` to get file names and line number in the warning messages.

``` c++
//tiny_race.c
#include <pthread.h>
int Global;
void *Thread1(void *x) {
  Global = 42;
  return x;
}
int main() {
  pthread_t t;
  pthread_create(&t, NULL, Thread1, NULL);
  Global = 43;
  pthread_join(t, NULL);
  return Global;
}

//$ clang -fsanitize=thread -g -O1 tiny_race.c
```

</br>

### _has_feature(thread_sanitizer)
* In some cases one may need to execute different code depending on whether ThreadSanitizer is enabled. __has_feature can be used for this purpose.

``` c++
#if defined(__has_feature)
#  if __has_feature(thread_sanitizer)
// code that builds only under ThreadSanitizer
#  endif
#endif
```

## Limitations
* ThreadSanitizer uses more real memory than a native run. At the default settings the memory overhead is 5x plus 1Mb per each thread.
* ThreadSanitizer maps a lot of virtual address space. This means that tools like `unlimit` may not work as usually expected.
* Libc/libstdc++ static linking is not supported.
* Non-position-independent executables are not supported. Therefore, the fsanitize=thread flag will cause Clang to act as though the `-fPIE` flag had been supplied if compiling without `-fPIC`, and as though the `-pie` flag had been supplied if linking an executable.

## Current Status
* ThreadSanitizer is in beta stage.
* It is known to work on large C++ programs using pthreads, but we do not promise anything(yet).
* C++11 threading is supported with llvm libc++.