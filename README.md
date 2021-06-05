# `libG3`

## Outline

- `libOpenSees`
- `libOpenSeesPy`
- `anabel.OpenSeesModel`

## Goals

- Stateless / Thread safe
- High code quality / consistency

## Requirements

- Thread safe
- 0 Compiler warnings
- Consistent newlines [Bilin.cpp]

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


