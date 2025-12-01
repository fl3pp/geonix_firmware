# fl3pp Firmware for Geonix Rev. 2

This repository contains the code for my custom firmware for the [Chosfox X Masro | Geonix Rev.2](https://chosfox.com/collections/40-keyboard/products/chosfox-x-masro-geonix-rev-2).

## Compiling

Download and extract the [Chosfox distribution](https://drive.google.com/drive/folders/1QNRFeJZBt527T0AZcOdAccgRrbsD4zqa) of the QMK source code, not in the official repository but through Google Drive.

However, note that some functionality doesn't work in this version, including e.g. `_user` functions which this keymaps makes use of. You'll have to fix this on your own if you want to use all features of this repo.

Then, install the `qmk` cli tool, navigate to the directory and setup it up using:

```
qmk setup
```

Next, you'll need to clone this repository into the appropriate subdirectory:

```
cd keyboards/geonix40/geonix40/keymaps
git clone git@github.com:fl3pp/moonlander_firmware.git
```

Finally, setup the Geonix and this keymap using the commands:

```
qmk config compile.keyboard=geonix40/geonix40
qmk config compile.keymap=fl3pp
```

You should then be able to compile the firmware (in 12 threads):

```
qmk compile -j 12
```

## Flashing

Using Windows, it should be possible to use the built-in flasher of the [QMK Toolbox](https://qmk.fm/toolbox) tooling to flash the keympap.

On Mac, there seems to be a driver issue (at least on my device). But it should be possible to manually copy a new version of the firmware over using the `cp` command directly (in this case, the mounted drive was called `/Volumes/NO NAME`)

```
cd "/Volumes/NO NAME" && cp ~/src/qmk/Chosfox_Genoix/geonix40_geonix40_fl3pp.bin FLASH.BIN
```

