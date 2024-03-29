# QMK_KEYMAP

This is my personal *userspace* for [QMK Firmware](https://github.com/qmk/qmk_firmware).

This repo specifically uses [my fork](https://github.com/vunhatchuong/qmk_firmware/tree/master) of QMK on branch master.

## Compile

Sofle:

```bash
qmk compile -kb sofle -km ronny
```

Ferris Sweep:

```bash
qmk compile -kb ferris/sweep -km ronny
```

Dactyl-Manuform 5x6:

```bash
qmk compile -kb handwired/dactyl_manuform/5x6 -km ronny
```

## External softwares

- [keymapviz](https://github.com/yskoht/keymapviz) or [go-keymapviz](https://github.com/vunhatchuong/go-keymapviz) to generate keymap.c ascii art.
  - [keymapviz.ini] is a modified version of [precondition's](https://github.com/precondition/dactyl-manuform-keymap/blob/main/visualisation/keymapviz/keymapviz.ini).

- [keymap-drawer](https://github.com/caksoylar/keymap-drawer) to generate `SVG` images.

## Code Style

All of the code styles files and folders in this repo are from my qmk_firmware fork master branch, this includes:

- [pre-commit](./.pre-commit-config.yaml)
- [.vscode](./.vscode) folder excludes `c_cpp_properties.json`.
- `c_cpp_properties.json` is from [drashna](https://gist.github.com/drashna/48e2c49ce877be592a1650f91f8473e8).
