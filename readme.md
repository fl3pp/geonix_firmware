# fl3pp Firmware for Geonix Rev. 2

This repository contains the code for my custom firmware for the [Chosfox X Masro | Geonix Rev.2](https://chosfox.com/collections/40-keyboard/products/chosfox-x-masro-geonix-rev-2).

## Setup

Download and extract the [Chosfix distribution](https://drive.google.com/drive/folders/1QNRFeJZBt527T0AZcOdAccgRrbsD4zqa) of the QMK source code, not in the official repository but through Google Drive.

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

