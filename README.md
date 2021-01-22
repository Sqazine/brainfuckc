# BrainFuckC
> C language implementation of a Brainfuck language interpreter.

## Installation

1.Install a ANSC C89 compiler(gcc,clang,msvc etc) \
2.Install CMake(higher or equal 3.10)

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage example

```sh
brainfuckc assets/helloworld.bf
Hello World!
```
If you prefer command line,you can do so
```sh
brainfuckc
>>> ++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>. 
Hello World!

>>>
```


_For more examples and usage, please refer to the [BrainFuck-Wikipedia][wiki]._\
\
Here is a online brainfuck runtime tape visualizer:https://fatiherikli.github.io/brainfuck-visualizer/


## Meta

Sqazine – Sqazine@163.com

Distributed under the Apache 2.0 license. See ``LICENSE`` for more information.

[https://github.com/Sqazine](https://github.com/Sqazine)

## Contributing

1. Fork it (<https://github.com/Sqazine/brainfuckc>)
2. Create your feature branch (`git checkout -b feature/XXX`)
3. Commit your changes (`git commit -am 'Add some XXX'`)
4. Push to the branch (`git push origin feature/XXX`)
5. Create a new Pull Request

<!-- Markdown link & img dfn's -->
[npm-image]: https://img.shields.io/npm/v/datadog-metrics.svg?style=flat-square
[npm-url]: https://npmjs.org/package/datadog-metrics
[npm-downloads]: https://img.shields.io/npm/dm/datadog-metrics.svg?style=flat-square
[travis-image]: https://img.shields.io/travis/dbader/node-datadog-metrics/master.svg?style=flat-square
[travis-url]: https://travis-ci.org/dbader/node-datadog-metrics
[wiki]: https://en.wikipedia.org/wiki/Brainfuck