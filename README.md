# casual_cosmos

> [!WARNING]
> This project is in early development.
> Expect breaking changes!
>
> A Contributions guide and the Code of Conduct is a WIP, so please
> wait to submit pull requests.

Welcome to Casual Cosmos, a game engine dedicated to custom casual games!

## Specification

The core config format has four main features:

- **Human-readable**, written in [TOML](https://toml.io/en/) with simple
  key and value names. (Currently, the text encoding is UTF-8).
- **Language agnostic**, so this engine can be implemented with
  nearly any programming language! (Board games are also possible!)
- **Extremely customizable**, from levels to UI design!
- **Backwards compatible**, with newer versions **only** adding new options!

These core features mean several things:

- **Easy to port.** You can quickly move around
  your config and use in other implementations!
- **Easy to customize.** Use the builtin editor
  or edit the file directly!
- **Easy to maintain.** No need to worry about old
  or proprietary formats!

See more details in [spec](./spec/README.md).

## Licenses

- [Specification](spec):

  SPDX-License-Identifier: CC0-1.0 ([LICENSE-CC0](LICENSE-CC0) or [https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt](https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt)).

- Main Implementation:

  SPDX-License-Identifier: [Apache-2.0 WITH LLVM-exception](LICENSE-Apache-2.0_WITH_LLVM-exception.md)
