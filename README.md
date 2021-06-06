# `libG3`

## Outline

- `libOpenSees`
- `libOpenSeesPy`
- `anabel.OpenSeesModel`

## Goals

- Reduce size of codebase
- Stateless / Thread safe
- High code quality / consistency
- streamline build system
- Facilitate library wrappers which:
  - Provide meaningful error messages
  - Adapt to natural/idomatic symantics in their host language (e.g., argument passing in OpenSeesPy)
  - Allow thread safe interactions with libraries in host language
  - Expose object oriented nature of OpenSees library. Current wrappers essentially flatten-out the architecture of OpenSees into a strict set of commands.


## Requirements

- [ ] [REQ.1] Thread safe
- [ ] Maintain 0 Compiler warnings
- [ ] Consistent line endings (CR/LF) [Bilin.cpp]
- [ ] Impose upper bound for number of lines in codebase 
- [ ] Implement cross-platform build system

## Root Organization

- [`api/`](./api) API definition files
- [`include/`](./include) Project-wide header files
- [`ext/`](./ext) external libraries
- [`lib/`](./lib)
- [`src/`](./src)

## Modules

### `base/domain/Domain.h`

### `base/component/DomainComponent.h`

### `base/node/Node.h`

- `element/OPS_Element`
- `element/XLA_Element`
- `element/FEAP_Element`

- `element/material/`


